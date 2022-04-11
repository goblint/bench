#include <ddverify/satabs.h>
#include <linux/mutex.h>

void mutex_init(struct mutex *lock)
{
 __CPROVER_HIDE:
#ifdef DDV_ASSERT_MUTEX
    __CPROVER_assert(!lock->locked, "Locked mutex must not be reinitialized");
#endif 
    lock->locked = 0;
    lock->init = 1;
}

void mutex_lock(struct mutex *lock)
{
 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
    assert_context_process();
#ifdef DDV_ASSERT_MUTEX
    __CPROVER_assert(lock->init, "Mutex is initialized");
    __CPROVER_assert(!lock->locked, "Lock a locked mutex");
#endif
    lock->locked = 1;
    __CPROVER_atomic_end();
}

void mutex_unlock(struct mutex *lock)
{
 __CPROVER_HIDE:
    assert_context_process();
#ifdef DDV_ASSERT_MUTEX
    __CPROVER_assert(lock->locked, "Unlock a not locked mutex");
#endif
    lock->locked = 0;
}
