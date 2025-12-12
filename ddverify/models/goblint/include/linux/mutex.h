/*
 * Mutexes: blocking mutual exclusion locks
 *
 * started by Ingo Molnar:
 *
 *  Copyright (C) 2004, 2005, 2006 Red Hat, Inc., Ingo Molnar <mingo@redhat.com>
 *
 * This file contains the main data structure and API definitions.
 */
#ifndef __LINUX_MUTEX_H
#define __LINUX_MUTEX_H

#include <linux/list.h>
#include <linux/spinlock_types.h>
//#include <linux/linkage.h>
//#include <linux/lockdep.h>

#include <asm/atomic.h>

struct mutex {
    int locked;
    int init;
};

#define __MUTEX_INITIALIZER(lockname) \
        { .locked = 0, .init = 1 }

#define DEFINE_MUTEX(mutexname) \
	struct mutex mutexname = __MUTEX_INITIALIZER(mutexname)

// DDV: Body for this function is defined in linux/kernel.mutex.c
void mutex_init(struct mutex *lock);
// DDV: Body for this function is defined in linux/kernel.mutex.c
void mutex_lock(struct mutex *lock);
// DDV: Body for this function is defined in linux/kernel.mutex.c
void mutex_unlock(struct mutex *lock);

#endif
