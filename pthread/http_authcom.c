/*
 * This module handles level 2 access protection for the HTTP server.  The
 * level 2 protection checks are actually done by a sub-process that this
 * module creates and communicates with via a mailbox.
 *
 * http_start_authenticator ( char *image );
 * int http_authenicate ( access_info acc, char *ident, tu_test rsphdr )
 *
 * Revised: 1-JUL-1994		Hack username into log line.
 * Revised: 30-JUl-1994		Fixup problem with username in log line.
 * Revised: 26-AUG-1994		Missing unlock in rundown routine.
 * Revised: 25-SEP-1994		Add tserver_tcp.h header file.
 * Revised:  4-FEB-1995		Add spawn flags for increased security (from 
 *				Chuck Lane, lane@duphy4.physics.drexel.edu).
 * Revised:  8-FEB-1995		Log spawn errors.
 * Revised: 22-JUN-1995		Support pipe-based IPC (unix version).
 * Revised: 15-MAR-1995		cmbdef fix
 * Revised: 22-NOV-1996		Change http_authenticate interface and
 *				include URI: header line in data to
 *				authenticator.
 * Revised: 30-JAN-1997		Have start_authenticator set subprocess output
 *				(sys$output) to value of environment variable
 *				authenticator_log if present.
 * Revised: 18-FEB-1997		Check for JPI$_MULTITHREAD (VMS V7.1).
 */
#include <stdio.h>
#include "ctype_np.h"
#ifdef VMS
#include <unixlib.h>
#include <descrip.h>
#include <iodef.h>
#ifndef __DECC
#ifndef CMB$M_READONLY
#define CMB$M_READONLY 1
#define CMB$M_WRITEONLY 2
#endif
#else
#include <cmbdef.h>
#endif
#include <ssdef.h>
/* The ssdef.h is out of date, hard code new values */
#ifndef SS$_NOREADER
#define SS$_NOREADER 0x024c4
#define SS$_NOWRITER 0x024cc
#endif
#include <clidef.h>
#ifndef CLI$M_TRUSTED
/* clidef.h is out of date, hard code new values */
#define CLI$M_TRUSTED 0		/* 0x0040 */
#define CLI$M_AUTHPRIV 0	/* 0x0080 */
#endif
#ifndef IO$M_READERCHECK
/*
 * Out-of-date iodef.h, hard code the values for new mailbox driver options.
 */
#define IO$M_READERCHECK 0x0100
#define IO$M_WRITERCHECK 0x0200
#endif
#else
/* 
 * OSF/1-specific includes. 
 */
#include <errno.h>
#ifdef __DECC			/* really is VMS, checking out /undef=VMS */
#include <unixio.h>
#include <processes.h>
#define fork vfork
#else
#endif
#endif

#include <string.h>

#include "pthread_1c_np.h"
#include "tserver_tcp.h"
#include "session.h"
#include "http_header.h"

#define REQUEST_MAILBOX "HTTP_AUTHCOM_RSP"
#define RESPONSE_MAILBOX "HTTP_AUTHCOM_REQ"
int http_log_level;
int tlog_putlog ( int level, char *ctlstr, ... );
static int ef;
static int req_mbx, rsp_mbx;
static long auth_pid = 0;			/* authenticator's process ID */

#include "authcom.h"
static struct msg1 req_msg;		/* Request mailbox messages */

static struct msg2 rsp_msg;             /* response mailbox messages. */

static struct {
    unsigned short status, count;	/* status and bytes read/written */
    long pid;				/* PID of sending/receiving process */
} iosb;

static pthread_mutex_t auth_io;		/* Mutex for I/O condition */
static pthread_cond_t auth_avail;	/* Signals that authenticator free */
static pthread_cond_t auth_io_done;	/* Signals that mbx I/O completed */
static pthread_key_t auth_key;
static pthread_t auth_owner;		/* Thread I/D of currnent owner */
static int auth_busy;			/* If true, authenticator in use */
static int auth_waiting;		/* Flags if thread is blocked */
#ifdef VMS
/******************************************************************************/
/*
 * The following two routines are used to enable a thread to perform I/O 
 * without blocking the execution of other threads.  The thread must do
 * the following:
 *	1. Acquire auth_io mutex.
 *	2  call SYS$QIO function specifying auth_synch_ast as the
 *	   AST argument and address of auth_io_done the as the AST parameter.
 *	3. call auth_synch_io to get status and release the mutex.
 */
static int auth_synch_ast ( pthread_cond_t *condition )
{
    int status;
    /*
     * Signal any waiting threads.
     */
    status = pthread_cond_signal_int_np ( condition );
    return status;
}

static int auth_synch_io ( int status, pthread_cond_t *condition )
{
    /*
     * Make sure operation is pending (success status).
     */
    if ( (status&1) == 1 ) {
	/*
	 * Loop until predicaate (iosb.status) is non-zero.
	 */
	do {
	    pthread_cond_wait ( condition, &auth_io );
	} while ( iosb.status == 0 );
	status = iosb.status;
    }
    /*
     * Condition satisfied, unlock mutex.
     */
    pthread_mutex_unlock ( &auth_io );
    return status;
}
/*************************************************************************/
#ifdef PTHREAD_USE_D4
/*
 * Draft 4 library lacks upcalls so always synchronize via ASTs signalling
 * a condition variable.
 */
int SYS$QIO();
#define QIO_AND_WAIT(cond,chan,func,iosb,p1,p2,p3,p4,p5,p6) \
     (pthread_mutex_lock(&auth_io),\
      auth_synch_io(SYS$QIO(0,chan,func,iosb,pthread_cond_signal_int_np,cond,\
		p1,p2,p3,p4,p5,p6),cond))
#else
/*
 * With standard V7 library, select synchronization method based upon whether
 * kernel thread upcalls enabled.
 */
int SYS$QIOW(), SYS$QIO(), os_kernel_threads();
static int kernel_threads = 0;
#ifdef __ALPHA
#define ENF 128
#else
#define ENF 12
#endif
#define QIO_AND_WAIT(cond,chan,func,iosb,p1,p2,p3,p4,p5,p6) \
 (kernel_threads ? SYS$QIOW(10,chan,func,iosb,0,0,p1,p2,p3,p4,p5,p6) : \
     (pthread_mutex_lock(&auth_io),\
     auth_synch_io(SYS$QIO(ENF,chan,func,iosb,pthread_cond_signal_int_np,\
		cond,p1,p2,p3,p4,p5,p6),cond)) )
#endif
#endif
/*************************************************************************/
/* Allocate access to the authenticator for this thread, waiting if another
 * thread using it.
 */
static void allocate_authenticator()
{
    /*
     * Serialize access to this routine through use of auth_avail condition.
     */
    pthread_mutex_lock ( &auth_io );
    if ( auth_busy ) pthread_setspecific ( auth_key, (void *) 2 );
    while ( auth_busy ) {
	auth_waiting++;
	pthread_cond_wait ( &auth_avail, &auth_io );
	auth_waiting--;
    }
    auth_busy = 1;
    pthread_setspecific ( auth_key, (void *) 1 );	/* mark that we own it */
    pthread_mutex_unlock ( &auth_io );
}
/***************************************************************************/
/* Deallocate the authenticator, signalling any other threads waiting.
 * This routine assumes that the calling thread owns the authenticator.
 */
void deallocate_authenticator()
{
    pthread_mutex_lock ( &auth_io );
    auth_busy = 0;
    pthread_setspecific ( auth_key, (void *) 0 );	/* no longer own authen. */
    if ( auth_waiting > 0 ) pthread_cond_signal ( &auth_avail );
    pthread_mutex_unlock ( &auth_io );
}
/***************************************************************************/
/* Cleanup any active contexts associated with a thread.  Active_flag is
 * the current auth_key context value:
 *     0 - Don't own authenticator, not waiting.
 *     1 - Currently 'own' authenticator.
 *     2 - Currently waiting for access to authenticator.
 */
static void auth_rundown ( void *active_flag_arg )
{
    int active_flag;
    active_flag = (int) active_flag_arg;	/* cast into int */
    if ( active_flag == 0 ) return;	/* not accessing authenticator */

    if ( auth_busy  && (active_flag == 1) ) {
	/*
	 * We are the active thread.  Kill any pending I/O.
	 */
#ifdef VMS
	int SYS$CANCEL();
	SYS$CANCEL ( rsp_mbx );
	SYS$CANCEL ( req_mbx );
#else
#endif
	pthread_mutex_lock ( &auth_io );
	if ( auth_waiting ) pthread_cond_signal ( &auth_avail );
	auth_busy = 0;
	pthread_mutex_unlock ( &auth_io );

    } else if ( active_flag == 2 ) {
	/*
	 * We were waiting to allocate it, reduce reference count.
	 */
	pthread_mutex_lock ( &auth_io );
	auth_waiting--;
	pthread_mutex_unlock ( &auth_io );
    }
}

/***************************************************************************/
static int send_request ( int length )
{
#ifdef VMS
    int status;
    /*
     * write message, retry until the authenticator is the reader.
     * If auth_pid is zero, loop will not execute and return NOREADER status.
     */
    status = SS$_NOREADER;
    for ( iosb.pid = 0; auth_pid != iosb.pid; ) {
	status = QIO_AND_WAIT ( &auth_io_done, req_mbx, 
		IO$_WRITEVBLK|IO$M_READERCHECK,	&iosb,
		&req_msg, length, 0, 0, 0, 0 );
	if ( (status&1) == 0 ) {
	    if ( status == SS$_NOREADER ) auth_pid = 0;
	    break;
	}
    }
    return status;
#else
    /*
     * Write message to pipe, begin with message length in host data order.
     * Writing to pipes is atomic as long as length is less that PIPE_BUF
     */
    int result;
    result = write ( req_mbx, &length, sizeof(length) );
    if ( result == sizeof(length) ){
	 result = write ( req_mbx, &req_msg, length );
	 return (result == length) ? 1 : 0;
    }
    else return 0;
#endif
}
static int receive_response ( int *length )
{
#ifdef VMS
    int status;
    /*
     * Read message, ignore any that aren't from the authenticator.
     */
    status = SS$_NOWRITER;
    for ( iosb.pid = 0; auth_pid != iosb.pid; ) {
	status = QIO_AND_WAIT ( &auth_io_done, rsp_mbx, 
		IO$_READVBLK|IO$M_WRITERCHECK,
		&iosb, &rsp_msg, sizeof(rsp_msg), 0, 0, 0, 0 );
	if ( (status&1) == 0 ) {
	    if ( status == SS$_NOWRITER ) auth_pid = 0;
	    break;
	}
    }
    *length = iosb.count;
    return status;
#else
    /*
     * Read from response pipe into structure.
     */
    int result, i;
    for ( i = 0; i < sizeof(*length); i+=result ) {
	result = read ( rsp_mbx, ((char *)length)+i, sizeof(length)-i );
	if ( result <= 0 ) return 0;
    }
    for ( i = 0; i < *length; i+=result ) {
        result = read ( rsp_mbx, &rsp_msg, *length );
	if ( result <= 0 ) return 0;
    }
    return 1;
#endif
}
/***************************************************************************/
/*
 * Authenticator startp initializes the communcation layer.  This must
 * be done prior to creating any threads.
 */
int http_start_authenticator ( char *image )
{
#ifdef VMS
    int status, spawn_flags, LIB$SPAWN();
    int LIB$GET_EF(), SYS$CREMBX(), SYS$SYNCH(),SYS$CANCEL();
    char command[256], *auth_log, authenticator_log[256];
    $DESCRIPTOR(req_mbx_name,REQUEST_MAILBOX);
    $DESCRIPTOR(rsp_mbx_name,RESPONSE_MAILBOX);
    $DESCRIPTOR(cmd, "");
    $DESCRIPTOR(sys$output_dx,"");
    /*
     * Determine synch mode for QIO_AND_WAIT if using V7 DECThreads.
     */
#ifndef PTHREAD_USE_D4
    kernel_threads = os_kernel_threads();
#endif
    /*
     * First create mailboxes.  Make them directional so we can detect the
     * authenticator dying on us.
     */
    req_mbx = rsp_mbx = ef = 0;
    LIB$GET_EF ( &ef );
    status = SYS$CREMBX ( 0, &req_mbx, sizeof(req_msg), sizeof(req_msg),
		MBX_PROT, 0, &req_mbx_name, CMB$M_WRITEONLY );
    if ( (status&1) == 0 ) return status;
    status = SYS$CREMBX ( 0, &rsp_mbx, sizeof(rsp_msg), sizeof(req_msg),
		MBX_PROT, 0, &rsp_mbx_name, CMB$M_READONLY );
    if ( (status&1) == 0 ) return status;
    /*                        
     * Start asynch read on response mailbox.
     */
    status = SYS$QIO ( ef, rsp_mbx, IO$_READVBLK, &iosb, 0, 0,
		&rsp_msg, sizeof(rsp_msg), 0, 0, 0, 0 );
    if ( (status&1) == 0 ) return status;
    /*
     * check for authenticator_log environment variable and reset sys$output.
     */
    auth_log = getenv ( "AUTHENTICATOR_LOG" );
    if ( auth_log ) {
	strncpy ( authenticator_log, auth_log, 255 );
	authenticator_log[255] = '\0';
	sys$output_dx.dsc$w_length = strlen ( authenticator_log );
	sys$output_dx.dsc$a_pointer = authenticator_log;
	tlog_putlog(0,"Authenticator log: '!AS'!/", &sys$output_dx,
		sys$output_dx.dsc$w_length );
    }
    /*
     * Spawn image, passing mailbox names as command line arguments.  Save PID
     * of the sub-process to validate against incoming messages.
     */
    sprintf ( command, "mcr %s %s %s", image, 
		REQUEST_MAILBOX, RESPONSE_MAILBOX);
    cmd.dsc$w_length = strlen ( command );
    cmd.dsc$a_pointer = command;

    spawn_flags = CLI$M_NOWAIT | CLI$M_TRUSTED | CLI$M_AUTHPRIV;
    status = LIB$SPAWN ( &cmd, 0, sys$output_dx.dsc$w_length == 0 ? 0 :
		&sys$output_dx, &spawn_flags, 0, &auth_pid, 0, 0,
		SYS$CANCEL, rsp_mbx );
#else
    int status, pdesc[2], length;
    /*
     * Create pipe.
     */
    if ( 0 != pipe ( pdesc ) ) {
    }
    auth_pid = fork();
    if ( auth_pid < 0 ) {
	/* Error in fork */
	auth_pid = 0;
	status = 0;
    } else if ( auth_pid == 0 ) {
	/* We are child, execl */
	char arg1[16], arg2[16];
	sprintf ( arg1, "%d", pdesc[1] );	/* request mailbox */
	sprintf ( arg2, "%d", pdesc[0] );	/* response mailbox */
	execl ( image, image, arg1, arg2, (char *) 0 );
	tlog_putlog(0,"Execl error: %d\n", errno );
	status = 0;
    } else {
	/*
	 * We are parent, move descriptors into global variables.
	 */
	rsp_mbx = pdesc[0];
	req_mbx = pdesc[1];
	status = 1;
    }
#endif
    if ( (status&1) == 0 ) {
	tlog_putlog (0, "Error spawning authenticator, status: 0x!XL!/", status);
	return status;
    }
    tlog_putlog ( 0, "Created authenticator process, PID = !8XL!/", auth_pid );
    /*
     *  After initializing, the authenticator writes a status line to the 
     *  mailbox.  Wait on this message to arrive, which lets us know the
     *  authenticator started.  The spawn specified SYS$CANCEL as the
     *  completion AST so that if the image dies the read will fail with
     *  an abort status.
     */
#ifdef VMS
    status = SYS$SYNCH ( ef, &iosb );
    if ( (status&1) == 1 ) status = iosb.status;
#else
    status = receive_response (&length);
#endif
    if ( (status&1) == 0 ) {
	tlog_putlog ( 0, "Error, authenticator did not initialize!/" );
	auth_pid = 0;
	return status;
    }
    tlog_putlog ( 0, "!AF!/", rsp_msg.log_len, &rsp_msg.data[rsp_msg.sts_len] );
    /*
     * Create DECthread objects used to serialize access to the authenticator.
     */
    auth_busy = 0;
    auth_waiting = 0;
    status = INITIALIZE_MUTEX ( &auth_io );
    status = CREATE_KEY ( &auth_key, auth_rundown );
    status = INITIALIZE_CONDITION ( &auth_avail );
    status = INITIALIZE_CONDITION ( &auth_io_done );

    return 1;
}

/******************************************************************************/
/* Main routine for checking authentication.
 */
int http_authenticate ( session_ctx scb, char *ident )
{
    access_info acc;
    string *request; tu_text rsphdr;
    int status, i, http_add_response(), length, flag_skip;

    acc = scb->acc;
    request = scb->request;
    rsphdr = scb->rsphdr;
    /*
     * Check that authenticator is running.
     */
    if ( auth_pid == 0 ) {
	/*
	 * No authenticator, put error response in response header and
	 * return fail status.
	 */
        status = http_add_response ( rsphdr, "500 Internal error", 1 );
	return 0;
    }
    /*
     * Serialize access to this routine through use of auth_avail condition.
     */
    allocate_authenticator();
    /*
     * Build message.  Trim leading '+' from protection file name.
     */
    req_msg.code = 1;
    ts_tcp_info ( &req_msg.local_port, &req_msg.remote_port,
	(unsigned int *) req_msg.remote_addr );
    length = request[0].l;
    tu_strnzcpy ( req_msg.method, request[0].s, length > 7 ? 7 : length );
    flag_skip = (*acc->prot_file == '+') ? 1 : 0;
    req_msg.setup_len = tu_strlen ( &acc->prot_file[flag_skip] );
    if ( req_msg.setup_len > 255 ) req_msg.setup_len = 255;
    req_msg.ident_len = tu_strlen ( ident );
    if ( req_msg.ident_len > 256 ) req_msg.ident_len = 256;
    tu_strncpy ( req_msg.data, &acc->prot_file[flag_skip], req_msg.setup_len );
    tu_strncpy ( &req_msg.data[req_msg.setup_len], ident, req_msg.ident_len );
    length = req_msg.setup_len + req_msg.ident_len;
    /*
     * Generate fake URI: header line from request[2]
     */
    if ( length + 6 + request[1].l < sizeof(req_msg.data) ) {
	tu_strcpy ( &req_msg.data[length], "URI: " );
	length += 5;
	tu_strnzcpy ( &req_msg.data[length], request[1].s, request[1].l );
	length += request[1].l;
	req_msg.data[length++] = '\n';
    }
    /*
     * Scan request headers for authorization lines and append to request.
     * Errors in extract header routine (count<0) will be ignored.
     */
    if ( length + 30 < sizeof(req_msg.data) ) {
	int count, alength;
        count = http_extract_header_lines ( http_std_atoms.authorization,
	    scb, &req_msg.data[length], sizeof(req_msg.data)-length, &alength );
	if ( count > 0 ) length += alength;
    }
    /*
     * send message to authenticator.
     */
    length = length + REQ_HDR_SIZE;
    status = send_request(length);
    if ( (status&1) == 0 ) {
        status = http_add_response ( rsphdr, "500 Internal error", 1 );
	status = 0;
    } else {
        /*
         * read response.
         */
        status = receive_response ( &length );
        if ( (status&1) == 0 ) {
            status = http_add_response ( rsphdr, "500 Internal error", 1 );
	    status = 0;
        }
	else {
	    /*
	     * Set return status from message.  If access failed, place
	     * status line in response header.
	     */
	    status = rsp_msg.status;
	    if ( !status ) {
		/* Strip final newline from status line. */
		if ( rsp_msg.data[rsp_msg.sts_len-1] == '\n' )
		    rsp_msg.data[rsp_msg.sts_len-1] = '\0';
		if ( rsp_msg.data[rsp_msg.sts_len-2] == '\r' )
		    rsp_msg.data[rsp_msg.sts_len-2] = '\0';
		http_add_response ( rsphdr, rsp_msg.data, 1 );
	    }
	    /*
	     * Hack to get username from authenticator.  If log line
	     * begins with "[string]", then string is username to insert
	     * in acc structure.
	     */
	    if ( (rsp_msg.log_len > 2) && 
		 (rsp_msg.data[rsp_msg.sts_len] == '[') ) {
		char c;
		/*
		 * Copy porition within brackets to acc.
		 */
		rsp_msg.sts_len++;	/* skip '[' */
		rsp_msg.log_len--;
		for ( i = 0; rsp_msg.log_len > 0 &&
			i < sizeof(acc->rem_user)-1; i++ ) {
		    --rsp_msg.log_len;
		    c = rsp_msg.data[rsp_msg.sts_len++];
		    if ( (c == '\0') || (c == ']') ) break;
		    acc->user[i] = c;
		}
		acc->user[i] = '\0';	/* terminate string */
	    }
	    /*
	     * Add log line if present.
	     */
	    if ( (rsp_msg.log_len > 0) && (http_log_level > 1) ) 
		tlog_putlog ( 1, "!AF!/",
		 rsp_msg.log_len, &rsp_msg.data[rsp_msg.sts_len] );
	}
    }
    /*
     * Free access to the channel.
     */
    deallocate_authenticator();

    return status;
}
/******************************************************************************/
/* Routine for requesting an auxilly network service (code 2) from the
 * authenticator.
 */
int http_auth_netsrv ( char *subfunc,		/* Subfunc: REMHOST, REMUSER */
	int tag,
	char *arg, int arglen,
	char *response,
	int rsplen )
{
    int status, i, http_add_response(), length, flag_skip;
    /*
     * Check that authenticator is running.
     */
    if ( auth_pid == 0 ) {
	/*
	 * No authenticator, put error response in response header and
	 * return fail status.
	 */
	return 0;
    }
    /*
     * Serialize access to this routine through use of auth_avail condition.
     */
    allocate_authenticator();
    /*
     * Build message.  Trim leading '+' from protection file name.
     */
    req_msg.code = 2;		/* Network service */
    ts_tcp_info ( &req_msg.local_port, &req_msg.remote_port,
	(unsigned int *) req_msg.remote_addr );
    tu_strnzcpy ( req_msg.method, subfunc, 7 );
    req_msg.setup_len = tag;
    req_msg.ident_len = arglen;
    if ( arglen > sizeof(req_msg.data) ) 
	req_msg.ident_len = sizeof(req_msg.data);
    tu_strncpy ( req_msg.data, arg, req_msg.ident_len );
    /*
     * send message to authenticator.
     */
    length = req_msg.ident_len + REQ_HDR_SIZE;
    status = send_request(length);
    if ( (status&1) == 1 ) {
        /*
         * read response.
         */
        status = receive_response ( &length );
        if ( (status&1) == 1 ) {
	    /*
	     * Set return status from message.  If access failed, place
	     * status line in response header.
	     */
	    status = rsp_msg.status;
	    if ( !status ) {
		/* Copy data to user arg */
		length = rsplen-1;
		if ( length > rsp_msg.sts_len ) length = rsp_msg.sts_len;
		tu_strnzcpy ( response, rsp_msg.data,length );
	    }
	    /*
	     * Add log line if present.
	     */
	    if ( (rsp_msg.log_len > 0) && (http_log_level > 1) ) 
		tlog_putlog ( 1, "!AF!/",
		 rsp_msg.log_len, &rsp_msg.data[rsp_msg.sts_len] );
	}
    }
    /*
     * Free access to the channel.
     */
    deallocate_authenticator();

    return status;
}
