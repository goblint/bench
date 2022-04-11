#include <ddverify/satabs.h>
#include <linux/mutex.h>

inline void mutex_init(struct mutex *lock)
{
 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
#ifdef DDV_ASSERT_MUTEX
    __CPROVER_assert(!lock->locked, "Locked mutex must not be reinitialized");
#endif 
    lock->locked = 0;
    lock->init = 1;
    __CPROVER_atomic_end();
}

inline void mutex_lock(struct mutex *lock)
{
 __CPROVER_HIDE:
 
#ifdef DDV_ASSERT_MUTEX
    __CPROVER_atomic_begin();
    assert_context_process();
    __CPROVER_assert(lock->init, "Mutex is not initialized");
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

inline void mutex_unlock(struct mutex *lock)
{
 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
     assert_context_process();
#ifdef DDV_ASSERT_SEMAPHORE
    __CPROVER_assert(lock->locked, "Unlock a not locked mutex");
#endif
    lock->locked = 0;
    __CPROVER_atomic_end();
}
