#include <ddverify/satabs.h>
#include <linux/spinlock.h>

void spin_lock_init(spinlock_t * lock)
{
    lock->init = 1;
    lock->locked = 0;
}

void spin_lock(spinlock_t * lock)
{
 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
#ifdef DDV_ASSERT_SPINLOCK
    __CPROVER_assert(lock->init, "Spinlock is initialized");
    __CPROVER_assert(!lock->locked, "Lock a locked spinlock");
#endif
    lock->locked = 1;
    __CPROVER_atomic_end();
}

void spin_lock_irqsave(spinlock_t *lock, unsigned long flags)
{
 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
#ifdef DDV_ASSERT_SPINLOCK
    __CPROVER_assert(lock->init, "Spinlock is initialized");
    __CPROVER_assert(!lock->locked, "Lock a locked spinlock");
#endif
    lock->locked = 1;
    __CPROVER_atomic_end();
}

void spin_lock_irq(spinlock_t *lock)
{
 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
#ifdef DDV_ASSERT_SPINLOCK
    __CPROVER_assert(lock->init, "Spinlock is initialized");
    __CPROVER_assert(!lock->locked, "Lock a locked spinlock");
#endif
    lock->locked = 1;
    __CPROVER_atomic_end();
}

void spin_lock_bh(spinlock_t *lock)
{
 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
#ifdef DDV_ASSERT_SPINLOCK
    __CPROVER_assert(lock->init, "Spinlock is initialized");
    __CPROVER_assert(!lock->locked, "Lock a locked spinlock");
#endif
    lock->locked = 1;
    __CPROVER_atomic_end();
}

void spin_unlock(spinlock_t *lock)
{
 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
#ifdef DDV_ASSERT_SPINLOCK
    __CPROVER_assert(lock->locked, "Unlock a not locked spinlock");
#endif
    lock->locked = 0;
}


void spin_unlock_irqrestore(spinlock_t *lock, unsigned long flags)
{
 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
#ifdef DDV_ASSERT_SPINLOCK
    __CPROVER_assert(lock->locked, "Unlock a not locked spinlock");
#endif
    lock->locked = 0;
    __CPROVER_atomic_end();
}

void spin_unlock_irq(spinlock_t *lock)
{
 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
#ifdef DDV_ASSERT_SPINLOCK
    __CPROVER_assert(lock->locked, "Unlock a not locked spinlock");
#endif
    lock->locked = 0;
    __CPROVER_atomic_end();
}

void spin_unlock_bh(spinlock_t *lock)
{
 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
#ifdef DDV_ASSERT_SPINLOCK
    __CPROVER_assert(lock->locked, "Unlock a not locked spinlock");
#endif
    lock->locked = 0;
    __CPROVER_atomic_end();
}
