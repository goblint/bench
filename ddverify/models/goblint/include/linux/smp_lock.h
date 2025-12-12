#ifndef __LINUX_SMPLOCK_H
#define __LINUX_SMPLOCK_H

#include <linux/sched.h>
#include <linux/spinlock.h>

spinlock_t kernel_lock;

#define lock_kernel()    spin_lock(&kernel_lock)
#define unlock_kernel()  spin_unlock(&kernel_lock)

#endif /* __LINUX_SMPLOCK_H */
