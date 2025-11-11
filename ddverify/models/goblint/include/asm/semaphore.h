#ifndef _I386_SEMAPHORE_H
#define _I386_SEMAPHORE_H

struct semaphore {
    int init;
    int locked;
};


#define __SEMAPHORE_INITIALIZER(name, n)				\
{									\
        .init           = 1,                                            \
	.locked		= n				                \
}

#define __DECLARE_SEMAPHORE_GENERIC(name,count) \
	struct semaphore name = __SEMAPHORE_INITIALIZER(name,count)

#define DECLARE_MUTEX(name) __DECLARE_SEMAPHORE_GENERIC(name,0)
#define DECLARE_MUTEX_LOCKED(name) __DECLARE_SEMAPHORE_GENERIC(name,1)

// DDV: Body is defined in linux/kernel/semaphore.c
void sema_init(struct semaphore *sem, int val);
// DDV: Body is defined in linux/kernel/semaphore.c
void init_MUTEX(struct semaphore * sem);
// DDV: Body is defined in linux/kernel/semaphore.c
void init_MUTEX_LOCKED(struct semaphore * sem);
// DDV: Body is defined in linux/kernel/semaphore.c
void down(struct semaphore * sem);
// DDV: Body is defined in linux/kernel/semaphore.c
int down_interruptible(struct semaphore * sem);
// DDV: Body is defined in linux/kernel/semaphore.c
int down_trylock(struct semaphore * sem);
// DDV: Body is defined in linux/kernel/semaphore.c
void up(struct semaphore * sem);

#endif
