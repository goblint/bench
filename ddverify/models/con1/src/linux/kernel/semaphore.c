#include <ddverify/ddverify.h>
#include <ddverify/satabs.h>
#include <asm/semaphore.h>

// DDV: The count value is ignored because ddverify only supports binary semaphores!
inline void sema_init(struct semaphore *sem, int val)
{
    sem->init = 1;
    sem->locked = 0;
}

inline void init_MUTEX(struct semaphore * sem)
{
    sem->init = 1;
    sem->locked = 0;
}

inline void init_MUTEX_LOCKED(struct semaphore * sem)
{
    sem->init = 1;
    sem->locked = 1;
}

inline void down(struct semaphore * sem)
{
 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
    assert_context_process();
#ifdef DDV_ASSERT_SEMAPHORE
    __CPROVER_assert(sem->init, "Semaphore is initialized");
    __CPROVER_assert(!sem->locked, "Lock a locked semaphore");
#endif
    sem->locked = 1;
    __CPROVER_atomic_end();
}

inline int down_interruptible(struct semaphore * sem)
{
  if (nondet_int()) {
     __CPROVER_HIDE:
     __CPROVER_atomic_begin();
     assert_context_process();
#ifdef DDV_ASSERT_SEMAPHORE
    __CPROVER_assert(sem->init, "Semaphore is initialized");
     __CPROVER_assert(!sem->locked, "Lock a locked semaphore");
#endif
     sem->locked = 1;
     __CPROVER_atomic_end();

     return 0;
  } else {
      return -1;
  }
}

inline int down_trylock(struct semaphore * sem)
{
 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
    assert_context_process();

#ifdef DDV_ASSERT_SEMAPHORE
    __CPROVER_assert(sem->init, "Semaphore is initialized");
#endif

    if (sem->locked == 0) {
      sem->locked = 1;
      return 0;
    } else {
      return 1;
    }

    __CPROVER_atomic_end();

    return 0;
}

inline void up(struct semaphore * sem)
{
 __CPROVER_HIDE:
     assert_context_process();
#ifdef DDV_ASSERT_SEMAPHORE
    __CPROVER_assert(sem->locked, "Unlock a not locked semaphore");
#endif
    sem->locked = 0;
}
