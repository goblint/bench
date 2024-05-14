#include <ddverify/satabs.h>
#include <linux/spinlock.h>

inline void spin_lock_init(spinlock_t * lock)
{
    lock->init = 1;
    lock->locked = 0;
}

inline void spin_lock(spinlock_t * lock)
{
 __CPROVER_HIDE:
 
#ifdef DDV_ASSERT_SPINLOCK
    __CPROVER_atomic_begin();
    __CPROVER_assert(lock->init, "Spinlock is not initialized");
    __CPROVER_atomic_end();
#endif

    do
    {
    	__CPROVER_atomic_begin();
    	if(lock->locked == 0)
	{
		lock->locked = 1;
    		__CPROVER_atomic_end();
		return;
	}
    	__CPROVER_atomic_end();
    }
    while(1);    
}

inline void spin_lock_irqsave(spinlock_t *lock, unsigned long flags)
{
 __CPROVER_HIDE:
 
#ifdef DDV_ASSERT_SPINLOCK
    __CPROVER_atomic_begin();
    __CPROVER_assert(lock->init, "Spinlock is not initialized");
    __CPROVER_atomic_end();
#endif

    do
    {
    	__CPROVER_atomic_begin();
    	if(lock->locked == 0)
	{
		lock->locked = 1;
    		__CPROVER_atomic_end();
		return;
	}
    	__CPROVER_atomic_end();
    }
    while(1);    
}

inline void spin_lock_irq(spinlock_t *lock)
{
 __CPROVER_HIDE:
 
#ifdef DDV_ASSERT_SPINLOCK
    __CPROVER_atomic_begin();
    __CPROVER_assert(lock->init, "Spinlock is not initialized");
    __CPROVER_atomic_end();
#endif

    do
    {
    	__CPROVER_atomic_begin();
    	if(lock->locked == 0)
	{
		lock->locked = 1;
    		__CPROVER_atomic_end();
		return;
	}
    	__CPROVER_atomic_end();
    }
    while(1);
}

inline void spin_lock_bh(spinlock_t *lock)
{
 __CPROVER_HIDE:
 
#ifdef DDV_ASSERT_SPINLOCK
    __CPROVER_atomic_begin();
    __CPROVER_assert(lock->init, "Spinlock is not initialized");
    __CPROVER_atomic_end();
#endif

    do
    {
    	__CPROVER_atomic_begin();
    	if(lock->locked == 0)
	{
		lock->locked = 1;
    		__CPROVER_atomic_end();
		return;
	}
    	__CPROVER_atomic_end();
    }
    while(1);    
}

inline void spin_unlock(spinlock_t *lock)
{
 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
#ifdef DDV_ASSERT_SPINLOCK
    __CPROVER_assert(lock->locked == 1, "Unlock a not locked spinlock");
#endif
    lock->locked = 0;
    __CPROVER_atomic_end();
}

inline void spin_unlock_irqrestore(spinlock_t *lock, unsigned long flags)
{
 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
#ifdef DDV_ASSERT_SPINLOCK
    __CPROVER_assert(lock->locked == 1, "Unlock a not locked spinlock");
#endif
    lock->locked = 0;
    __CPROVER_atomic_end();
}

inline void spin_unlock_irq(spinlock_t *lock)
{
 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
#ifdef DDV_ASSERT_SPINLOCK
    __CPROVER_assert(lock->locked == 1, "Unlock a not locked spinlock");
#endif
    lock->locked = 0;
    __CPROVER_atomic_end();
}

inline void spin_unlock_bh(spinlock_t *lock)
{
__CPROVER_HIDE:
    __CPROVER_atomic_begin();
#ifdef DDV_ASSERT_SPINLOCK
    __CPROVER_assert(lock->locked == 1, "Unlock a not locked spinlock");
#endif
    lock->locked = 0;
    __CPROVER_atomic_end();

}
