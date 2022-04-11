#ifndef __LINUX_FILE_H
#define __LINUX_FILE_H

#include <asm/atomic.h>
#include <linux/posix_types.h>
#include <linux/compiler.h>
#include <linux/spinlock.h>
//#include <linux/rcupdate.h>
#include <linux/types.h>

extern void fput(struct file *);
extern struct file * fget(unsigned int fd);

#endif /* __LINUX_FILE_H */
