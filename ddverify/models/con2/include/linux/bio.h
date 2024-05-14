#ifndef __LINUX_BIO_H
#define __LINUX_BIO_H

#include <linux/highmem.h>

struct bio_vec {
    struct page	        *bv_page;
    unsigned int	bv_len;
    unsigned int	bv_offset;
};

struct bio_set;
struct bio;
typedef int (bio_end_io_t) (struct bio *, unsigned int, int);
typedef void (bio_destructor_t) (struct bio *);

struct bio {
    sector_t	        bi_sector;

    struct bio		*bi_next;	/* request queue link */
    struct block_device	*bi_bdev;
    unsigned long	bi_flags;	/* status, command, etc */
    unsigned long	bi_rw;	

    unsigned short	bi_vcnt;
    unsigned short	bi_idx;

    /* Number of segments in this BIO after
     * physical address coalescing is performed.
     */
    unsigned short		bi_phys_segments;

    unsigned int	bi_size;
    struct bio_vec	*bi_io_vec;
    
    bio_end_io_t	*bi_end_io;

    void		*bi_private;
};

/*
 * bio flags
 */
#define BIO_UPTODATE	0	/* ok after I/O completion */
#define BIO_RW_BLOCK	1	/* RW_AHEAD set, and read/write would block */
#define BIO_EOF		2	/* out-out-bounds error */
#define BIO_SEG_VALID	3	/* nr_hw_seg valid */
#define BIO_CLONED	4	/* doesn't own data */
#define BIO_BOUNCED	5	/* bio is a bounce bio */
#define BIO_USER_MAPPED 6	/* contains user pages */
#define BIO_EOPNOTSUPP	7	/* not supported */
#define bio_flagged(bio, flag)	((bio)->bi_flags & (1 << (flag)))

/*
 * top 4 bits of bio flags indicate the pool this bio came from
 */
#define BIO_POOL_BITS		(4)
#define BIO_POOL_OFFSET		(BITS_PER_LONG - BIO_POOL_BITS)
#define BIO_POOL_MASK		(1UL << BIO_POOL_OFFSET)
#define BIO_POOL_IDX(bio)	((bio)->bi_flags >> BIO_POOL_OFFSET)	

/*
 * bio bi_rw flags
 *
 * bit 0 -- read (not set) or write (set)
 * bit 1 -- rw-ahead when set
 * bit 2 -- barrier
 * bit 3 -- fail fast, don't want low level driver retries
 * bit 4 -- synchronous I/O hint: the block layer will unplug immediately
 */
#define BIO_RW		0
#define BIO_RW_AHEAD	1
#define BIO_RW_BARRIER	2
#define BIO_RW_FAILFAST	3
#define BIO_RW_SYNC	4


#define bio_iovec_idx(bio, idx)	(&((bio)->bi_io_vec[(idx)]))
#define bio_iovec(bio)		bio_iovec_idx((bio), (bio)->bi_idx)
#define bio_page(bio)		bio_iovec((bio))->bv_page
#define bio_offset(bio)		bio_iovec((bio))->bv_offset
#define bio_sectors(bio)	((bio)->bi_size >> 9)
//#define bio_cur_sectors(bio)	(bio_iovec(bio)->bv_len >> 9)
#define bio_data(bio)		(page_address(bio_page((bio))) + bio_offset((bio)))
#define bio_barrier(bio)	((bio)->bi_rw & (1 << BIO_RW_BARRIER))
#define bio_sync(bio)		((bio)->bi_rw & (1 << BIO_RW_SYNC))
#define bio_failfast(bio)	((bio)->bi_rw & (1 << BIO_RW_FAILFAST))
#define bio_rw_ahead(bio)	((bio)->bi_rw & (1 << BIO_RW_AHEAD))
#define bio_rw_meta(bio)	((bio)->bi_rw & (1 << BIO_RW_META))

/*
 * drivers should not use the __ version unless they _really_ want to
 * run through the entire bio and not just pending pieces
 */
#define __bio_for_each_segment(bvl, bio, i, start_idx)			\
	for (bvl = bio_iovec_idx((bio), (start_idx)), i = (start_idx);	\
	     i < (bio)->bi_vcnt;					\
	     bvl++, i++)

#define bio_for_each_segment(bvl, bio, i)				\
	__bio_for_each_segment(bvl, bio, i, (bio)->bi_idx)

void * __bio_kmap_atomic(struct bio *, int, enum km_type);
void __bio_kunmap_atomic(char *buffer, enum km_type);

void bio_endio(struct bio *, unsigned int, int);
//#define bio_cur_sectors(bio)	(bio_iovec(bio)->bv_len >> 9)
int bio_cur_sectors(struct bio *);

#endif /* __LINUX_BIO_H */
