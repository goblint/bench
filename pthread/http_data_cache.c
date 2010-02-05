/*
 * This module provides very low level routines for managing a thread-safe
 * cache of named record sequences.
 *
 * Each cache item control block (struct cache_item) always resides on one
 * of 3 lists:
 *    active_list	Item is being accessed (tcache_acces()) by one or 
 *			more threads.  This list is a circular bi-directional
 *			linked list.
 *
 *    lru_list		item is not being accesed by  any threads and
 *			therefore is a candidate for scavenging to recover
 *			memory.  This list is a circular bi-directional
 *			linked list, lru_list.flink points to item
 *			least recently moved from active_list.
 *
 *    free_list		Item structure is not used and is available for
 *			immediate allocation.  This list is a singly-linked
 *			list accessed as a LIFO queue.
 *
 *  The items on the active list and lru list are linked in to a hash table
 *  that expedites searching for entries by name/type.  They may also have
 *  associated records sequences.
 *
 *  To avoid deadlocks, the mutexes must be obtained in the following order:
 *      cache_item_mutex, cache_chunk_mutex
 *  
 * Author:	David Jones
 * Revised:	18-AUG-1997	Fixed bug in free_cache_item, call
 *				mark_item_deleted to remove from hash chain.
 * Revised:	20-AUG-1997	Added 'scan' functions.
 * Revsied:	15-NOV-1997	Add tcache_delete_writelocked() function.
 * Revised:	23-DEC-1997	Increased default hash table size, support
 *				configurable maxrec (chunk size).
 */
#include <stdio.h>
#include <stdlib.h>
#include "pthread_1c_np.h"
#include "tutil.h"
#include <string.h>
/*
 * Define non-opaque forms for pointers and include prototype definitions.
 */
#define tcache_item_ptr struct cache_item *
#define tcache_rec_ptr struct cache_rec *
#include "data_cache.h"
/*
 * The cache_item struct is the main entity for controlling a cache entry.
 * A cache entry is always in 1 of 5 states (indicated by state field):
 *   -1 - Entry not valid, on free list (free list is singly linked)
 *    0 - Entry on LRU list, no active references.
 *    1 - Entry on active list, ref_count = current readers.
 *    2 - Entry on active list with 1 writer accessing (ref_count=1).
 *    3 - Entry on active list with delete pending.  Entry will be rundown
 *	  and placed on free list.
 *
 * An entry on the LRU or active lists is also linked into the hash table
 * used for lookups unless it is in state 3 (delete pending).
 */
struct cache_rec {
    struct cache_rec *next;
    long size;
    char data[sizeof(long)];		/* variable sized */
};
struct cache_item {
    struct cache_item *flink, *blink;
    struct cache_item *next_hash;	/* hash chain for lookups */
    struct cache_chunk *first_chunk;	/* First allocated chunk */
    struct cache_chunk *last_chunk;
    struct cache_rec *first_rec, *last_rec;	/* data records. */
    int state;				/* 0-free, 1-readlock, 2-writelocked */
    int hash_value;			/* index for hash table */
    int type;
    int ref_count;			/* Number of 'open' accesses */
    char name[TCACHE_MAX_NAME];
};

static int max_data;			/* default alloc. limit */
/*
 * The following global structures are protected by the cache_item_lock
 * mutex.
 */
static pthread_mutex_t cache_item_lock;
static struct tcache_context master_cache;
static struct cache_item cache_entries;		/* holds entries */
static struct cache_item active_list;		/* open entries */
static struct cache_item lru_list;		/* non-open entry */
static struct cache_item *free_list;
static int item_stats[8];		/* [0] access attempts */
					/* [1] access success - active */
					/* [2] access success - LRU */
					/* [3] creates */
					/* [4] blocks */
					/* [5] allocation failures */
					/* [6] chunks allocated to entries */

static int hash_table_size;			/* must be power of 2 */
static int hash_mask;
static int hash_entry_count;
#ifndef DEFAULT_HTBL_SIZE
#define DEFAULT_HTBL_SIZE 64			/* must be power of 2 */
#endif
static struct cache_item **hash_table, *default_hash_table[DEFAULT_HTBL_SIZE];
/*
 * The cache's memory is managed with allocation units known as chunks with
 * the following global structures protected by the cache_chunk_lock mutex.
 */
static pthread_mutex_t cache_chunk_lock;
struct cache_chunk {
    struct cache_chunk *next;		/* next chunk in list */
    int used, remaining;		/* Tracks sub-allocation */
    char data[sizeof(struct cache_rec)-sizeof(long)];
};
static struct cache_chunk *free_chunk;
static char *chunk_space;
static int chunk_struct_size;		/* 'real' sizeof cache_chunk struct */
static int chunk_data_size;		/* 'real' size of cache_chunk.data */
static int override_max_recsize=0;
static int chunk_limit, chunks_used;
static int chunk_stats[8];		/* [0] allocation attempts */
					/* [1] copy of chunks_used */
					/* [2] copy of chunk_limit */
					/* [3] allocation failures */
					/* [4] free_item assigned to empty list */
					/* [5] free_item assigned to non-emtpy */
					/* [6] free_item added to free_list */
/****************************************************************************/
static void init_cache_item ( char *name, int type, struct cache_item *item )
{
    item->type = type;
    tu_strnzcpy ( item->name, name, sizeof(item->name)-1 );
}
static struct cache_chunk *alloc_chunk ( int quota )
{
    struct cache_chunk *chunk;
    pthread_mutex_lock ( &cache_chunk_lock );
    chunk_stats[0]++;			/* count alloc requests */
    if ( free_chunk ) {
	chunk = free_chunk;
	free_chunk = chunk->next;
    } else if ( chunk_limit > chunks_used ) {
	chunk = (struct cache_chunk *) chunk_space;
	chunk_space = chunk_space + chunk_struct_size;
	chunks_used++;
    } else {
	/* no chunks available */
	chunk_stats[3]++;
	pthread_mutex_unlock ( &cache_chunk_lock );
	return (struct cache_chunk *) 0;
    }
    pthread_mutex_unlock ( &cache_chunk_lock );
    chunk->next = (struct cache_chunk *) 0;
    chunk->used = 0;
    chunk->remaining = quota;
    return chunk;
}

static struct cache_rec *alloc_rec ( struct cache_item *item, int length,
	int *reason )
{
    struct cache_chunk *cur_chunk;
    struct cache_rec *crec;
    int alloc_size;
    /*
     * See if new block can be put into current last chunk or we need a new
     * one.  Round allocate granularity up to pointer size.
     */
    alloc_size = length+sizeof(struct cache_rec)-sizeof(long);
    alloc_size = (alloc_size+sizeof(void *)-1) & (~(sizeof(void *)-1));
    cur_chunk = item->last_chunk;
    if ( !cur_chunk ) {
	/*
	 * Allocate first chunk.  Quota for the chunk list is calculated
	 * for special objects and max_data for user objects.  For special
	 * items assume roughly at least 1 chunk needs to be allocated per item.
	 */
	item->first_chunk = item->last_chunk = alloc_chunk (
	    (item->type == TCACHE_TYPE_CACHE) ? 
		(chunk_limit-2)*(12+sizeof(struct cache_item)) : max_data);
	cur_chunk = item->first_chunk;
	if ( !cur_chunk ) { 
	    *reason = TCACHE_FAILURE; return (struct cache_rec *) 0; 
	} else if ( item->type  == TCACHE_TYPE_CACHE ) {
		item_stats[6]++;	/* count overhead chunks */
	}
    }
    if ( cur_chunk->remaining < alloc_size ) {
	cur_chunk->remaining = -1;	/* force subsequent allocs to fail */
	*reason = TCACHE_OVERRUN;
	return (struct cache_rec *) 0;
    } 
    if ( alloc_size + cur_chunk->used > chunk_data_size ) {
	/*
	 * Add new chunk.  Ensure user didn' specify unsatisfiable size.
	 */
	if ( alloc_size > chunk_data_size ) {
	    *reason = TCACHE_FAILURE; return (struct cache_rec *) 0;
	}
	cur_chunk->next = alloc_chunk(cur_chunk->remaining);
	if ( !cur_chunk->next ) { 
	   *reason = TCACHE_FAILURE; return (struct cache_rec *) 0;
	}
	item->last_chunk = cur_chunk->next;
	cur_chunk = cur_chunk->next;
    }
    /*
     * Append record to end of chunk and insert in item's record chain.
     */
    crec = (struct cache_rec *) &cur_chunk->data[cur_chunk->used];
    cur_chunk->used += alloc_size;
    cur_chunk->remaining = cur_chunk->remaining - alloc_size;
    crec->next = (struct cache_rec *) 0;
    crec->size = length;

    if ( item->first_rec == (struct cache_rec *) 0 ) {
	item->first_rec = crec;
    } else {
	item->last_rec->next = crec;
    }
    item->last_rec = crec;
    return crec;
}
/****************************************************************************/
/* The following static functions assume caller has locked the cache_item_mutex.
 *   mark_item_deleted		Set state=3 and remove item from hash table
 *   alloc_cache_item		Allocate item from free list or LRU list.
 *   free_cache_item		Move item from LRU or active list to free list,
 *				deallocating/reassigning its chunks.
 */
static void mark_item_deleted ( struct cache_item *item )
{
    struct cache_item *blk;
    item->state = 3;
    blk = hash_table[item->hash_value];
    if ( blk == item ) {		/* first in list, remove */
	hash_table[item->hash_value] = item->next_hash;
	--hash_entry_count;
    } else {
        while ( blk ) {
	    if ( blk->next_hash == item ) {
		blk->next_hash = item->next_hash; 
		--hash_entry_count;
		break;
	    }
	    blk = blk->next_hash;
	}
    }
}

static struct cache_item *alloc_cache_item ( )
{
    struct cache_item *new_item;
    struct cache_rec *rec;
    int status;

    new_item = free_list;
    if ( new_item ) free_list = new_item->flink;
    else {
	/* grow the cache_entries and get  new next rec. */
	rec = alloc_rec ( &cache_entries, sizeof(struct cache_item), &status );
	if ( rec ) new_item = (struct cache_item *) &rec->data[0];
	else if ( lru_list.flink != &lru_list ) {
	    /*
	     * Cache memory fully allocated, take oldest item from LRU list.
	     */
	    new_item = lru_list.flink;
	    lru_list.flink = new_item->flink;
	    new_item->flink->blink = &lru_list;
	    /*
	     * Remove from hash chain.
	     */
	    mark_item_deleted ( new_item );
	    /*
	     * Free chunks allocated to this item (separate mutex).
	     */
	    if ( new_item->first_chunk ) {
		pthread_mutex_lock ( &cache_chunk_lock );
		new_item->last_chunk->next = free_chunk;
		free_chunk = new_item->first_chunk;
		pthread_mutex_unlock ( &cache_chunk_lock );
	    }
	} else new_item = (struct cache_item *) 0;	/* outta luck */
    }
    return new_item;
}

static void free_cache_item ( struct cache_item *item, 
	struct cache_item *assignee )
{
    /*
     * Return data chunks used (if any).
     */
    if ( item->first_chunk ) {
	pthread_mutex_lock ( &cache_chunk_lock );
	if ( assignee ) {
	    /* Caller is freeing item because it has dire need for more space.
	     * Assign the first (and probably only) chunk of the freed item
	     * to the end of the assignee's chunk list.
	     */
	    if ( assignee->first_chunk ) {
		chunk_stats[5]++;
		item->first_chunk->remaining = assignee->last_chunk->remaining;
		assignee->last_chunk->next = item->first_chunk;
	    } else {
		/* Assignee has empty chunk list */
		chunk_stats[4]++;
		item->first_chunk->remaining = max_data;
		assignee->first_chunk = item->first_chunk;
	    }
	    assignee->last_chunk = item->first_chunk;
	    item->first_chunk = item->first_chunk->next;
	    if ( !item->first_chunk ) 
		item->last_chunk = (struct cache_chunk *) 0;
	    assignee->last_chunk->next = (struct cache_chunk *) 0;
	    assignee->last_chunk->used = 0;

	}
	if ( item->first_chunk ) {
	    chunk_stats[6]++;
	    item->last_chunk->next = free_chunk;
	    free_chunk = item->first_chunk;
	}
	pthread_mutex_unlock ( &cache_chunk_lock );
	item->first_chunk = item->last_chunk = (struct cache_chunk *) 0;
    }
    /*
     * Remove from current circular list and push item onto free list
     */
    if ( item->state != 3 ) mark_item_deleted ( item );	
    item->flink->blink = item->blink;
    item->blink->flink = item->flink;

    item->state = -1;
    item->flink = free_list;
    free_list = item;
}
/*****************************************************************************/
/* Define hash function for determining initial hash table entry.
 * We assume string has been upcased and that hash table is valid.
 */
static int hash_name ( int type, char *name )
{
    int hash, i;
    char *ptr;

    for ( hash = type, ptr = name; *ptr; ptr++ ) {
	i = (unsigned) *ptr;
	hash = hash_mask & (i*577 ^ hash*3);
    }
    return hash;
}
/****************************************************************************/
/* non-advertised routine to get statistics counters, optionally reseting. */
void tcache_get_counters ( int item[8], int chunk[8], int zero )
{
    int i;
    pthread_mutex_lock ( &cache_item_lock );
    for ( i=0; i < 8; i++ ) item[i] = item_stats[i];
    if ( zero ) for ( i=0; i < 8; i++ ) item_stats[i] = 0;
    pthread_mutex_unlock ( &cache_item_lock );
    pthread_mutex_lock ( &cache_chunk_lock );
    for ( i = 0; i < 8; i++ ) chunk[i] = chunk_stats[i];
    if ( zero ) for ( i = 0; i < 8; i++ ) chunk_stats[i] = 0;
    chunk[1] = chunks_used;
    chunk_stats[1] = chunks_used;
    chunk_stats[2] = chunk_limit;
    pthread_mutex_unlock ( &cache_chunk_lock );
}
/****************************************************************************/
int tcache_set_max_recsize ( int rec_size )
{
    if ( rec_size < 4096 ) {
	override_max_recsize = 4096;
    } else {
	override_max_recsize = (rec_size+sizeof(long)-1) & (~(sizeof(long)-1));
   }
   return override_max_recsize;
}
/****************************************************************************/
int tcache_init ( int size, int data_limit )
{
    int alloc_size, i;
    /*
     * Allocate structures used for managing chunks, chunk_struct_size
     * may be configurable in future.  Round up to quadword.
     */
    if ( override_max_recsize > 0 ) chunk_data_size = override_max_recsize;
    else chunk_data_size = TCACHE_MAX_RECSIZE;
    chunk_data_size = chunk_data_size + sizeof(free_chunk->data);
    if ( TCACHE_MAX_RECSIZE < 4096 ) chunk_data_size = 4096 +
		sizeof(free_chunk->data);
    chunk_data_size = (chunk_data_size+sizeof(long)-1) & 
		(~(sizeof(long)-1));
    chunk_struct_size = sizeof(struct cache_chunk) + chunk_data_size -
		sizeof(free_chunk->data);
    chunk_limit = (size+chunk_struct_size-1)/ chunk_struct_size;
    chunks_used = 0;
    chunk_space = (char *) malloc ( chunk_limit * chunk_struct_size );
    if ( !chunk_space ) { chunk_limit = 0; return TCACHE_FAILURE; }
    max_data = data_limit;
    free_chunk = (struct cache_chunk *) 0;
     INITIALIZE_MUTEX ( &cache_chunk_lock );
    /*
     * Initialize DECthreads synchronizaation objects.
     */
    INITIALIZE_MUTEX ( &cache_item_lock );
    /*
     * Initialize cache.
     */
    active_list.flink = active_list.blink = &active_list;
    lru_list.flink = lru_list.blink = &lru_list;
    active_list.type = TCACHE_TYPE_CACHE;
    tu_strcpy ( active_list.name, "active_list" );
    active_list.ref_count = 1;
    cache_entries.type = TCACHE_TYPE_CACHE;
    tu_strcpy ( cache_entries.name, "INDEX" );
    cache_entries.ref_count = 1;
    cache_entries.first_chunk = cache_entries.last_chunk = 
		(struct cache_chunk *) 0;
    cache_entries.first_rec = cache_entries.last_rec = (struct cache_rec *) 0;
    master_cache.cache_item = &cache_entries;
    master_cache.next_rec = (tcache_rec_ptr) 0;
    /*
     * Initialize hash table, assume 2 chunks/entry is typical.
     */
    for ( hash_table_size = DEFAULT_HTBL_SIZE; hash_table_size*2 < chunk_limit;
	hash_table_size *= 2 );
    hash_table = (struct cache_item **) 0;
    if ( hash_table_size > DEFAULT_HTBL_SIZE ) hash_table = 
	(struct cache_item **) malloc ( hash_table_size *
		sizeof(struct cache_item *) );
    if ( !hash_table ) {
	/* Small table or allocation failure, fallback to default */
	hash_table_size = DEFAULT_HTBL_SIZE;
	hash_table = default_hash_table;
    }
    hash_entry_count = 0;
    hash_mask = hash_table_size - 1;
    for ( i = 0; i < hash_table_size; i++ ) 
	hash_table[i] = (struct cache_item *) 0;
    /*
     * Initialize statistics counters.
     */
    for ( i = 0; i < 8; i++ ) item_stats[i] = 0;
    for ( i = 0; i < 8; i++ ) chunk_stats[i] = 0;
    chunk_stats[1] = chunks_used;
    chunk_stats[2] = chunk_limit;

    return TCACHE_SUCCESS;
}
/****************************************************************************/
/* Allocate record of size length at end of cache entry's chunk chain,
 * possibly extending the chain.
 */
int tcache_put ( tcache_ctxptr ctx, void *rec, int length )
{
    struct cache_item *item;
    struct cache_rec *crec;
    int status;
    /*
     * Locate cache block being referred to by user's ctx struct.
     */
    item = ctx->cache_item;

    crec = alloc_rec ( item, length, &status );
    if ( !crec ) {
	/*
	 * Out of space.
	 */
	if ( status == TCACHE_FAILURE ) {
	    /*
	     * Trim an entry from the LRU list and re-try allocation.
	     */
	    pthread_mutex_lock ( &cache_item_lock );
	    if ( lru_list.flink != &lru_list ) {
		free_cache_item ( lru_list.flink, item );
	    }
	    pthread_mutex_unlock ( &cache_item_lock );
	    crec = alloc_rec ( item, length, &status );
	}
	if ( !crec ) return status;
    }
    ctx->next_rec = crec;		/* shortcut to last record added */
    memcpy ( crec->data, rec, length );
    return TCACHE_SUCCESS;
}
/****************************************************************************/
int tcache_get ( tcache_ctxptr ctx, void **next_rec, int *length )
{
    struct cache_rec *crec;
    /*
     * Locate next being referred to by user's ctx struct and extract data.
     */
    crec = ctx->next_rec;
    if ( !crec ) return TCACHE_FAILURE;
    ctx->next_rec = crec->next;
    *next_rec = (void *) &crec->data[0];
    *length = crec->size;
    return TCACHE_SUCCESS;
}
/****************************************************************************/
int tcache_clear ( tcache_ctxptr ctx )
{
    struct cache_item *item;
    struct cache_rec *crec;
    /*
     * Locate cache block being referred to by user's ctx struct.
     */
    item = ctx->cache_item;
    if ( item->state != 2 ) return TCACHE_FAILURE;
    if ( item->first_chunk ) {
        pthread_mutex_lock ( &cache_chunk_lock );
	item->last_chunk->next = free_chunk;
	free_chunk = item->first_chunk;
        pthread_mutex_unlock ( &cache_chunk_lock );
	item->first_chunk = item->last_chunk = (struct cache_chunk *) 0;
    }
    item->first_rec = item->last_rec = (struct cache_rec *) 0;
    return TCACHE_SUCCESS;
}
/****************************************************************************/
int tcache_deaccess ( tcache_ctxptr ctx, int delete_flag )
{
    struct cache_item *item;
    struct cache_rec *crec;
    /*
     * Locate cache block being referred to by user's ctx struct.
     */
    item = ctx->cache_item;
    pthread_mutex_lock ( &cache_item_lock );
    item->ref_count--;
    if ( delete_flag ) {
	/*
	 * mark item for delete and remove from hash chain.  Subsequent
	 * accesses on this name/type will cause a new instance to be
	 * created.
	 */
	if ( item->state != 3 ) mark_item_deleted ( item );
    }
    if ( item->ref_count <= 0 ) {
	/*
	 * No more references to this item, move to tail of lru or free list
	 */
	if ( item->state == 3 ) {
	    free_cache_item ( item, (struct cache_item *) 0 );
	} else {
	    /*
	     * Move item from active list to tail of lru list.
	     */
	    item->flink->blink = item->blink;
	    item->blink->flink = item->flink;	/* remove from active list */

	    item->blink = lru_list.blink;
	    item->flink = &lru_list;
	    lru_list.blink->flink = item;
	    lru_list.blink = item;		/* insert on LRU list done */
	    item->state = 0;
	}
    }
    pthread_mutex_unlock ( &cache_item_lock );
    return TCACHE_SUCCESS;
}
/*****************************************************************************/
int tcache_access ( int type, char *name, 
	tcache_ctxptr ctx, void **last_rec, int *length )
{
    int hash_value;
    struct cache_item *item;
    char test_name[TCACHE_MAX_NAME];
    tu_strnzcpy ( test_name, name, sizeof(test_name)-1 );
#ifndef CASE_SENSITIVE
    tu_strupcase ( test_name, test_name );
#endif
    /*
     * lookup name in hash table.
     */
    hash_value = hash_name ( type, test_name );
    pthread_mutex_lock ( &cache_item_lock );
    item_stats[0]++;
    for ( item= hash_table[hash_value]; item; item = item->next_hash ) {
	if ( item->type == type ) if ( tu_strncmp ( test_name, item->name,
		TCACHE_MAX_NAME ) == 0 ) break;
    }
    if ( item ) {
	/*
	 * Item found, bump rec count to prevent deletion if no other
	 * accessors.
	 */
	if ( item->state == 0 ) {
	    /*
	     * Move item from lru list to active list.
	     */
	    if ( item->ref_count != 0 ) {
		/* BUGCHECK, items on free list should always have 0 referers */
		printf("BUGCHECK, non-zero ref_count on free list item\n");
	    }
	    item_stats[2]++;		/* count LRU hits */
	    item->ref_count = 1;
	    item->state = 1;		/* Mark as being read. */
	    item->flink->blink = item->blink;
	    item->blink->flink = item->flink;
	    item->flink = active_list.flink;
	    item->blink = &active_list;
	    active_list.flink->blink = item;
	    active_list.flink = item;
	} else if ( item->state == 1 ) {
	    item_stats[1]++;		/* count concurrent accesses */
	    item->ref_count++;
	} else {
	    /*
	     * Item is being written (2) or deleted (3), fail lookup.
	     */
	    item_stats[4]++;		/* count blocked */
	    pthread_mutex_unlock ( &cache_item_lock );
	    return TCACHE_ACCESS_BLOCKED;
	}
    } else {
	/*
	 * Item not found, allocate.
	 */
	item = alloc_cache_item();
	if ( !item ) {
	    item_stats[5]++;
	    pthread_mutex_unlock ( &cache_item_lock );
	    return TCACHE_ACCESS_FAILURE;
	}
	item_stats[3]++;		/* count creates */
	item->first_chunk = item->last_chunk = (struct cache_chunk *) 0;
	item->first_rec = item->last_rec = (struct cache_rec *) 0;
	item->hash_value = hash_value;
	item->type = type;
	tu_strcpy ( item->name, test_name );
	item->state = 2;
	item->ref_count = 1;
	/*
	 * Place item on active list. and hash chain;
	 */
	item->flink = active_list.flink;
	item->blink = &active_list;
	active_list.flink->blink = item;
	active_list.flink = item;

	item->next_hash = hash_table[hash_value];
	hash_table[hash_value] = item;
	hash_entry_count++;
    }
    pthread_mutex_unlock ( &cache_item_lock );
    /*
     * Initialize callers context for reading or writing.
     */
    ctx->cache_item = item;
    ctx->next_rec = item->first_rec;
    if ( item->state == 2 ) {
	*length = 0;
	*last_rec = (void *) 0;
	return TCACHE_ACCESS_CREATED;
    } else {  /* item->state == 1 */
	if ( item->last_rec ) {
            *last_rec = &item->last_rec->data[0];
	    *length = item->last_rec->size;
	} else {
	    *last_rec = (void *) 0;
	    *length = -1;
	}
    }
    return TCACHE_ACCESS_ACCESSED;
}
/**************************************************************************/
/* Mark active list items opened for write for delete, removing them from 
 * hash table so they become invisible.
 */
int tcache_delete_writelocked()
{
    int i;
    struct cache_item *blk;
    pthread_mutex_lock ( &cache_item_lock );
    for ( blk = active_list.flink; blk != &active_list; blk = blk->flink ) {
	if ( blk->state == 2 ) mark_item_deleted ( blk );
    }
    pthread_mutex_unlock ( &cache_item_lock );
    return 1;
}
/**************************************************************************/
/* Mark all cache entries for delete.  The hash table is cleared so all
 * entries effectively become hidden and the active list of cache
 * items is set to state 3.  The items on the LRU list will then get 
 * scavenged on demand
 */
int tcache_delete_all()
{
    int i;
    struct cache_item *blk;
    pthread_mutex_lock ( &cache_item_lock );
    /* 
     * clear hash table. 
     */
    for ( i = 0; i < hash_table_size; i++ ) 
	hash_table[i] = (struct cache_item *) 0;
    hash_entry_count = 0;
    /*
     * scan active list and mark items for delete.
     */
    for ( blk = active_list.flink; blk != &active_list; blk = blk->flink ) {
	blk->state = 3;		/* delete on final deaccess */
    }
    pthread_mutex_unlock ( &cache_item_lock );
    return 1;
}
/******************************************************************************/
/* The following functions are provided for diagnostic purposes and must
 * be used with care since the cache_item mutex is locked for extended
 * periods.  Return value is 1 on success and 0 when no more entries.
 */
int tcache_scan_entries ( tcache_ctxptr ctx, int *type, char **name,
	int *state, int *ref_count, void **last_rec, int *lr_length )
{
    tcache_rec_ptr rec;
    tcache_item_ptr item;
    if ( !ctx->cache_item ) {
	/* Initial call */
	pthread_mutex_lock ( &cache_item_lock );
	ctx->cache_item = &cache_entries;
	ctx->next_rec = cache_entries.first_rec;
    }
    rec = ctx->next_rec;
    if ( rec ) {
	/*
	 * For the special cache_entries item, the records are the cache
	 * entry structures.
	 */
	if ( rec != ctx->cache_item->last_rec ) ctx->next_rec = rec->next;
	else ctx->next_rec = (tcache_rec_ptr) 0;

	item = (tcache_item_ptr) rec->data;
	if ( rec->size != sizeof(struct cache_item) ) {
	    /* bugcheck */
	    fprintf ( stderr, "tcache_scan_entries found illegal record\n");
	    return 0;
	}
	*state = item->state;
	*type = item->type;
	*ref_count = item->ref_count;
	*name = item->name;
	/*
	 * Access to the last_rec field really ought to be synchronized.
	 */
	if ( item->state >= 0 && item->state != 2 && item->last_rec ) {
	    *last_rec = (void *) item->last_rec->data;
	    *lr_length = item->last_rec->size;
	} else {
	    *last_rec = "";
	    *lr_length = 0;
	}
    } else {
	return 0;
    }
    return 1;
}

void tcache_end_scan ( tcache_ctxptr ctx )
{
    pthread_mutex_unlock ( &cache_item_lock );
    ctx->cache_item = (tcache_item_ptr) 0;
}
