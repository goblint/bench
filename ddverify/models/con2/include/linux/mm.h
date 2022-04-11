#ifndef _LINUX_MM_H
#define _LINUX_MM_H

#include <linux/sched.h>
#include <linux/errno.h>
#include <linux/capability.h>

#include <linux/gfp.h>
#include <linux/fs.h>
#include <linux/mutex.h>
#include <linux/mm_types.h>

#include <asm/page.h>

void *page_address(struct page *page);

#endif /* _LINUX_MM_H */
