/*
 * This module handles the low-level transport layer of the FASTCGI server,
 * establishing connections to applications and multiplexing the record
 * streams.
 *
 *    status = fcgi_connect ( apphost, port, fcgi_hndl &fcgi, char err[256] );
 *    status = fcgi_send ( fcgi, int msgtype, void *msg, int msgsize );
 *    status = fcgi_recv ( fcgi, int &msgtype, char **msg, int *msgsize );
 *    status = fcgi_disconnect ( fcgi, int keep_connection );
 *    status = fcgi_app_info ( fcgi, &apphost, &port );
 *
 * On send, the callers buffer is copied to a buffer managed by this module.
 * The receive function returns a pointer to the message data kept in
 * a module-private buffer whose lifetime is the next recv call.
 *
 * Author:	David Jones
 * Date:	22-JUN-1997
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tclient_tcp.h"
#include "tutil.h"
#include "pthread_1c_np.h"
#include "fastcgi_mux.h"
#include "mst_share.h"
#define FCGI_VERSION_1 1
#define FCGI_HEADER_LEN 8
#define FCGI_GET_VALUES 9
#define FCGI_GET_VALUES_RESULT 10
#define MAX_IOSIZE 4096
/*
 * msg_buffer is the basic structure for handling FASTCGI records, the unit
 * of transfer between the server and the application.  A msg_queue structure
 * manages a fifo list of these buffers.  The free_msg global holds a cache
 * of free msg_buffers for quick allocation.
 */
struct msg_buffer {
    struct msg_buffer *next;
    char *content;			/* points to malloced buffer or
						.rec.content */
    int req_id;
    int hdr_pos;			/* if < 8, then still reading header */
    int content_length;			/* content length in host data order */
    int total_length;			/* content length + padding length */
    int content_pos;
    struct {
	/* 
         * FASTCGI record structure.  Note that version byte is declared
         * as an array to facilitate continutation while reading header.
         */
	unsigned char version[1];	/* FASTCGI version (1) */
	unsigned char type;		/* Record type: */
	unsigned char requestid_msb;	/* High byte of request ID */
	unsigned char requestid_lsb;
	unsigned char contentlength_msb;  /* High byte of data length */
	unsigned char contentlength_lsb;
	unsigned char paddinglength;	/* # of pad bytes that follow data */
        unsigned char reserved;
	char content[120];		/* data if contentlength+padding < 120
					 * else use content pointer above */
    } rec;
};
typedef struct msg_buffer *msgbuf;
static msgbuf free_msg;			/* Lookaside list */
/*
 * The msg_queue struct controls a FIFO of msg_buffer structs.  The nonempty
 * condition variable and dequeue_pending flag is used to allow a dequeuing
 * thread to wait for another thread to queue the next msg_buffer.
 * The cur pointer points to the buffer previously dequeued, head points
 * to the buffer that will be dequeued next.
 */
struct msg_queue {
    msgbuf cur, head, tail;
    int dequeue_pending;		/* Non-zero if waiting */
    pthread_cond_t nonempty;
};
/*
 * The fcgi_context struct manages a single request ID.  The context can
 * operate in 2 modes: multiplexed and non-multiplexed.  In multiplexed mode,
 * fastcgi records are sent and received via msg_queue FIFOs:  sends are queued
 * to the owning app_context's outbound queue and receives are dequeued from
 * this context's inbound queue.  In non-multiplexed mode, the sends and
 * receives are done directly to the cnx socket handle.
 */
struct fcgi_context {
   struct fcgi_context *next;		/* Next fgi_context onwed by thread */
   int request_id;			/* ID 0 reserved for control thread */
   int req_state;			/* 0-free, 1-in use, 2-idle */
   tc_socket cnx;			/* TCP socket, not used if multiplex */
   msgbuf inbound;			/* 'active' input */
   struct app_context *app;		/* back pointer */
   struct msg_queue in_queue;
};
typedef struct fcgi_context *fcgi_ctx;
/*
 * The app_context structure controls a single connection to a FASTCGI
 * application and optionally manages multiplexing the requests.
 * The global app_list structure is the list head for the list of active
 * contexts.
 */
static struct app_context {
    struct app_context *flink, *blink;
    char *host;
    int port;
    int ref_count;			/* Number of threads linked */
    int app_state;			/* 0 - init (locked), 1 - ready */
    int multiplexed;			/* true if multiplexing */
    int max_reqid, areq_active;		/* max requests alllowed on this cnx */

    pthread_mutex_t lock;		/* Lock for accessing message queues */
    pthread_cond_t init_done;

    struct msg_queue out_queue;
    fcgi_ctx req;			/* variable length array [max_reqid] */
    struct fcgi_context req0;		/* initial request */
} app_list;				/* List header */

/*
 * Define global pthread objects for synchronizing access of shared data.
 */
static pthread_mutex_t msg_pool;	/* Locks pool memory man. structures */

static pthread_mutex_t app_pool;	/* Locks app list memory structures */
static pthread_key_t fastcgi_key;	/* Value is fcgi_ctx for thread */

/***************************************************************************/
/* The follow group of routines are utility functions for managing the
 * message buffers an queues: 
 *    init_queue 	Initializes structure (initially empty).
 *    clear_queue	Discards all queued message buffers.
 *    destroy_queue	Deletes queue structure (assumed empty).
 *    enqueue		Add message to tail of queue (signalling waiters)
 *    dequeue		Make head message cur message (or null).
 *    dequeue_wait	Wait for non-empty queue, then dequeue.
 */
static void init_queue ( struct msg_queue *queue )
{
    queue->cur = queue->head = queue->tail = (msgbuf) 0;
    queue->dequeue_pending = 0;
    INITIALIZE_CONDITION ( &queue->nonempty );
    return;
}

static void clear_queue ( struct msg_queue *queue )
{
    /*
     * Note, queue is note locked.
     */
    if ( queue->head || queue->cur ) {
	/*
	 * Return unread messages to pool.
	 */
	if ( queue->cur ) {	/* push back onto queue */
	    if ( !queue->head ) queue->tail = queue->cur;
	    queue->cur->next = queue->head;
	    queue->head = queue->cur;
	    queue->cur = (msgbuf) 0;
	}
	pthread_mutex_lock ( &msg_pool );
	queue->tail->next = free_msg;
	free_msg = queue->head;
	pthread_mutex_unlock ( &msg_pool );
	queue->head = (msgbuf) 0;
    }
}
static void destroy_queue ( struct msg_queue *queue )
{
    clear_queue ( queue );
    pthread_cond_destroy ( &queue->nonempty );
}

static int enqueue ( msgbuf msg, struct msg_queue *queue, 
	pthread_mutex_t *lock)
{
    int status;
    msg->next = (msgbuf) 0;		/* message is at end of list */
    pthread_mutex_lock ( lock );
    if ( queue->head ) {
	queue->tail->next = msg;
	status = 0;
    } else {
	queue->head = msg;
	if ( queue->dequeue_pending ) pthread_cond_signal ( &queue->nonempty );
	status = 1;			/* Queue was empty */
    }
    queue->tail = msg;
    pthread_mutex_unlock ( lock );
    return status;
}

static msgbuf dequeue ( struct msg_queue *queue, pthread_mutex_t *lock )
{
    pthread_mutex_lock ( lock );
    queue->cur = queue->head;
    if ( queue->head ) queue->head = queue->head->next;
    pthread_mutex_unlock ( lock );
    return queue->cur;
}
static msgbuf dequeue_wait ( struct msg_queue *queue, pthread_mutex_t *lock )
{
    pthread_mutex_lock ( lock );
    while ( !queue->head ) {
	queue->dequeue_pending++;
	pthread_cond_wait ( &queue->nonempty, lock );
	--queue->dequeue_pending;
    }
    queue->cur = queue->head;
    queue->head = queue->head->next;
    pthread_mutex_unlock ( lock );
    return queue->cur;
}
/***************************************************************************/
/* Allocate and initialize an array of fcgi_context structures to be owned
 * by app_context.  The request ID value is initialized to the position of 
 * the structure in the array.
 */
int allocate_req_list ( struct app_context *app, int size )
{
    int i;
    fcgi_ctx req;

    app->max_reqid = 0;
    if ( size > 1 ) {
	app->req = (fcgi_ctx) malloc ( sizeof(struct fcgi_context) * size );
        if ( !app->req ) return 0;
    } else {
	app->req = &app->req0;
    }
    app->max_reqid = size;
    req = app->req;
    for ( i = 0; i < size; i++ ) {
	req[i].request_id = i;
	req[i].req_state = 0;
	req[i].app = app;
	init_queue ( &req[i].in_queue );
    }
    return 1;
}
/*
 * Destroy fgi_context array created by allocate_req_list.
 */
void deallocate_req_list ( struct app_context *app )
{
    int i;
    fcgi_ctx req;
    req = app->req;
    for ( i = 0; i < app->max_reqid; i++ ) {
	destroy_queue ( &req[i].in_queue );
    }
    if ( app->max_reqid > 1 ) free ( app->req );
    app->max_reqid = 0;
    app->req = (fcgi_ctx) 0;
    
}
/***************************************************************************/
/*  Decrement refernece count in app block (we assume thread has incremented
 * it) and unlink if count drops to zero.
 */
static void dereference_app ( struct app_context *app )
{
    int last_reference;
    pthread_mutex_lock ( &app_pool );
    app->ref_count--;
    last_reference = 0;
    if ( app->ref_count < 0 ) {
	/* bugcheck */
	tlog_putlog (0,"Bugcheck: Multiple deallocation of fastcgi mux block!/");
    } else if ( app->ref_count == 0 ) {
	/* unlink from global list */
	last_reference = 1;
	app->blink->flink = app->flink;
	app->flink->blink = app->blink;
    }
    pthread_mutex_unlock ( &app_pool );

    if ( last_reference ) {
	/*
	 * Deconstruct block.
	 */
	pthread_mutex_destroy ( &app->lock );
	pthread_cond_destroy ( &app->init_done );
	destroy_queue ( &app->out_queue );
	deallocate_req_list ( app );
	LOCK_C_RTL
	free ( app->host );
	free ( app );
	UNLOCK_C_RTL
    }
}
/***************************************************************************/
/* Destructor routine for fastcgi_key context key.  Traverse the list of
 * fcgi_contexts owned by the thread and close their connections.
 */
static void fcgi_rundown ( fcgi_ctx ctx ) 
{
    struct app_context *app;
    struct fcgi_context dummy;

    if ( http_log_level > 10 ) tlog_putlog(11,"Beginning fcgi_rundown!/");
    for ( ; ctx; ctx = ctx->next ) {
        app = ctx->app;
	pthread_mutex_lock ( &app->lock );
	if ( app->multiplexed == 0 ) { 
	    tc_close ( ctx->cnx ); 
	    ctx->cnx = 0;
	} else {
	    /* Send request abort message */
	}
        ctx->req_state = 0;		/* mark request ID as free */
	pthread_mutex_unlock ( &app->lock );
        dereference_app ( app );
    }
}
/***************************************************************************/
/* One-time initialization for module.  Initialize globals objects.
 */
int fcgi_init_mux ( )
{
    INITIALIZE_MUTEX ( &msg_pool );
    INITIALIZE_MUTEX ( &app_pool );
    CREATE_KEY ( &fastcgi_key, (pthread_destructor_t) fcgi_rundown );
    /*
     * Initialize app list to empty.
     */
    app_list.flink = app_list.blink = &app_list;
    app_list.host = "";
    app_list.port = -1;
    app_list.ref_count = 0;
    INITIALIZE_MUTEX ( &app_list.lock );
    free_msg = (msgbuf) 0;
    return 1;
}
/***************************************************************************/
/* Scan application contexts for matching host/port and allocate request ID
 * from the context, returning the address of corresponding fgi_context 
 * structure.  On error, null is returned and errmsg contains error text.
 */
static fcgi_ctx allocate_ctx ( char *host, int port, char *errmsg )
{
    fcgi_ctx ctx;
    struct app_context *app;
    int i, embryo;
    /*
     * Scan app control blocks for matching host/port tag, creating an
     * embryonic one if not found.  Reference count is incremented to
     * ensure it isn't removed.
     */
    ctx = (fcgi_ctx) 0;
    pthread_mutex_lock ( &app_pool );
    for (app = app_list.flink; app != &app_list; app = app->flink) {
	if ((app->port == port) && (0 == tu_strncmp (host, app->host,1000))) {
	    if ( http_log_level > 10 ) tlog_putlog(11,
		 "Found exising app block for !AZ:!SL, ref_count: !SL!/", 
			host, port, app->ref_count );
	    app->ref_count++;
	    embryo = 0;
	    break;
	}
    }
    if ( app == &app_list ) {
	/* 
	 * Scan failed, allocate new app block and place into list.
	 */
	embryo = 1;
	app = (struct app_context *) malloc ( sizeof(struct app_context) );
        app->host = malloc ( tu_strlen(host)+1 );
	tu_strcpy ( app->host, host );
	app->flink = &app_list;
	app->blink = app_list.blink;
	app_list.blink->flink = app;
	app_list.blink = app;
	app->port = port;
	app->ref_count = 1;
	app->app_state = 0;		/* mark as initting */
	INITIALIZE_MUTEX ( &app->lock );
	INITIALIZE_CONDITION ( &app->init_done );
    }
    pthread_mutex_unlock ( &app_pool );
    /*
     * Lock app context and search for free request.
     */
    pthread_mutex_lock ( &app->lock );
    if ( embryo ) {
	/*  New connection, complete initialization of items that we
	 * didn't need the app_pool mutex to access.
	 */
	app->multiplexed = 0;
	app->max_reqid = 2;
	app->areq_active = 0;
	init_queue ( &app->out_queue );
	allocate_req_list ( app, 2 );	/* room for null reqid + 1 */
	ctx = app->req;			/* point to first element */
    } else {
	/*
	 * Wait for initialization to complete.
	 */
	while ( app->app_state == 0 ) {
	    tlog_putlog(11,"Waiting for app init to complete!/");
	    pthread_cond_wait ( &app->init_done, &app->lock );
	}
	/*
	 * Take first avaialbe request id.
	 */
	for (i=1; i < app->max_reqid; i++) if ( app->req[i].req_state != 1 ) {
	    ctx = &app->req[i];
	    /*  
	     * If we are re-using an idle connection, undo ref_count increment
	     */
	    if ( app->req[i].req_state == 2 ) {
		dereference_app ( app );
		tc_attach ( ctx->cnx );
	    }
	    ctx->req_state = 1;
	    break;
	}
    }
    pthread_mutex_unlock ( &app->lock );
    if ( ctx ) {
	/*
	 * Link into thread-specific list of fcgi_contexts.
	 */
	if ( ctx->request_id > 0 ) {
	    GET_SPECIFIC ( fastcgi_key, ctx->next );
	    pthread_setspecific ( fastcgi_key, ctx );
	}
    } else {
	/*
	 * Failure, remove reference and deallocate app block.
	 */
	dereference_app ( app );
	tu_strnzcpy ( errmsg, "Failed to allocate context", 100 );
    }
    return ctx;
}

/*****************************************************************************/
/* Utility routine for decoding name-value pairs. */
static char *namevaluepair_scan ( char *buffer,
	char **name, int *namlen, char **value, int *vallen )
{
    unsigned char *hdr;
    int length1, length2;

    hdr = (unsigned char *) buffer;
    length1 = *hdr++;
    if ( length1 > 127 ) {
	length1 = ((length1 & 0x7f) << 24)|(hdr[0]<<16)|(hdr[1]<<8)|hdr[2];
	hdr += 3;
    }
    length2 = *hdr++;
    if ( length2 > 127 ) {
	length2 = ((length2 & 0x7f) << 24)|(hdr[0]<<16)|(hdr[1]<<8)|hdr[2];
	hdr += 3;
    }
    *name = (char *) hdr;
    *namlen = length1;
    *value = (char *) &hdr[length1];
    *vallen = length2;
    return (char *) &hdr[length1+length2];
}
/*************************************************************************/
/* Allocate a message structure and set initial content length.
 */
static msgbuf allocate_message ( int content_length )
{
    msgbuf msg;
    /*
     * Allocate from message lookaside list, expanding list if empty.
     */
    pthread_mutex_lock ( &msg_pool );
    msg = free_msg;
    if ( !msg ) {
	int i;
	free_msg = (msgbuf) malloc ( 20 * sizeof(struct msg_buffer) );
	for ( i = 0; i < 19; i++ ) free_msg[i].next = &free_msg[i+1];
	free_msg[i].next = (msgbuf) 0;
	msg = free_msg;
    }
    free_msg = msg->next;
    pthread_mutex_unlock ( &msg_pool );
    /*
     * Initialize block.
     */
    msg->hdr_pos = msg->total_length = 0;
    if ( content_length <= sizeof(msg->rec.content) ) {
	msg->content = msg->rec.content;
    } else {
	LOCK_C_RTL
	msg->content = malloc ( content_length );
	UNLOCK_C_RTL
    }
    return msg;
}

static int realloc_message_content ( msgbuf msg, int content_length )
{
    if ( content_length <= sizeof(msg->rec.content) ) {
	if ( msg->content != msg->rec.content ) {
	    LOCK_C_RTL
	    free ( msg->content );
	    UNLOCK_C_RTL
	}
	msg->content = msg->rec.content;
    } else {
	if ( msg->content != msg->rec.content ) {
	    LOCK_C_RTL
	    msg->content = realloc ( msg->content, content_length );
	    UNLOCK_C_RTL
	} else {
            LOCK_C_RTL
	    msg->content = malloc ( content_length );
	    UNLOCK_C_RTL
	}
	if ( !msg->content ) return 0;
    }
    return 1;
}

static void deallocate_message ( msgbuf msg )
{
    if ( msg->content != msg->rec.content ) {
	free ( msg->content );
    }
    pthread_mutex_lock ( &msg_pool );
    msg->next = free_msg;
    free_msg = msg;
    pthread_mutex_unlock ( &msg_pool );
}
/*****************************************************************************/
static int create_app ( struct app_context *app, int request_id, char *err_msg )
{
    tc_socket cnx;
    int status, max_reqs, max_conns;
    static char getvalues_msg[] = { 14, 0, 'F', 'C', 'G', 'I', '_', 'M',
	'A', 'X', '_', 'C', 'O', 'N', 'N', 'S', 13, 0, 'F', 'C', 'G', 'I',
	'_', 'M', 'A', 'X', '_', 'R', 'E', 'Q', 'S', 15, 0, 'F', 'C', 'G',
	'I', '_', 'M', 'P', 'X', 'S', '_', 'C', 'O', 'N', 'N', 'S'
    };
    /*
     * Try to get connection first so we don't waste time allocating stuff.
     */
    if ( http_log_level > 10 )
        tlog_putlog(11,"/mux/ creating new application connection (!AZ:!SL)!/",
	     app->host, app->port );
    status = tc_open_tcp_socket ( app->host, app->port, 
		0, (char **) 0, &cnx, err_msg );
    if ( (status&1) == 0 ) {
	tlog_putlog ( 5, "Connect error on !AZ/!SL: !AZ (!SL)!/", app->host,
		app->port, err_msg, status );
	return status;
    }
    app->req[request_id].cnx = cnx;
    if ( request_id > 0 ) {
	/* Secondary client */
	return 1;
    }
    max_reqs = max_conns = 0;
    /*
     * Send get values messge to determine application limits.
     */
    status = fcgi_send ( (fcgi_handle) &app->req[0], FCGI_GET_VALUES, 
	(void *) getvalues_msg, sizeof(getvalues_msg) );
    if ( status&1 ) status = fcgi_send ( (fcgi_handle) &app->req[0], 
	FCGI_GET_VALUES, (void *) getvalues_msg, 0 );
    if ( status&1 ) {
	char *result, *result_part, *nvctx, *name, *value;
	int msgtype, msgsize, result_size;
	int namlen, vallen;
	/*
	 * read returned stream and put in allocated array.
	 * Those fuckers can't make up their minds about whether GET_VALUES
	 * pairs are sent in a stream on management record.
	 */
	result = (char *) 0;
	result_size = 0;
	do {
	    status = fcgi_recv ( (fcgi_handle) &app->req[0], &msgtype,
		&result_part, &msgsize );
	    if ( (status&1) == 0 || msgtype != FCGI_GET_VALUES_RESULT ) {
	        /* Error */
	        tu_strcpy ( err_msg, "error reading FCGI_GET_VALUES_RESULT message" );
	        msgsize = 0;
	    } else {
		LOCK_C_RTL
		if ( result_size == 0 ) result = malloc ( msgsize );
		else result = realloc ( result, msgsize+result_size );
		memcpy ( &result[result_size], result_part, msgsize );
		UNLOCK_C_RTL
		result_size += msgsize;
		break;
	    }
	} while ( msgsize != 0 );
	/*
	 * Scan the returned list of values.
	 */
	for ( nvctx = result; nvctx < &result[result_size]; ) {
	    nvctx = namevaluepair_scan ( nvctx, &name, &namlen,
			&value, &vallen );
	    if ( (name+namlen) > &result[result_size] || 
		(value+vallen) > &result[result_size]  ) { 
		/* Invalid name-value pair encoding. */
	    }
	    if ( tu_strncmp ( name, "FCGI_MAX_CONNS", 14 ) == 0 ||
	         tu_strncmp ( name, "FCGI_MAX_REQS", 13 ) == 0 ) {
		/*
		 * Convert value to integer.
		 */
		int i, number;
		for ( i = number = 0; i < vallen; i++ ) {
		    if ( value[i] >= '0' && value[i] <= '9' )
		    	number = number*10 + (value[i]-'0');
		    else break;
		}
		if ( namlen == 13 ) max_conns = number; else max_reqs = number;
	    } else if ( tu_strncmp ( name, "FCGI_MPXS_CONNS", 15 ) == 0 ) {
		/*
		 * Set multiplex enable flag.
		 */
		if ( (vallen == 1) && (*value == '1') ) app->multiplexed = 1;
	    }
	    if ( result_size > 0 ) free ( result );
	}
    } else {
	tu_strcpy ( err_msg, "error writing FCGI_GET_VALUES message" );
    }
    /*
     * Resize the requestor array to handle max number of clients.
     */
    if ( max_conns > max_reqs ) max_reqs = max_conns;
    if ( max_reqs > 2000 ) max_reqs = 2000;
    deallocate_req_list ( app );
    allocate_req_list ( app, max_reqs+1 );
    /*
     * Create dispatcher thread.
     */
    if ( app->multiplexed ) {
	tc_detach ( cnx );
    }
    return status;
}
/*************************************************************************/
/* Stall routine for non-multiplexed connections.  Wait for next event
 * that matches mask.  Revceived data while waiting for write event
 * is queued.
 *
 * Return values:
 *	0	Error on socket.
 *	1	Sucessful completion, outbound completed or message enqueued.
 *	2	Bugcheck, write complete when no outbound specified.
 *	3	Attention called socket.  Note status 1 (outbound completion
 *		takes precedence).
 */
static int await_io ( fcgi_ctx ctx, msgbuf outbound )
{
    int flags, bytes_read, bytes_written, segsize, status;
    msgbuf msg;
    /*
     * setup initial read if none active.
     */
    msg = ctx->inbound;
    if ( !msg ) {
        ctx->inbound = msg = allocate_message(sizeof(msg->rec.content));
        msg->hdr_pos = 0;
        status = tc_start_io ( ctx->cnx, 1, &msg->rec, 8 );
        if ( (status&1) == 0 ) {
        }
    }
    /*
     * Main loop, wait for event and react.
     */
    while ( tc_io_stall ( ctx->cnx, &flags, &bytes_read, &bytes_written ) ) {
	/*
	 * Write completion sets bit 0.
	 */
	if ( http_log_level > 10 ) tlog_putlog ( 11,
	    "MUX await_io stall returned, flags: !SL, bytes: !SL read  !SL wrote!/",
		flags, bytes_read, bytes_written );
	if ( flags & 1 ) {
	    /* Write completed, see if all written */
	    if ( !outbound ) return 0;		/* Unexpected */

	    if ( outbound->hdr_pos < 8 ) {	/* still writing header */
		outbound->hdr_pos += bytes_written;
		bytes_written = 0;
	    }
	    if ( outbound->hdr_pos < 8 ) {
		status = tc_start_io ( ctx->cnx, 0, 
			&outbound->rec.version[outbound->hdr_pos], 
			8 - outbound->hdr_pos );
	    } else {
		outbound->content_pos += bytes_written;
		if ( outbound->content_pos >= outbound->total_length ) {
		    /*
		     * Content all written.
		     */
		   break;
	        } else {
		    /*
		     * Write remaining piece (or up to 4K of it).
		     */
		    segsize = outbound->total_length - outbound->content_pos;
		    status = tc_start_io ( ctx->cnx, 0, 
			&outbound->content[outbound->content_pos],
			segsize > MAX_IOSIZE ? MAX_IOSIZE : segsize );
	        }
	    }
	}
	/*
	 * Read completion sets bit 1.
	 */
	if ( flags & 2 ) {
	    /*  Read completed, update position context. */
	    if ( http_log_level > 10 ) tlog_putlog ( 11,
		"Read completion, header pos: !SL content: !SL!/", 
		msg->hdr_pos, msg->content_pos );
	    if ( msg->hdr_pos < 8 ) {		/* still reading header */
		msg->hdr_pos += bytes_read;
		bytes_read = 0;
		if ( msg->hdr_pos == 8 ) {
		    /*
		     * Header complete, decode and setup for reading content.
		     */
		    msg->req_id = msg->rec.requestid_msb;
		    msg->req_id = msg->req_id<<8 | msg->rec.requestid_lsb;
		    msg->content_length = msg->rec.contentlength_msb;
		    msg->content_length = msg->content_length<<8 | 
			msg->rec.contentlength_lsb;
		    msg->total_length = msg->content_length +
			msg->rec.paddinglength;
		    msg->content_pos = 0;
		    if ( http_log_level > 10 ) tlog_putlog ( 11,
			"  Decoded header: id: !SL type: !SL content_length: !SL!/",
			   msg->req_id, msg->rec.type, msg->content_length);
		    if ( !realloc_message_content (msg, msg->total_length) ) {
		    }
		}
	    } else {
		msg->content_pos += bytes_read;
	    }
	    /*
	     * Determine progress of record input.
	     */
	    if ( msg->hdr_pos < 8 ) {
		/*
		 * All of header hasn't been read yet, get rest of it.
		 */
		status = tc_start_io ( ctx->cnx, 1, 
			&msg->rec.version[msg->hdr_pos], 8 - msg->hdr_pos );
	    } else if ( msg->content_pos < msg->total_length ) {
		/*
		 * Initiate read of rest of content;
		 */
		segsize = msg->total_length - msg->content_pos;
		status = tc_start_io ( ctx->cnx, 1, 
			&msg->content[msg->content_pos], 
			segsize > MAX_IOSIZE ? MAX_IOSIZE : segsize );
	    } else {
		/*
		 * Buff now holds a complete record.
		 */
		ctx->inbound = (msgbuf) 0;	/* No longer active */
		if ( ctx->request_id == 0 ) {
		    /*
		     * We are multiplexed dispatcher.
		     */
		} if ( msg->req_id == ctx->request_id ) {
		    /*
		     * Place on input queue for context.
		     */
		   enqueue ( msg, &ctx->in_queue, &ctx->app->lock );
		} else if ( msg->req_id == 0 ) {
		    /* What to do with data on null channel */
		    deallocate_message ( msg );
	        } else {
		    /*
		     * Invalid request Id, drop it.
		     */
		    deallocate_message ( msg );
	        }
		/*
		 * Start new read (effectively double buffer reads)
		 */
		msg = ctx->inbound = allocate_message (sizeof(msg->rec.content));
		status = tc_start_io ( ctx->cnx, 1, &msg->rec, 8 );
		if ( !outbound && ctx->in_queue.head ) break;
	    }
	}
	/*
	 * Errors set bit 2.
	 */
	if ( flags & 4 ) {
	    /* Connection error, close up shop */
	    return 2;
	}
	if ( flags&8 ) return 3;	/* attention on cnx called */
    }
    /*
     * Wait satisfied.
     */
    return 1;
}
/*************************************************************************/
static int multiplex_dispatcher ( struct app_context *app )
{
    int flags, bytes_read, bytes_written, status;
    msgbuf msg;

    tc_attention ( app->req[0].cnx );	/* force first check for outbound */
    msg = (msgbuf) 0;
    for ( ; ; ) {
	status = await_io ( app->req, msg );
	switch ( status ) {
	    case 3:
		if ( !msg ) break;	/* spurious attention */

	    case 1:			/* Current write completd */
		msg = dequeue ( &app->out_queue, &app->lock );
		if ( msg ) {
		    status = tc_start_io ( app->req[0].cnx, 0,
			&msg->rec, 8 );
		}
		break;

	    case 0:
	    case 2:
		break;
	    default:
		/* error */
		break;
	}
    }
    /*
     * Abort, cleanup connection.
     */
    return 0;
}
/***************************************************************************/
int fcgi_listen ( int port, int connect_callback(), int request_callback(),
	char errmsg[256] )
{
    int status, max_connect, max_request, remote_port;
    unsigned char remote_addr[16];
    tc_listener ctx;
    tc_socket cnx;
    /*
     * Make listener object.
     */
    status = tc_create_tcp_listener ( port, 5, 0, (char **) 0, &ctx, errmsg );
    if ( (status&1) == 0 ) return status;

    tu_strcpy ( errmsg, "" );
    for ( ; ; ) {
	/*
	 * Accept connection.
	 */
	status = tc_accept ( ctx, &cnx, &remote_port, remote_addr,
		sizeof(remote_addr), errmsg );
	if ( (status&1) == 0 ) break;
	/*
	 * Make request callback to determine if connection allowed.
	 */
	status = connect_callback ( remote_addr, remote_port,
		&max_connect, &max_request );
	if ( status == 1 ) {
	    /*
	     * Connection accepted, create application context to
	     * handle multiplexing.
	     */
	} else {
	    /*
	     * Reject connection unceremoniously.
	     */
	    tc_close ( cnx );
	}
    }
    return status;
}
/***************************************************************************/
/* Below are external functions.
 *  Return values for fcgi_connect:
 *	0	Error, detail returned in err arrary.
 *	1	Success.
 *	2	Failed to allocate slot.
 */
int fcgi_connect ( char *apphost, int port, 
	fcgi_handle *cgi, char err[256] )
{
    fcgi_ctx ctx;
    struct app_context *app;
    int status, request_id;

    ctx = allocate_ctx ( apphost, port, err );
    if ( !ctx ) return 2;
    app = ctx->app;
    request_id = ctx->request_id;	/* preserve */

    if ( request_id == 0 ) {
	/*
	 * We are initial connect, do initial handshake to setup connection
	 * parameters.  Subsequent connects to this apphost/port by other
	 * threads will block until we complete the initialization.
	 * Send a FCGI_GET_VALUES request for max_conns, max_reqs, mpxs_conns.
	 */
	status = create_app ( app, request_id, err );
	if ( (status&1) == 0 ) {
	    dereference_app ( app );
	    return 0;
	}
	/*
	 * Move connection from 0 to 1.
	 */
	app->req[1].req_state = 1;
	if ( !app->multiplexed ) {
	    app->req[1].cnx = app->req[0].cnx;
	    app->req[1].inbound = app->req[0].inbound;
	    app->req[0].inbound = (msgbuf) 0;
	}
	ctx = &app->req[1];
	GET_SPECIFIC ( fastcgi_key, ctx->next );
	pthread_setspecific ( fastcgi_key, ctx );
	/*
	 * Continue anyone waiting for initialzation to complete.
	 */
	pthread_mutex_lock ( &ctx->app->lock );
	ctx->app->app_state = 1;
	pthread_cond_broadcast ( &ctx->app->init_done );
	pthread_mutex_unlock ( &ctx->app->lock );
    } else if ( ctx->app->multiplexed == 0 && !ctx->cnx) {
	/*
	 * Remote application does not understand multiplexing and wants
	 * a separate connection for each client.
	 */
	status = create_app ( app, request_id, err );
	if ( (status&1) == 0 ) {
	    dereference_app ( app );
	    return 0;
	}
    }
    *cgi = (fcgi_handle) ctx;
    return (ctx) ? 1 : 0;
}

int fcgi_send ( fcgi_handle fcgi, int msgtype, void *content, int msgsize )
{
    fcgi_ctx ctx;
    struct app_context *app;
    msgbuf msg;
    int status, total_length;
    /*
     * build message block.
     */
    ctx = (fcgi_ctx) fcgi;
    if ( ctx->req_state != 1 && ctx->request_id != 0 ) return 20;

    app = ctx->app;
    total_length = (msgsize+3) & (0x0FFFC);
    msg = allocate_message ( total_length );
    if ( !msg ) return 0;
    msg->req_id = ctx->request_id;
    msg->content_length = msgsize;
    msg->total_length = total_length;
    msg->rec.version[0] = 1;		/* FASTCGI_VERSION */
    msg->rec.type = msgtype;
    msg->rec.requestid_msb = (msg->req_id >> 8) & 255;
    msg->rec.requestid_lsb = msg->req_id & 255;
    msg->rec.contentlength_msb = (msgsize>>8) &255;
    msg->rec.contentlength_lsb = (msgsize) & 255;
    msg->rec.paddinglength = total_length - msgsize;
    msg->rec.reserved = 0;
    memcpy ( msg->content, content, msgsize );
    /*
     * Either queue to dispatcher (multiplexed) or write it out.
     */
    if ( app->multiplexed ) {
	if ( enqueue ( msg, &app->out_queue, &app->lock ) == 1 ) {
	    tc_attention ( app->req[0].cnx );
	}
	status = 1;
    } else {
	/* 
	 * Write header, then content 
	 */
	msg->hdr_pos = msg->content_pos = 0;
	status = tc_start_io ( ctx->cnx, 0, msg->rec.version, 8 );
	if ( status&1 ) status = await_io ( ctx, msg );

	deallocate_message ( msg );
    }
    return status;
}

int fcgi_recv ( fcgi_handle fcgi, int *msgtype, char **content, int *msgsize )
{
    fcgi_ctx ctx;
    struct app_context *app;
    msgbuf msg;
    int status, total_length;

    ctx = (fcgi_ctx) fcgi;
    if ( ctx->req_state != 1 && ctx->request_id != 0 ) return 20;
    app = ctx->app;

    if ( app->multiplexed ) {
	if ( ctx->in_queue.cur ) deallocate_message ( ctx->in_queue.cur );
	msg = dequeue_wait ( &ctx->in_queue, &app->lock );
	if ( !msg ) {
	} else {
	}
	status = 1;
    } else {
	status = await_io ( ctx, (msgbuf) 0 );
	if ( status == 1 ) {
	    msg = dequeue ( &ctx->in_queue, &app->lock );
	} else {
	    /*
	     * Error in wait.
	     */
	    return 0;
	}
    }
    *msgtype = msg->rec.type;
    *content = msg->content;
    *msgsize = msg->content_length;
    return status;
}
int fcgi_app_info ( fcgi_handle fcgi, char **apphost, int *port, int *mplx )
{
    fcgi_ctx ctx;
    struct app_context *app;

    ctx = (fcgi_ctx) fcgi;
    app = ctx->app;
    *apphost = app->host;
    *port = app->port;
    *mplx = app->multiplexed;
    
    return 1;
}

int fcgi_disconnect ( fcgi_handle fcgi, int keep_connection )
{
    fcgi_ctx ctx, prev_ctx;
    struct app_context *app;
    /*
     * Find context on per-thread list and remove.
     */
    ctx = (fcgi_ctx) fcgi;
    GET_SPECIFIC ( fastcgi_key, prev_ctx );
    if ( prev_ctx == ctx ) pthread_setspecific ( fastcgi_key, ctx->next );
    else {
	while ( prev_ctx ) {
	    if ( prev_ctx->next == ctx ) {
		prev_ctx->next = ctx->next;
		break;
	    }
	    prev_ctx = prev_ctx->next;
	}
	if ( !prev_ctx ) {
	    tlog_putlog ( 0,"Bugcheck: fcgi context not found on key chain!/" );
	}
    }
    /*
     * disconnect stream.
     */
    app = ctx->app;
    if ( keep_connection ) {
        pthread_mutex_lock ( &app->lock );
	tc_detach ( ctx->cnx );
        ctx->req_state = 2; 
        clear_queue ( &ctx->in_queue );
        pthread_mutex_unlock ( &app->lock );
    } else {
        if ( app->multiplexed ) {
        } else {
	    tc_close ( ctx->cnx );
	    ctx->cnx = 0;
        }
        pthread_mutex_lock ( &app->lock );
        ctx->cnx = (tc_socket) 0;
        ctx->req_state = 0;
        clear_queue ( &ctx->in_queue );
        pthread_mutex_unlock ( &app->lock );
        /*
         * Deallocate context.
         */
        dereference_app ( app );
    }
    return 1;
}
