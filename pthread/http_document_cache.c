/*
 * Manage cache of documents for http server.  Documents are identified uniquely
 * by the file path (ident), representation (e.g. test/plain), and encoding
 * (e.g. 8BIT).  The stored information is therefore ready to be sent to
 * client without any further formatting.
 *
 * Note: Cache blocks only store the pointers to the representation and
 * encoding string supplied by the caller to put_cache.  These strings are
 * assumed to have been permanently allocated by the caller.
 *
 * int http_init_doc_cache ( int slots );
 * int http_invalidate_doc_cache();
 * int http_get_doc_cache ( char *ident, char *rep, char *encoding,
 *		char *buffer, int bufsize, int *data_bytes )
 * int http_put_doc_cache ( char *ident, char *rep, char *encoding,
 *		char *buffer int data_bytes );
 *
 *  Author:	David Jones
 *  Revised:	23-MAR-1994
 *  Revised:	26-MAY-1994		Added bufsize arg. to get_doc_cache().
 *  Revised:	29-JUL-1994		Adjust includes for RTL use.
 */
#include "pthread_1c_np.h"
#include <stdio.h>
#include <stdlib.h>
#include "tutil.h"

#define CACHE_BLOCK_SIZE 4096
struct cache_block {
    struct cache_block *lru_flink, *lru_blink;	/* pointers for LRU list */
    struct cache_block *hsh_flink, *hsh_blink;	/* Hash chain */
    int data_length;				/* Length of document */
    int ident_len;				/* Length of ident string */
    char *rep;					/* MIME representation */
    char *encoding;				/* data transfer type */
    char ident[256];				/* File name */
    char data[CACHE_BLOCK_SIZE];
};
typedef struct cache_block *cache_ptr;
#define NULL_PTR (cache_ptr) 0

static pthread_mutex_t doc_cache;		/* guards hash table and LRU */

static int cache_size = 0;
static int hash_table_size;			/* Length of hash table */
static int hash_mask;				/* Hash function mask */
static cache_ptr *hash_table;			/* hash table for lookups */

static cache_ptr free_list;			/* list of free cache blocks */
static struct cache_block lru_head;		/* Least Recently Used listhead*/
/****************************************************************************/
/*
 * Hashing function for lookups.  Only hash ident portion since multiple
 * representations/encodings will be rare.
 */
static int hash_ident ( char *ident )
{
    int hash, i;
    char *ptr;

    for ( hash = 0, ptr = ident; *ptr; ptr++ ) {
	i = (unsigned) *ptr;
	hash = hash_mask & (i*577 ^ hash*3);
    }
    return hash;
}
/****************************************************************************/
/*  Initialize module.  Pre-allocate cache blocks.
 */
int http_init_doc_cache ( int slots )
{
    int status, i;
    status = INITIALIZE_MUTEX ( &doc_cache );
    /*
     * Allocate and initialize hash table and cache blocks.
     */
    cache_size = slots;
    for ( hash_table_size = 1; hash_table_size < slots; hash_table_size*=2 );
    if ( cache_size == 0 ) return 0;
    hash_mask = hash_table_size - 1;            
    LOCK_C_RTL
    hash_table = malloc ( hash_table_size * sizeof(cache_ptr) );
    free_list = malloc ( cache_size * sizeof(struct cache_block) );
    UNLOCK_C_RTL
    if ( !hash_table ) { cache_size = 0; return 0; }
    for ( i = 0; i < hash_table_size; i++ ) hash_table[i] = NULL_PTR;

    if ( !free_list ) { cache_size = 0; return 0; }
    for ( i = 0; i < cache_size; i++ ) {
	free_list[i].lru_flink = &free_list[i+1];
    }
    free_list[cache_size-1].lru_flink = NULL_PTR;	/* terminate list */
    lru_head.lru_flink = &lru_head;
    lru_head.lru_blink = &lru_head;
    return 1;                  
}                                                  
/****************************************************************************/
int http_invalidate_doc_cache()
{
    int status, i;

    if ( cache_size <= 0 ) return 0;		/* no cache */
    status = pthread_mutex_lock ( &doc_cache );
    if ( status != 0 ) printf("Invalid mutex lock status: %d\n", status );
    for ( i = 0; i < hash_table_size; i++ ) hash_table[i] = NULL_PTR;
    /*
     * Move entire LRU list to the free list (if it is non-empty).
     */
    if ( lru_head.lru_flink != &lru_head ) {
        lru_head.lru_blink->lru_flink = free_list;
        free_list = lru_head.lru_flink;
	lru_head.lru_flink = &lru_head;
	lru_head.lru_blink = &lru_head;
    }
    status = pthread_mutex_unlock ( &doc_cache );
    return 0;
}
/****************************************************************************/
/* Search cache for specified document/representation/encoding and return
 * it if found.  Return value is 1 ro cache hit, 0 for miss.
 */
int http_get_doc_cache ( char *ident, char *rep, char *encoding, 
	char *buffer, int bufsize, int *length ) 
{ 
    int hash_ndx, ident_len, i, copy_len;
    cache_ptr blk;
    char *src;
    if ( cache_size <= 0 ) return 0;		/* no cache available */
    /*
     *  Scan hash chain for this identifier.
     */
    ident_len = tu_strlen ( ident );
    hash_ndx = hash_ident ( ident );
    pthread_mutex_lock ( &doc_cache );
    for ( blk = hash_table[hash_ndx]; blk != NULL_PTR; blk = blk->hsh_flink) {
	/*
	 * We must get match on ident, rep, and encoding to get a 'hit'
	 */
	if ( ident_len != blk->ident_len ) continue;
	if ( tu_strncmp ( ident, blk->ident, ident_len ) != 0 ) continue;
	if ( tu_strncmp ( rep, blk->rep, 100 ) != 0 ) continue;
	if ( tu_strncmp ( encoding, blk->encoding, 100 ) != 0 ) continue;
	/*
	 * Passing the gauntlet above means this is the block be want.
	 * Copy the data, unlock database, and return success status.
         */
	*length = copy_len = blk->data_length;
	if ( *length > bufsize ) break;		/* Too much data for buffer */
	for ( src = blk->data, i = 0; i < copy_len; i++ ) *buffer++ = *src++;
	/*
	 * Move block to front on lru list.
	 */
	blk->lru_flink->lru_blink = blk->lru_blink;
	blk->lru_blink->lru_flink = blk->lru_flink;

	blk->lru_blink = &lru_head;
	blk->lru_flink = lru_head.lru_flink;
	blk->lru_flink->lru_blink = blk;
	blk->lru_blink->lru_flink = blk;
	pthread_mutex_unlock ( &doc_cache );

	return 1;
    }
    /*
     * Falling out of loop means data not in cache.
     */
    pthread_mutex_unlock ( &doc_cache );
    return 0; 
}
/****************************************************************************/
/* Insert data block into cache.  Note that no check for duplicates is made,
 * although properly we should once the database is locked.
 * Note also that rep and encoding are stored as the pointers passed to
 * this routine, so the caller must not change them.
 */
int http_put_doc_cache ( char *ident, char *rep, char *encoding, 
		char *buffer, int length ) 
{ 
    int i, hash_ndx;
    cache_ptr blk;
    char *ptr;

    if ( (cache_size <= 0) || length > CACHE_BLOCK_SIZE ) return 0;
    /*
     * Get cache block to hold new data.  Lock database while manipulating it.
     */
    pthread_mutex_lock ( &doc_cache );
    if ( free_list != NULL_PTR ) {
	/*
	 * Easy case, take block from free list.
	 */
        blk = free_list;
	free_list = blk->lru_flink;

    } else {
	/*
	 * Hard case, Remove oldest block from lru list and it's hash chain.
	 */
	blk = lru_head.lru_blink;
	if ( blk == &lru_head ) {
	    /*  BUG, both free list and lru list empty */
	    printf("Bugcheck, document cache in inconsistent state\n" );
	    pthread_mutex_unlock ( &doc_cache );
	    return 0;
	}
	lru_head.lru_blink = blk->lru_blink;
	blk->lru_blink->lru_flink = &lru_head;

	if ( blk->hsh_blink == NULL_PTR ) {
	    /* Block is first in hash chain, update hash table. */
	    hash_ndx = hash_ident ( blk->ident );
	    hash_table[hash_ndx] = blk->hsh_flink;

	} else {
	    blk->hsh_blink->hsh_flink = blk->hsh_flink;
	}
	if ( blk->hsh_flink != NULL_PTR ) 
			blk->hsh_flink->hsh_blink = blk->hsh_blink;
    }
    /*
     * Initialize block.
     */
    tu_strnzcpy ( blk->ident, ident, sizeof(blk->ident)-1 );
    blk->ident_len = tu_strlen ( blk->ident );
    blk->rep = rep;
    blk->encoding = encoding;
    blk->data_length = length;
    for ( ptr = blk->data, i = 0; i < length; i++ ) *ptr++ = *buffer++;
    /*
     * Insert in lru list and hash table.
     */
    blk->lru_blink = &lru_head;
    blk->lru_flink = lru_head.lru_flink;
    blk->lru_flink->lru_blink = blk;
    blk->lru_blink->lru_flink = blk;

    hash_ndx = hash_ident ( blk->ident );
    blk->hsh_blink = NULL_PTR;			/* always at head of list */
    blk->hsh_flink = hash_table[hash_ndx];
    if ( blk->hsh_flink != NULL_PTR ) {
	blk->hsh_flink->hsh_blink = blk;
    }
    hash_table[hash_ndx] = blk;
    
    pthread_mutex_unlock ( &doc_cache );
    return 1; 
}
                                                      
