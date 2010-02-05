/*
 * This module supports execution of server management commands via designated
 * server scripts binding to non-privileged ports.  The script uses this
 * feature as follows:
 *
 *   1. Create socket and bind it to a random port (e.g. 2308).  While you
 *      have this socket, noone else can originate a connection from this port
 *      (you must NOT specifiy REUSEADDR).
 *
 *   2. Send <DNETMANAGE> message and follow with message containing
 *      port and command to execute ("2308 newlog").  Server saves command
 *      and temporarily changes management port to the alternate port.
 *     
 *   3. Read response from server:
 *       "200 Command accepted, send TRIGGER command to designated port"
 *	 "400 Bad request/protocol error"
 *       "402 unauthorized to do command."
 *       "401 busy, another script has reserved management port"
 *	 "404 unkown script"
 *       "500 Syntax error"
 *
 *   4. if success, connect to server with created socket and send TRIGGER
 *      command.  Read output from server.  If a script reqeust is pending,
 *      server sustitutes saved command for TRIGGER command and responds
 *      as if the command was sent of the manage port connection.  Saved
 *      command is cleared and management port is reset.
 *
 *   5. Send next scriptserver command to server over net_link or close it.
 *      Closing link will reset management port to saved copy.
 *
 *  int http_configure_manage_port (char *item, char *tok1, char *tok2, char *);
 *  int http_script_manage_request ( scb, request, status );
 *  int http_script_manage_clear();
 *  int http_verify_script_request ( );
 */
#include "pthread_1c_np.h"		/* portable pthread() wrappers */
#include <stdio.h>
#include <stdlib.h>
#include "tutil.h"			/* Thread-safe string functions */
#include "tserver_tcp.h"		/* manipulate manange port */
#include "script_manage.h"		/* verify prototype definitions */
int http_log_level;			/* Trace detail level */
int tlog_putlog();
/*
 * Only 1 management request can be pending at a time, declare shared storage
 * synchronization objects used to access it.
 */
int http_manage_port;
char *http_manage_host;
int http_manage_request ( ts_client_ctx ctx, short port, int *shut_time );

struct known_script_entry {
    struct known_script_entry *next;
    char *script;
    int slen, command_count;	/* Length of script string */
    char **command_list;	/* Valid commands */
};

static char pending_request[256];
static pthread_once_t script_manage_setup = PTHREAD_ONCE_INIT;
pthread_mutex_t script_manage_ctl;
static int script_manage_pending = 0;
static int saved_manage_port;
static unsigned int saved_manage_host;
static struct known_script_entry *known_scripts;

/*****************************************************************************/
/* one-time initialization routine to initialize globals.
 */
static void script_manage_init ( )
{
    INITIALIZE_MUTEX(&script_manage_ctl);
    known_scripts = (struct known_script_entry *) 0;
}
/*****************************************************************************/
/* Configure_manage_port is called when during rule file parsing to
 * handle interpretation of MANAGE command.  Errors are output via tlog_putlog.
 */
int http_configure_manage_port (
	char *item,		/*  "PORT"  | "HOST"  | "SCRIPT" */
	char *arg1,		/*  port#     ip-addr   script-name */
	char *arg2,		/*    -          -      command-list */
	char *reserved )	/* Reserved for future use */
{
    char subcode[32];
    /*
     * Parse item code.
     */
    tu_strnzcpy ( subcode, item, sizeof(subcode) - 1 );
    if ( tu_strncmp ( subcode, "PORT", 8 ) == 0 ) {
	http_manage_port = atoi ( arg1 );
    } else if ( tu_strncmp ( subcode, "HOST", 5 ) == 0  ) {
	/*
	 * Verify format of host address string is nnn.nnn.nnn.nnn
	 */
	int status, port;
	unsigned int host;
	port = -1;
	status = http_decode_manage_host ( arg1, &host, &port );
	if ( status && port == -1 ) {
	    http_manage_host = malloc (  tu_strlen(arg1) + 1 );
	    tu_strcpy ( http_manage_host, arg1 );
	} else {
	    tlog_putlog ( 0,"Error decoding MANAGE HOST address '!AZ'!/",
		arg1 );
	    return 0;
	}
    } else if ( tu_strncmp ( subcode, "SCRIPT", 7 ) == 0 ) {
	/*
	 * Make new known script entry.
	 */
	struct known_script_entry *new_kse;
	pthread_once ( &script_manage_setup, script_manage_init );
        LOCK_C_RTL
	new_kse = (struct known_script_entry *) malloc (
		sizeof(struct known_script_entry) );
	new_kse->slen = tu_strlen(arg1);
	new_kse->script = malloc ( new_kse->slen + 1 );
	UNLOCK_C_RTL

#ifdef VMS
	tu_strupcase ( new_kse->script, arg1 );
#else
	tu_strcpy ( new_kse->script, arg1 );
#endif
	new_kse->command_count = 0;
	new_kse->command_list = (char **) 0;
	/*
	 * Count number of commands.
	 */
	if ( arg2 ) if ( arg2[0] ) {
	    int i, j, commas;
	    char *buffer;
	    /*
	     * Copy string to buffer that will be split into multiple strings.
	     */
	    LOCK_C_RTL
	    buffer = malloc ( tu_strlen(arg2) + 1 );
	    UNLOCK_C_RTL
	    tu_strupcase ( buffer, arg2 );
	    /*
	     * Count the number of commands.
	     */
	    new_kse->command_count = 1;
	    for (i=0; arg2[i]; i++) 
		if (arg2[i] == ',') new_kse->command_count++;
	    new_kse->command_list = (char **) malloc ( (sizeof (char *)) * 
			new_kse->command_count );
	    new_kse->command_list[0] = buffer;
	    for ( i = j = 0; buffer[i]; i++ ) if ( buffer[i] == ',' ) {
		j++;
		buffer[i] = '\0';
		new_kse->command_list[j] = &buffer[i+1];
	    }
	}
	/*
	 * Add new entry to list.
	 */
	pthread_mutex_lock ( &script_manage_ctl );
	new_kse->next = known_scripts;
	known_scripts = new_kse;
	pthread_mutex_unlock ( &script_manage_ctl );

	tlog_putlog(5,"Defined known script '!AZ', command count: !SL!/",
		new_kse->script, new_kse->command_count );
    } else {
	tlog_putlog(0,"unknown manage option: '!AZ'!/", subcode );
	return 0;
    }
    return 1;
}

/*****************************************************************************/
/* Manage_request is called during scriptserver protocol processing as part
 * of <DNETMANAGE> dispatching.  Return value is 1 for success (200) and
 * 0 for failure.
 */
int http_script_manage_request ( 
	char *script, 		/* name of script making request */
       char *request, 		/* Command to execute: [host:]port command */
       char *response,		/* request status line (returned) */
	int rspsize,		/* Size of response array */
	int *rsplen )		/* Size of returned line */
{
    int status, tmp_port, i, j;
    unsigned int tmp_host;
    char *p, *command, *cmpstr, compare_buffer[256];
    struct known_script_entry *kse;

    pthread_once ( &script_manage_setup, script_manage_init );
    /*
     * Parse out script-name portion.
     */
    tu_strnzcpy ( compare_buffer, script, sizeof(compare_buffer) - 1 );
    p = tu_strstr ( compare_buffer, "*" );
    if ( p ) *p = '\0';
#ifdef VMS
    tu_strupcase ( compare_buffer, compare_buffer );
#endif
    cmpstr = compare_buffer;
    pthread_mutex_lock ( &script_manage_ctl );
    /*
     * Search known script list for match.
     */
    for ( kse = known_scripts; kse; kse = kse->next ) {
	if ( tu_strncmp ( cmpstr, kse->script, kse->slen ) == 0 ) break;
    }
    if ( kse ) {
	/*
	 * Check if another script request pending and save current state if not.
	 */
	if ( http_log_level > 4 ) tlog_putlog ( 5,
		"Script manage request: '!AZ'!/", request );
	if ( script_manage_pending ) {
	    pthread_mutex_unlock ( &script_manage_ctl );
	    tu_strcpy ( response, "402 command not permitted" );
	    *rsplen = tu_strlen ( response );
	    return 0;
	}
	script_manage_pending = 1;
	http_decode_manage_host ( http_manage_host, &saved_manage_host,
		&saved_manage_port );
	saved_manage_port = http_manage_port;
	tu_strcpy ( pending_request, "HELP" );
	pthread_mutex_unlock ( &script_manage_ctl );
	/*
	 * Parse request into host, port, and command.
	 */
	command = tu_strstr ( request, " " );
	if ( !command ) {
	    http_clear_script_manage();
	    tu_strcpy ( response, "400 Syntax error in request" );
	    *rsplen = tu_strlen ( response );
	    return 0;
	}
	command++;
	tmp_port = http_manage_port;
	tmp_host = 0x0100007f;
	status = http_decode_manage_host ( request, &tmp_host, &tmp_port );
	if ( !status ) {
	    http_clear_script_manage();
	    tu_strcpy ( response, "400 Syntax error in request" );
	    *rsplen = tu_strlen ( response );
	    return 0;
	}
	/*
	 * Validate against command list (if command list defined)
	 */
	if ( kse->command_count > 0 ) {
	    http_clear_script_manage();
	    tu_strcpy ( response, "403 illegal command" );
	    *rsplen = tu_strlen ( response );
	    return 0;
	}
	/*
	 * Make temporary assignment of manage host.
	 */
	pthread_mutex_lock ( &script_manage_ctl );
	tu_strnzcpy ( pending_request, command, sizeof(pending_request)-1 );
	tu_strupcase ( pending_request, pending_request );
	pthread_mutex_unlock ( &script_manage_ctl );

	ts_set_manage_port ( tmp_port, tmp_host, http_manage_request );

	tu_strnzcpy ( response, "200 manage request armed, send TRIGGER",
		rspsize-1 );
	*rsplen = tu_strlen ( response );
	
	return 1;
    }
    else pthread_mutex_unlock ( &script_manage_ctl );

    tu_strcpy ( response, "404 request script not known" );
    *rsplen = tu_strlen ( response );

    return 0;
}

/*****************************************************************************/
/* Reset the pending information.
 */
int http_clear_script_manage()
{
    pthread_mutex_lock ( &script_manage_ctl );
    if ( script_manage_pending ) {
	script_manage_pending = 0;
	http_manage_port = saved_manage_port;
	if ( http_log_level > 4 ) tlog_putlog ( 5,
	"Clearing script management command, new is: !SL!/", http_manage_port );
	ts_set_manage_port ( http_manage_port, saved_manage_host,
		http_manage_request );
	pthread_mutex_unlock ( &script_manage_ctl );
	return 1;
    }
    pthread_mutex_unlock ( &script_manage_ctl );
    return 0;
}
/*****************************************************************************/
/* verify_script_request checks if script management pending and that
 * remote port is temporary port and that request is TRIGGER.  Rewwrite.
 */
int http_verify_script_request (
	void *ctx,			/* TCP/IP context */
	char *request,			/* Buffer containing manage command */
	int reqsize,			/* size of request buffer (max length)*/
	int *length )
{
    int local_port, remote_port;
    unsigned int remote_addr[32];

    pthread_once ( &script_manage_setup, script_manage_init );
    /*
     * Check for active script.
     */
    pthread_mutex_lock ( &script_manage_ctl );
    if ( script_manage_pending == 0 ) {
	/* No pending script, return request as is */
	pthread_mutex_unlock ( &script_manage_ctl );
	return 1;	
    }
    pthread_mutex_unlock ( &script_manage_ctl );
    /*
     * Get remote port and compare with current and saved ports.
     * If matches saved info, requesting client connected before we switched
     * manage port in tserver_tcp module so allow request (leave script
     * request pending).
     */
    ts_tcp_info ( &local_port, &remote_port, remote_addr );
    if ( (remote_port == saved_manage_port) &&
	(remote_addr[0] == saved_manage_host) ) return 1;
     /*
      * rewrite request string and clear pending request.
      */
    tu_strnzcpy ( request, pending_request, reqsize-1 );
    http_clear_script_manage ( );

    *length = tu_strlen ( request );
    return 1;
}
/*****************************************************************************/
/* Decode string of form [nnn.nnn.nnn.nnn:]ppp into IP address and port.
 */
int http_decode_manage_host ( char *hoststr, unsigned int *ip_addr, int *port)
{
    int i, j;
    unsigned int octet[5];
    /*
     * Interpret string as list of integers separated by dots and colons,
     * Value after colon goes into element zero.
     */
    for ( i = 0; i < 5; i++ ) octet[i] = 0;
    j = 1;
    for ( i = 0; hoststr[i] && (hoststr[i] != ' '); i++ ) {
	if ( (hoststr[i] >= '0') && (hoststr[i] <= '9') ) {
	    octet[j] = (octet[j]*10) + (hoststr[i]-'0');
	    if ( octet[j] > 65768 ) return 0;
	} else if ( hoststr[i] == '.' ) {
	    j++;
	    if ( (j == 1) || (j > 4) ) return 0;	/* syntax error */
	} else if ( hoststr[i] == ':' ) {
	    if ( j != 4 ) return 0;	/* syntax error */
	    j = 0;
	}
    }
    /*
     * Return port if a colon present (j=0) or not dots present (j=1).
     * Return host address if dots present in string (j!=1).
     */
    if ( j < 2 ) *port = octet[j];
    if  ( j != 1 ) 
	*ip_addr = octet[1] | (octet[2]<<8) | (octet[3]<<16) | (octet[4]<<24);
    return 1;
}
