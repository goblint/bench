 /*
 * This Threads-based module manages per-thread heaps for memory
 * allocation/deallocation using routines (tm_malloc, tm_free) that
 * follow standard C malloc/free semantics.
 *
 * Author:	David Jones
 * Revised:	24-SEP-1996	Fix bug in tm_free, was not zeroing pointer when
 *				adding new block to empty free list.
 * Revised:	25-OCT-1996	Fix bug in realloc calls for oversize blocks.
 */
#include <stdio.h>
#include <stdlib.h>

#include "pthread_1c_np.h"
#include "tmemory.h"
/*
 * 4 basic structures used by this modul are:
 *     hdrptr  		Basic memory block header, has pointer to next and limit.
 *     tm_heap_attr_blk
 *	heap		Heap control block
 *	heapref		Heap reference block, used for per-thread allocation.
 */
struct blk_hdr {
    struct blk_hdr *next;
    void *limit;
};
typedef struct blk_hdr *hdrptr;
#define BLK_HDR_SIZE sizeof(struct blk_hdr)

struct heap_master {
    struct heap_master *flink, *blink;	/* links in list */
    pthread_mutex_t lock;		/* for synchonizing changes to lock */
    hdrptr free_chunks;			/* chunks available for sub-allocation*/
    int type;
    int ref_count;			/* number of threads using heap */
    int chunk_size;			/* units are in BLK_HDR_SIZE bytes */
    int delete_pending;			/* if true, delete when ref_count==0 */
    int quota;
};

struct heap_reference {
    struct heap_reference *next;	/* next reference block */
    struct heap_reference *current;	/* Current heap to use */
    struct heap_master *master;
    hdrptr free_list;			/* this threads heap */
    hdrptr chunk_list;			/* blocks borrowed from heap master */
    hdrptr oversize_list;		/* oversize blocks allocated */
};
/*
 * The module uses the following global structures.
 */
static pthread_once_t module_setup = PTHREAD_ONCE_INIT;
static pthread_mutex_t master_lock;
static pthread_key_t heap_ref;			/* Context for heaps used by thread */
static struct heap_master *heap_list;
static struct heap_master *default_heap, initial_heap;
static struct heap_reference *free_ref;	/* Lookaside list of reference blocks */
static void reference_rundown ( struct heap_reference *first );

/*****************************************************************************/
/* One-time routine to initializing the module's global variables.
 */
static void module_init ()
{
    int status;
    /*
     * Create pthread objects.
     */
    default_heap = (struct heap_master *) 0;
    INITIALIZE_MUTEX ( &master_lock );
    status = CREATE_KEY (&heap_ref, (pthread_destructor_t) reference_rundown);
    if ( status != 0 ) return;
    /*
     * Initialize global lists, global data protected by mutex master_lock.
     */
    pthread_mutex_lock ( &master_lock );
    heap_list = (struct heap_master *) 0;
    default_heap = &initial_heap;
    default_heap->flink = default_heap->blink = default_heap;
    default_heap->type = TMEM_TYPE_FIRST_FIT;
    INITIALIZE_MUTEX ( &default_heap->lock );
    default_heap->free_chunks = (hdrptr) 0;
    default_heap->ref_count = 0;
    default_heap->chunk_size = 4096;	/* units are sizeof(struct header) */
    default_heap->delete_pending = 0;
    free_ref = (struct heap_reference *) 0;
    pthread_mutex_unlock ( &master_lock );
}
/*****************************************************************************/
/* Destructor routine for heap_reference key.  Return memory chunks allocated
 * to thread their heap master control blocks.
 */
static void reference_rundown ( struct heap_reference *first )
{
    hdrptr cur, next, blk;
    struct heap_reference  *ref, *last_ref;
    struct heap_master *master;
    /*
     * Process each reference block.
     */
    for ( last_ref = ref = first; ref; ref = ref->next ) {
	/*
	 * Free blocks on oversize list.
	 */
	for ( cur = ref->oversize_list; cur; cur = next ) {
	    next = cur->next;
	    free ( cur );
	}
	/*
	 * Find end of chunk list and return as group to heap master.
	 */
	if ( ref->chunk_list ) {
	    for ( cur = ref->chunk_list; cur->next; cur = cur->next );

	    master = ref->master;
	    pthread_mutex_lock ( &master->lock );
	    cur->next = master->free_chunks;
	    master->free_chunks = ref->chunk_list;
	    --master->ref_count;
	    if ( (master->ref_count == 0) && master->delete_pending ) {
		/*
		 * We are last thread using heap marked for deletion.
		 */
		pthread_mutex_unlock ( &master->lock );
		tm_destroy_heap ( master );
	    } else pthread_mutex_unlock ( &master->lock );
	}
	last_ref = ref;
    }
    /*
     * Put list of reference blocks on the ref block free list.
     */
    pthread_mutex_lock ( &master_lock );
    last_ref->next = free_ref;
    free_ref = first;
    pthread_mutex_unlock ( &master_lock );
}

/*****************************************************************************/
/* Initialize function called by user of module.  Return value is
 * allocation quantum (chunk_size) of default heap or -1 if error.
 */
int tm_initialize()
{
    pthread_once ( &module_setup, module_init );
    if ( !default_heap ) return -1;
    return (default_heap->chunk_size * BLK_HDR_SIZE);
}
/*****************************************************************************/
/* Grab chunk from heap master's pool.
 */
static hdrptr allocate_chunk ( struct heap_master *master,
	struct heap_reference *ref )
{
    hdrptr blk;
    /*
     * Get block from pool or run-time.
     */
    pthread_mutex_lock ( &master->lock );
    blk = master->free_chunks;
    if ( blk ) master->free_chunks = blk->next;
    pthread_mutex_unlock ( &master->lock );
    if ( !blk ) {
	/*
	 * Get new chunk for run-time system, add extra bytes for chunk list
	 * header.
	 */
	LOCK_C_RTL
	blk = (hdrptr) malloc ( BLK_HDR_SIZE * (master->chunk_size+1) );
	UNLOCK_C_RTL
	if ( !blk ) return blk;
    }
    /*
     * Add block to thread's chunk list.
     */
    blk->next = ref->chunk_list;
    ref->chunk_list = blk;

    return &blk[1];
}
/*****************************************************************************/
/* Allocate a reference block from the global free list, grow by 8 blocks
 * if list empty.  The current ref cell in the thread's heap_ref context key 
 * is set to the address of the reference.
 */
static struct heap_reference *create_reference ( 
	struct heap_reference *ref_list,
	struct heap_master *master )
{
    struct heap_reference *ref;
    if ( ref_list ) {
	/*
	 * Search for existing reference with target master heap and simply 
	 * update current field if found.
	 */
	for ( ref = ref_list; ref; ref = ref->next ) {
	    if ( ref->master == master ) {
		ref_list->current = ref;
		return ref;
	    }
	}
    }
    /*
     * Allocate free reference block from global list.
     */
    pthread_mutex_lock ( &master_lock );
    ref = free_ref;
    if ( !ref ) {
	/*
	 * free list empty, expand it and take last block.
	 */
	int i;
	LOCK_C_RTL
	free_ref = (struct heap_reference *) malloc 
			( 8 * sizeof(struct heap_reference) );
	UNLOCK_C_RTL
	for ( i = 0; i < 6; i++ ) free_ref[i].next = &free_ref[i+1];
	free_ref[6].next = free_ref[7].next = (struct heap_reference *) 0;
	ref = &free_ref[7];
    } else free_ref = ref->next;	/* remove from list */
    pthread_mutex_unlock ( &master_lock );
    /*
     * Initialize the reference block.
     */
    if ( !ref_list ) {		/* first reference block used by thread */
	pthread_setspecific ( heap_ref, ref );
	ref_list = ref;
    }
    ref_list->current = ref;
    ref->next = (struct heap_reference *) 0;
    ref->current = ref;
    ref->master = master;
    ref->free_list = (hdrptr) 0;
    ref->chunk_list = (hdrptr) 0;
    ref->oversize_list = (hdrptr) 0;

    return ref;
}
/*****************************************************************************/
/* Primary allocation routine
 *
 * Argument:
 *     int size		Number of bytes to allocate.
 * Return value:
 *     (void *) 	Address of allocated block.
 */
void *tm_malloc ( int size )
{
    struct heap_reference *ref;
    struct heap_master *master;
    hdrptr cur, prev, chunk;
    int x;
    /*
     * locate current heap.
     */
    GET_SPECIFIC(heap_ref, ref);
    if ( !ref ) {
	ref = create_reference ( ref, default_heap );
    }
    ref = ref->current;
    master = ref->master;
    if ( ref->master->type ) {
    }
    /*
     * first fit algorithm.
     */
    x = (size - 1 + (2*BLK_HDR_SIZE)) / BLK_HDR_SIZE;
    if ( x > master->chunk_size ) {
	cur = (hdrptr) malloc ( x*BLK_HDR_SIZE );
	cur->next = ref->oversize_list;
	cur->limit = (void *) cur;	/* flag as special allocation */
	ref->oversize_list = cur;
	
	return (void *) &cur[1];
    }

    prev = (hdrptr) 0;
    for ( cur = ref->free_list; cur; cur = cur->next ) {
	if ( cur->limit >= (void *) &cur[x] ) {
	    /* Found block big enough to hold request */
	    if ( cur->limit < (void *) &cur[x+3] ) {
		/*
		 * Current free blocks size doesn't leave enough remaining
		 * to have sub-allocation worth while, take whole block
		 * and remove from list
		 */
		if ( prev ) prev->next = cur->next;
		else ref->free_list = cur->next;
	    } else {
		/*
		 * sub-allocate from tail of this region.
		 */
		prev = cur;
		cur = ((hdrptr) prev->limit) - x;
		cur->limit = prev->limit;
		prev->limit = (void *) cur;
	    }
	    cur->next = cur;
	    return (void *) &cur[1];
	}
	prev = cur;
    }
    /*
     * Block of adequate size, not found.
     */
    chunk = allocate_chunk ( master, ref );
    if ( !chunk ) return (void *) chunk;
    chunk->limit = (void *)(chunk + master->chunk_size - x);
    prev = (hdrptr) 0;
    for ( cur = ref->free_list; cur; cur = cur->next ) {
	if ( cur > chunk ) break; else prev = cur;
    }
    chunk->next = cur;
    if ( prev ) prev->next = chunk;
    else ref->free_list = chunk;

    cur = (hdrptr) chunk->limit;
    cur->next = cur;
    cur->limit = (void *) (cur + x);
    return (void *) &cur[1];
}
/*************************************************************************/
/* Routine for freeing block allocated by tm_malloc().
 */
void tm_free ( void *ublk )
{
    hdrptr blk, blk_end, cur, prev;
    void *limit;
    struct heap_reference *ref;
    struct heap_master *master;
    /*
     * Get out heap info.
     */
    GET_SPECIFIC ( heap_ref, ref );
    if ( !ref ) {
	fprintf(stderr,"Invalid call to tm_free()\n");
	return;
    }
    ref = ref->current;
    if ( ref->master->type ) {
        master = ref->master;
    }
    /*
     * Compute pointer and do sanity checks.
     */
    if ( !ublk ) return;
    blk = ((hdrptr) ublk) - 1;
    if ( blk->limit == (void *) blk ) {
	/* 
	 * Request was an oversize allocation, remove from oversize list
	 */
	prev = (hdrptr) 0;
	for ( cur = ref->oversize_list; cur; cur = cur->next ) {
	    if ( cur == blk ) {
		if ( prev ) {
		    prev->next = cur->next;
		} else {
		    ref->oversize_list = cur->next;
		}
		free ( blk );
		return;
	    }
	    prev = cur;
	}
	fprintf(stderr,"tm_free error, block not found on oversize list\n");
	return;
    } else if ( blk->limit < (void *) blk ) {
	fprintf(stderr,"Deallocation failure, corrupted limit field\n");
	return;
    }
    blk_end = (hdrptr) blk->limit;
    /*
     * Do trivial cases of empty free list or first free block at
     * higher address.
     */
    if ( !ref->free_list ) {
	/*
	 * Free list was empty.
	 */
	blk->next = (hdrptr) 0;
	ref->free_list = blk;
	return;
    } else if ( ref->free_list > blk ) {
	/*
	 * Current block will become first block in list.
	 */
	if ( blk->limit == (hdrptr) ref->free_list ) {
	    /*
	     * Prepend to existing first block.
	     */
	    blk->next = ref->free_list->next;
	    blk->limit = ref->free_list->limit;
	} else {
	    /*
	     * make new first block.
	     */
	    blk->next = ref->free_list;
	}
	ref->free_list = blk;
	return;
    }
    /*
     * Scan free list for first block with higher address.
     */
    prev = ref->free_list;
    for ( cur = ref->free_list->next; cur; cur = cur->next ) if ( cur > blk ) {
	/*
	 * Check for consolidating with previous and/or current block.
	 */
	int mode;
	mode = 0;
	if ( prev->limit == (void *) blk ) mode += 1;  /* merge with prev */
	if ( blk->limit == (void *) cur ) mode += 2;   /* merge with cur */

	switch ( mode ) {
	    case 0:	/* insert new block in list */
		prev->next = blk;
		blk->next = cur;
		break;
	    case 1:	/* append to previous block */
		prev->limit = blk->limit;
		break;
	    case 2:	/* prepend to current block */
		prev->next = blk;
		blk->next = cur->next;
		blk->limit = cur->limit;
		break;
	    case 3:	/* consolidate prev, blk, cur */
		prev->next = cur->next;
		prev->limit = cur->limit;
		break;
	}
	return;
    } else prev = cur;
    /*
     * Prev points to last block, append to it or add new block.
     */
     if ( prev->limit == (void *) blk ) {
	prev->limit = blk->limit;
    } else {
	blk->next = prev->next;
	prev->next = blk;
    }
}

/*************************************************************************/
/*
 */
void *tm_calloc ( int size )
{
    int *blk, i, words;

    blk = (int *) tm_malloc ( size );
    if ( !blk ) return (void *) blk;
    words = (size+(sizeof(int)-1))/sizeof(int);
    for ( i = 0; i < words; i++ ) blk[i] = 0;
    return (void *) blk;
}

void *tm_realloc ( void *old, int new_size )
{
    int *blk, i, words, x, *ptr;
    hdrptr hdr;
    /*
     * examine old block header to determine if oversize or not.
     */
    hdr = ((hdrptr) old) - 1;
    if ( (void *) hdr == hdr->limit ) {
	/*
	 * Oversize block, manually remove and realloc.
	 */
	hdrptr prev, cur;
	struct heap_reference *ref;
	struct heap_master *master;
        /*
	 * Get heap control block so we can access oversize list.
	 */
        GET_SPECIFIC ( heap_ref, ref );
        if ( !ref ) {
	    fprintf(stderr,"Invalid call to tm_realloc()\n");
	    return;
	}
	ref = ref->current;
	if ( ref->master->type ) {
    	    master = ref->master;
	}
	/*
	 * Scan oversize list for old block.
	 */
	prev = (hdrptr) 0;
	for ( cur = ref->oversize_list; cur; cur = cur->next ) {
	    if ( cur == hdr ) {
		if ( prev ) {
		    prev->next = cur->next;
		} else {
		    ref->oversize_list = cur->next;
		}
		/*
		 * realocate block and insert new on oversize list.
		 * Note: the new block may be smaller than chunk_size but we
		 * must use realloc() since we don't know the size of the
		 * original block
		 */
		x = (new_size - 1 + (2*BLK_HDR_SIZE)) / BLK_HDR_SIZE;
		cur = (hdrptr) realloc ( hdr, x*BLK_HDR_SIZE );
		cur->next = ref->oversize_list;
		cur->limit = (void *) cur;
		ref->oversize_list = cur;
		return (void *) &cur[1];
	    }
	    prev = cur;
	}
	fprintf(stderr,"tm_realloc error, block not found on oversize list\n");
	return (void *) 0;
    } else if ( hdr->limit < (void *) hdr ) {
	fprintf(stderr,"Deallocation failure, corrupted limit field\n");
	return (void *) 0;

    } else { 
	/*
	 * Old block comes from chunk store.  Allocate new and copy.
	 */
	blk = (int *) tm_malloc ( new_size );
	if ( !blk ) return (void *) blk;
	if ( old ) {
	    words = (new_size+(sizeof(int)-1))/sizeof(int);
	    hdr = ((hdrptr) old) - 1;
	    for (i = 0, ptr = old; (i < words) &&
		(ptr < (int *) hdr->limit); i++) blk[i] = *ptr++;
	    tm_free ( old );
	}
    }
    return (void *) blk;
}
/*****************************************************************************/
/* Change the current heap from which tm_malloc allocates blocks.
 */
tm_heap_id tm_change_heap ( tm_heap_id heap_id )
{
    struct heap_master *target, *previous;
    struct heap_reference *ref;
    int delete_pending;
    /*
     * Search known heaps for requested heap, search will ignore heaps
     * being  run down.
     */
    if ( !heap_id ) target = default_heap;
    else {
        pthread_mutex_lock ( &master_lock );
        target = (struct heap_master *) heap_id;
	for ( previous = default_heap->flink;
		(previous != target); previous = previous->flink )
	    if ( previous == default_heap ) break;
        pthread_mutex_unlock ( &master_lock );
	if ( previous != target ) return (tm_heap_id) 0;
	pthread_mutex_lock ( &target->lock );
	delete_pending = target->delete_pending;
	pthread_mutex_unlock ( &target->lock );
	if ( delete_pending ) return (tm_heap_id) 0;
    }
    /*
     * Search current thread for matching heap.
     */
    GET_SPECIFIC ( heap_ref, ref );
    previous = ref->current->master;
    ref = create_reference ( ref, target );
    return (tm_heap_id) previous;
}
/*****************************************************************************/
/* Create a heap and return a handle for it.
 */
tm_heap_id tm_create_heap ( int type, tm_heap_attr attr )
{
    struct heap_master *master;
    /*
     * Allocate and initialize master block.
     */
    LOCK_C_RTL
    master = (struct heap_master *) malloc ( sizeof(struct heap_master) );
    UNLOCK_C_RTL
    if ( !master ) return master;
    master->type = type;
    master->free_chunks = (hdrptr) 0;
    master->ref_count = master->delete_pending = 0;
    INITIALIZE_MUTEX ( &master->lock );

    if ( type == TMEM_TYPE_FIRST_FIT ) {
	master->chunk_size = (attr->ff.chunk_size -1  + BLK_HDR_SIZE) /
		BLK_HDR_SIZE;
	master->quota = attr->ff.max_alloc;
    }
    /*
     * Make new block part of master list.
     */
    pthread_mutex_lock ( &master_lock );
    master->flink = default_heap;
    master->blink = default_heap->blink;
    default_heap->blink = master;
    master->blink->flink = master;
    pthread_mutex_unlock ( &master_lock );

    return (tm_heap_id) master;
}
/*****************************************************************************/
/* Delete heap.  Return value:
 *	0 	Heap deleted
 *	>0	Heap has non-zero reference count (value returned), marked for
 *		delete.
 *	-1	Error.
 */
int tm_destroy_heap ( tm_heap_id heap_id )
{
    struct heap_master *target, *previous;
    struct heap_reference *ref;
    hdrptr cur, next;
    int ref_count;
    /*
     * Search known heaps for requested heap.
     */
    target = (struct heap_master *) heap_id;
    if ( !target ) return -1;				/* invalid heap id */
    else if ( target == default_heap ) return -1;
    else {
        pthread_mutex_lock ( &master_lock );
	for ( previous = default_heap->flink;
		previous != target; previous = previous->flink )
	    if ( previous == default_heap ) break;
        pthread_mutex_unlock ( &master_lock );
	if ( previous != target ) return -1;
    }
    /*
     * Rundown heap.
     */
    pthread_mutex_lock ( &target->lock );
    target->delete_pending = 1;		/* prevents additional increase */
    ref_count = target->ref_count;
    pthread_mutex_unlock ( &target->lock );

    if ( ref_count == 0 ) {
	/*
	 * Unhook from master list.
	 */
	pthread_mutex_lock ( &master_lock );
	target->flink->blink = target->blink;
	target->blink->flink = target->flink;
	pthread_mutex_unlock ( &master_lock );
	/*
	 * Free resources.
	 */
	LOCK_C_RTL
	if ( target->free_chunks ) {
	    for ( cur = target->free_chunks; cur->next; cur = next ) {
		next = cur->next;
		free ( cur );
	    }
	}
	free ( target );
	UNLOCK_C_RTL
    }
    return ref_count;
}
