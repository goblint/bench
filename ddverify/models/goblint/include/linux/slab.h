#ifndef _LINUX_SLAB_H
#define	_LINUX_SLAB_H

#include <linux/gfp.h>
#include <linux/types.h>

// DDV: TODO
void kfree(const void *);
// DDV: Body is defined in linux/mm/slab.c
void *kmalloc(size_t size, gfp_t flags);
// DDV: Body is defined in linux/mm/slab.c
void *kzalloc(size_t size, gfp_t flags);
// DDV: TODO
unsigned int ksize(const void *);

#endif
