/*
 * This module supports global counters for tracking server usage.
 *
 *   int http_open_active_counter 
 *	( int ndx, int port, unsigned char *address, int *lock_state );
 *   int http_set_active_counter 
 *	( int ndx, char *method, char *request, int *lock_state );
 *   int http_close_active_counter ( int ndx );
 *   int http_define_host_counter ( char *class_name, char *host_mask );
 *   int http_increment_host_counters ( unsigned char *address, int *lk_state );
 *   int http_increment_keepalive_counter 
 *	( int transaction_number, int *lk_state );
 *   int http_lock_counters();
 *   int http_unlock_counters();
 *    int http_zero_counters();
 *
 * lock_state usage:
 *   Several of the routines include a lock_state argument, which is a pointer
 *   to an int.  If the int this argument points to is zero, the called
 *   function may acquire the global counters lock (http_lock_counters()) and
 *   set *lock_state to 1.  If the state is already 1, the function assumes
 *   the caller or a prior counter function acquired the global lock.
 *   The all counter updates are done, the caller must check the value of
 *   lock_state and free the lock.  Example:
 *
 *	if ( http_counters ) {
 *	    int lock_state=0;		! initially free
 *	    http_increment_keepalive_counter ( 0, &lock_state );
 *	    if ( lock_state ) http_unlock_counters ();
 *	}
 *
 * Author:	David Jones
 * Date:	21-APR-1995
 * Revised:	2-SEP-1995		support zero_time.
 * Revised:	19-FEB-1996		Support keepalive counters.
 * REvised:	 7-DEC-1996		Add lock_state variable to API and
 *					support for keepalive_offered.
 */

#include "pthread_1c_np.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "tserver_tcp.h"
#include "tutil.h"
/*
 * Define global variables, only http_counters externally visible.
 */
#include "counters.h"
int http_dns_enable;				/* Flags if dns lookup allowed*/
int http_keepalive_limit;
static struct counter_block counters;
static pthread_once_t counter_setup = PTHREAD_ONCE_INIT;
static pthread_mutex_t counter_ctl;		/* synchronizes access */
/*****************************************************************************/
/* Define initialization of global variables.
 */
static void module_init ()
{
    /* create pthread objects */
    INITIALIZE_MUTEX ( &counter_ctl );

    /* Initialize global counter block */
    counters.active_size = 0;	/* no active list */
    counters.host = (struct host_counter *) 0;
    counters.ka_histogram_size = 0;
}
/******************************************************************************/
/* Define routines for locking/unlocking global list for scanning/updating
 * purposes.  These routines are called internally as well, giving us the
 * option to replace the mutex with a condition-based lock in the future.
 */
int http_lock_counters ( ) {
    return pthread_mutex_lock ( &counter_ctl );
}
int http_unlock_counters ( ) {
    return pthread_mutex_unlock ( &counter_ctl );
}
/******************************************************************************/
/* Active counter routines.
 */
int http_enable_active_counters()
{
    int i, status;
    /* 
     * Make initial allocation of active stack. Freeze counter database
     * while allocating.
     */
    status = 1;
    pthread_once ( &counter_setup, module_init );
    http_lock_counters();
    http_counters = &counters;
    if ( counters.active_size == 0 ) {
	counters.active_size = 32;
	counters.ka_histogram_size = 32;
	LOCK_C_RTL
	counters.active_hist = 
		(int *) malloc ( sizeof(int) * counters.active_size );
	counters.active_stack = (struct client_counter *)
		malloc ( sizeof(struct client_counter) * counters.active_size );
	counters.ka_hist = (int *) malloc ( 
		sizeof(int) * counters.ka_histogram_size );
	UNLOCK_C_RTL
	if ( !counters.active_hist || !counters.active_stack ||
		!counters.ka_hist ) {
	    LOCK_C_RTL
	    printf("Error allocating counter storage\n");
	    UNLOCK_C_RTL
	    counters.active_size = 0;
	    counters.ka_histogram_size = 0;
	    status = 0;
	} else {
	    /* Zero the histogram */
	    http_zero_counters(1);
	}
	counters.active_sp = 0;
    }
    http_unlock_counters();
    return status;
}

int http_open_active_counter ( int ndx, int port, unsigned char *address,
	int *lock_state )
{
    int sp, status, i;
    struct client_counter *client;

    if ( !*lock_state ) { http_lock_counters(); *lock_state = 1; };
    status = 0;
    if ( counters.active_hist &&
	counters.active_sp >= counters.active_size ) {
	/*
	 * Expand active lists if we grew too much.
	 */
	counters.active_size = counters.active_size * 2;
	LOCK_C_RTL
	counters.active_hist = (int *) realloc ( 
		counters.active_hist, sizeof(int) * counters.active_size );
	counters.active_stack = (struct client_counter *)
		realloc ( counters.active_stack,
		    sizeof(struct client_counter)*counters.active_size );
	UNLOCK_C_RTL
	if ( !counters.active_hist || !counters.active_stack ) {
	    LOCK_C_RTL
	    printf("Error expanding counter storage, counters lost\n");
	    UNLOCK_C_RTL
	    counters.active_size = 0;
	    status = 0;
	} else {
	    /* Zero the new portion of the histogram */
	    for ( i = counters.active_sp; i < counters.active_size; i++ )
		counters.active_hist[i] = 0;
	}
    }

    if ( counters.active_hist ) {
	/*
	 * Count number of clients at each concurrency level.
	 */
        sp = counters.active_sp++;
	counters.active_hist[sp]++;
	/*
	 * allocate spot on active stack and initialize.
	 */
	client = &counters.active_stack[sp];
	client->ndx = ndx;
	client->port = port;
	client->address = address;
	client->method = (char *) 0;
	client->ident = (char *) 0;
	status = 1;
    }
    return status;
}

int http_set_active_counter ( int ndx, char *method, char* request, int
	*lock_state )
{
    int sp, status, i;
    struct client_counter *client;

    if ( !*lock_state ) { http_lock_counters(); *lock_state=1; }
    status = 0;
    if ( counters.active_stack ) {
	/*
	 * Locate index on active list, search from back since longest
	 * open connections will work down to bottom of stack.
	 */
	sp = counters.active_sp-1;
	for ( i = sp; i >= 0; --i ) {
	    if ( counters.active_stack[i].ndx == ndx ) {
		/*
		 * Set pointers in client block from active list.
		 */
		client = &counters.active_stack[i];
		client->method = method;
		client->ident = request;
		status = 1;
		break;
	    }
	}
    }
    return status;
}

int http_close_active_counter ( int ndx )
{
    int sp, status, i;
    struct client_counter *client;

    http_lock_counters();
    status = 0;
    if ( counters.active_stack ) {
	/*
	 * Locate index on active list, search from back since longest
	 * open connections will work down to bottom of stack.
	 */
	sp = --counters.active_sp;
	for ( i = sp; i >= 0; --i ) {
	    if ( counters.active_stack[i].ndx == ndx ) {
		/*
		 * Remove client block from active list.
		 */
		if (i != sp) counters.active_stack[i] = 
			counters.active_stack[sp];
		status = 1;
		break;
	    }
	}
	if ( i < 0 ) counters.active_sp++;	/* not found */
    }
    http_unlock_counters();
    return status;
}
/****************************************************************************/
/* Reset all counter fields to zero, note that active list is not removed.
 */
int http_zero_counters ( int have_lock )
{
    int i;
    struct host_counter *host;
    time_t now;
    char ftime[40];
    /*
     * Lock global data and iterate through histogram and host counter list
     */
    pthread_once ( &counter_setup, module_init );
    if ( have_lock == 0 ) http_lock_counters();
    for ( i = 0; i < counters.active_size; i++ ) counters.active_hist[i] = 0;
    for ( i = 0; i < counters.ka_histogram_size; i++ )
	counters.ka_hist[i] = 0;
    counters.ka_offered = 0;
    for ( host = counters.host; host; host = host->next ) host->count = 0;
    /*
     * Format current time and store in zero_time field, trim trailing LF.
     */
    pthread_lock_global_np();
    time ( &now );
    tu_strcpy ( ftime, ctime(&now) );
    pthread_unlock_global_np();
    if ( tu_strlen ( ftime ) > 3 ) {
	for ( i = 4; ftime[i] && (ftime[i] != '\n'); i++ ) {
	    http_counters->zero_time[i-4] = ftime[i];
	}
	http_counters->zero_time[i-4] = '\0';
    }
    else http_counters->zero_time[0] = '\0';

    if ( have_lock == 0 ) http_unlock_counters();
    return 1;
}
/************************************************************************/
/* Compare host string with IP address, return 1 if it matches. 
 */
static int check_host ( char *host, unsigned char *address )
{
    static char octet_str[256][4];
    static int octet_str_init = 0;

    if ( ( *host >= '0' ) && ( *host <= '9' ) ) {
	/*
	 * Numeric host address.  Compare octet by octet, host string can
	 * substitute * for an octet.
	 */
        char number[16], *d, *octet;
        int i, j, len;
	if ( !octet_str_init ) {
	    /* First time, init numeric strings */
	    for ( i = 0; i < 256; i++ ) tu_strint ( i, octet_str[i] );
	    octet_str_init = 1;
	}

        for ( d = host, i = 0; i < 4; i++ ) {
	    if ( (*d == '*') && ((d[1]=='.')||(d[1]=='\0')||(d[1]==',')) ) {
		d += 2;
	    } else {
		octet = octet_str[address[i]];
		for ( len = 0; d[len] && 
			(d[len] != ',') && (d[len] != '.'); len++ ) {
		    if ( d[len] != octet[len] ) break;		/* mismatch */
		}

		if ( octet[len] != '\0' ) break;
		else if ( i < 3 ) {
		    if ( d[len] != '.' ) break;		/* wrong delimiter */
		} else {
		    if ( (d[len] != '\0') && (d[len] != ',') ) break;
		}
		d += len + 1;
	    }
	}
	if ( i == 4 ) return 1;	/* we have a match, 4 fields matched */

    } else if ( http_dns_enable ) {
	/*
	 * Compare domain name.
	 */
	char *d;
        int i, j, k, len, rhost_len;
	char remote_host[256];

	tu_strnzcpy ( remote_host, ts_tcp_remote_host(), 255 );
	rhost_len = tu_strlen ( remote_host );
	remote_host[rhost_len++] = '.';

	/* Break hostname into separate labels */
	d = host;
	for (j=i=0; i <= rhost_len; i++ ) if (remote_host[i]=='.') {
	    /* 
	     * String goes from j to i, ending in period.  Determine
	     * length (k) of next label in pattern string (d)
	     */
	    for ( k=0; d[k] && (d[k]!='.') && (d[k] != ','); k++ );
	    len = i - j;
	    if ( (k != 1) || (d[0] != '*') ) {

	        if ( k != len) break;	/* mismatch */
	        if ( tu_strncmp(d,&remote_host[j],len) ) break;
	    }
	    d += k; if ( *d ) d++;
	    j = i+1;
	}
	/* We pass if If all labels matched and no more value */
	if ( (i > rhost_len) && !*d ) return 1;
    }
    return 0;
}
/****************************************************************************/
/* Define routines to handle counters based on source host, do later. 
 */
int http_define_host_counter ( char *class_name, char *host_mask )
{
    struct host_counter *class, *existing;
    int i;
    /*
     * Search for host counter block with specified class_name.
     */
    pthread_once ( &counter_setup, module_init );
    http_lock_counters();
    existing = (struct host_counter *) 0;
    for ( class = counters.host; class; class = class->next ) {
	if ( tu_strncmp ( class->class_name, class_name, 256 ) == 0 ) {
	    /*
	     * Add host_mask to existing class.
	     */
	    existing = class;
	    i = tu_strlen ( class->mask );
	    if ( i < (sizeof(class->mask)-tu_strlen(host_mask)-2) ) {
		class->mask[i++] = ',';
		tu_strcpy ( &class->mask[i], host_mask );
	    } else {
		/* Overflow of storage space */
	    }
	    break;
	} else if ( class->next == (struct host_counter *) 0 ) {
	    break;
	}
    }

    if ( !existing ) {
	LOCK_C_RTL
	existing = (struct host_counter *) malloc(sizeof(struct host_counter));
	existing->class_name = malloc ( tu_strlen(class_name) + 1 );
	UNLOCK_C_RTL
	existing->next = (struct host_counter *) 0;
	existing->count = 0;
	tu_strnzcpy ( existing->mask, host_mask, sizeof(existing->mask)-1 );
	tu_strcpy ( existing->class_name, class_name );
	if ( class ) class->next = existing; else counters.host = existing;
    }
    http_unlock_counters();
    return 0;
}

int http_increment_host_counters ( unsigned char *address, int *lock_state )
{
    struct host_counter *class;
    int i, j, negate_check, negate_fail;
    char *mask;
    /*
     * Scan all host classes and increment counters on all that match.
     */
    if ( !*lock_state ) { http_lock_counters(); *lock_state = 1; };
    for ( class = counters.host; class; class = class->next ) {
	/*
	 * check list of host belonging to this class.
	 * To bump the counter, the remote address must match at least
	 * one of the non-negated hosts in the mask or match none of
	 * the negated hosts in the mask.
	 */
	mask = class->mask;
	negate_check = negate_fail = 0;
	if ( mask[0] ) for ( i = 0; mask[i]; i = j ) {
	    /*
	     * Find end point of current mask, mask[i..j-1] is string.
	     */
	    for ( j = i+1; mask[j] && (mask[j] != ','); j++ );
	     if ( mask[j] ) j++;
	    /*
	     * Test string against stuff.
	     */
	    if ( mask[i] == '~' ) {
		negate_check = 1; 
		if ( check_host ( &mask[i+1], &address[4] ) ) {
		    /* Matching a negated host means we fail */
		    negate_fail = 1;
		}
	     } else {
		if ( check_host ( &mask[i], &address[4] ) ) {
		    negate_check = 0;	/* ignore negation results */
		    class->count = class->count + 1;
		    break;	/* go to next class */
		}
	     }
	}
	if ( negate_check && !negate_fail ) class->count += 1;
    }
    /* http_unlock_counters(); */
    return 1;
}

int http_increment_keepalive_counter ( int transaction_number,int  *lock_state )
{
    if ( transaction_number < 0 ) return 0;
    if ( !*lock_state ) { http_lock_counters(); *lock_state = 1; };
    if ( counters.ka_histogram_size > transaction_number ) {
	counters.ka_hist[transaction_number]++;
    } else {
	counters.ka_hist[counters.ka_histogram_size-1]++;
    }
    /* http_unlock_counters(); */
    return 1;
}
