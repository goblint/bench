#ifndef __LINUX_GFP_H
#define __LINUX_GFP_H

#include <linux/mmzone.h>
#include <linux/stddef.h>
//#include <linux/linkage.h>
#include <linux/config.h>

/*
 * Action modifiers - doesn't change the zoning
 *
 * __GFP_REPEAT: Try hard to allocate the memory, but the allocation attempt
 * _might_ fail.  This depends upon the particular VM implementation.
 *
 * __GFP_NOFAIL: The VM implementation _must_ retry infinitely: the caller
 * cannot handle allocation failures.
 *
 * __GFP_NORETRY: The VM implementation must not retry indefinitely.
 */
#define __GFP_WAIT	((__force gfp_t)0x10u)	/* Can wait and reschedule? */
#define __GFP_HIGH	((__force gfp_t)0x20u)	/* Should access emergency pools? */
#define __GFP_IO	((__force gfp_t)0x40u)	/* Can start physical IO? */
#define __GFP_FS	((__force gfp_t)0x80u)	/* Can call down to low-level FS? */
#define __GFP_COLD	((__force gfp_t)0x100u)	/* Cache-cold page required */
#define __GFP_NOWARN	((__force gfp_t)0x200u)	/* Suppress page allocation failure warning */
#define __GFP_REPEAT	((__force gfp_t)0x400u)	/* Retry the allocation.  Might fail */
#define __GFP_NOFAIL	((__force gfp_t)0x800u)	/* Retry for ever.  Cannot fail */
#define __GFP_NORETRY	((__force gfp_t)0x1000u)/* Do not retry.  Might fail */
#define __GFP_NO_GROW	((__force gfp_t)0x2000u)/* Slab internal usage */
#define __GFP_COMP	((__force gfp_t)0x4000u)/* Add compound page metadata */
#define __GFP_ZERO	((__force gfp_t)0x8000u)/* Return zeroed page on success */
#define __GFP_NOMEMALLOC ((__force gfp_t)0x10000u) /* Don't use emergency reserves */
#define __GFP_HARDWALL   ((__force gfp_t)0x20000u) /* Enforce hardwall cpuset memory allocs */

#define __GFP_BITS_SHIFT 20	/* Room for 20 __GFP_FOO bits */
#define __GFP_BITS_MASK ((__force gfp_t)((1 << __GFP_BITS_SHIFT) - 1))

/* if you forget to add the bitmask here kernel will crash, period */
#define GFP_LEVEL_MASK (__GFP_WAIT|__GFP_HIGH|__GFP_IO|__GFP_FS| \
			__GFP_COLD|__GFP_NOWARN|__GFP_REPEAT| \
			__GFP_NOFAIL|__GFP_NORETRY|__GFP_NO_GROW|__GFP_COMP| \
			__GFP_NOMEMALLOC|__GFP_HARDWALL)

/* GFP_ATOMIC means both !wait (__GFP_WAIT not set) and use emergency pool */
#define GFP_ATOMIC	(__GFP_HIGH)
#define GFP_NOIO	(__GFP_WAIT)
#define GFP_NOFS	(__GFP_WAIT | __GFP_IO)
#define GFP_KERNEL	(__GFP_WAIT | __GFP_IO | __GFP_FS)
#define GFP_USER	(__GFP_WAIT | __GFP_IO | __GFP_FS | __GFP_HARDWALL)
#define GFP_HIGHUSER	(__GFP_WAIT | __GFP_IO | __GFP_FS | __GFP_HARDWALL | \
			 __GFP_HIGHMEM)


// DDV: Body defined in linux/mm/page_alloc.c
unsigned long __get_free_pages(gfp_t gfp_mask, unsigned int order);
// DDV: Body defined in linux/mm/page_alloc.c
unsigned long __get_free_page(gfp_t gfp_mask);
// DDV: Body defined in linux/mm/page_alloc.c
unsigned long get_zeroed_page(gfp_t gfp_mask);

// DDV: No body required
void free_pages(unsigned long addr, unsigned int order);
// DDV: No body required
void free_page(unsigned long addr);

// DDV: Body defined in linux/mm/page_alloc.c
static struct page *alloc_pages_node(int nid, gfp_t gfp_mask,
				     unsigned int order);
// DDV: Body defined in linux/mm/page_alloc.c
struct page * alloc_pages(gfp_t gfp_mask, unsigned int order);
// DDV: Body defined in linux/mm/page_alloc.c
struct page * alloc_page(gfp_t gfp_mask);

#endif
