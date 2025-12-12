#ifndef __LINUX_SPINLOCK_H
#define __LINUX_SPINLOCK_H

#include <linux/stringify.h>
#include <linux/spinlock_types.h>

// DDV: Bodies for all spinlock-functions are defined in linux/kernel/spinlock.c

void spin_lock_init(spinlock_t *);
void spin_lock(spinlock_t *);
void spin_lock_irqsave(spinlock_t *, unsigned long);
void spin_lock_irq(spinlock_t *);
void spin_lock_bh(spinlock_t *);

void spin_unlock(spinlock_t *);
void spin_unlock_irqrestore(spinlock_t *, unsigned long);
void spin_unlock_irq(spinlock_t *);
void spin_unlock_bh(spinlock_t *);

#endif /* __LINUX_SPINLOCK_H */
