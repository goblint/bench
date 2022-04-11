#include <ddverify/ddverify.h>
#include <ddverify/satabs.h>
#include <asm/semaphore.h>

// DDV: The count value is ignored because ddverify only supports binary semaphores!
void sema_init(struct semaphore *sem, int val)
{
 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
    sem->init = 1;
    sem->locked = 0;
    __CPROVER_atomic_end();
}

void init_MUTEX(struct semaphore * sem)
{
 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
    sem->init = 1;
    sem->locked = 0;
    __CPROVER_atomic_end();
}

void init_MUTEX_LOCKED(struct semaphore * sem)
{
 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
    sem->init = 1;
    sem->locked = 1;
    __CPROVER_atomic_end();
}

void down(struct semaphore * sem)
{ 
__CPROVER_HIDE:
 
#ifdef DDV_ASSERT_SEMAPHORE
    __CPROVER_atomic_begin();
    assert_context_process();
    __CPROVER_assert(lock->init, "Semaphore is not initialized");
    __CPROVER_atomic_end();
#endif

    do
    {
    	__CPROVER_atomic_begin();
    	if(sem->locked == 0)
	{
		sem->locked = 1;
    		__CPROVER_atomic_end();
		return;
	}
    	__CPROVER_atomic_end();
    }
    while(1);
}

int down_interruptible(struct semaphore * sem)
{
__CPROVER_HIDE:
 
#ifdef DDV_ASSERT_SEMAPHORE
    __CPROVER_atomic_begin();
    assert_context_process();
    __CPROVER_assert(sem->init, "Semaphore is not initialized");
    __CPROVER_atomic_end();
#endif

    do
    {
    	__CPROVER_atomic_begin();
    	if(sem->locked == 0)
	{
		sem->locked = 1;
    		__CPROVER_atomic_end();
		return 0;
	}
	if(nondet_int()){
    		__CPROVER_atomic_end();
		return -1;
	}
		
    	__CPROVER_atomic_end();
    }
    while(1);
}

int down_trylock(struct semaphore * sem)
{
 __CPROVER_HIDE:
    __CPROVER_atomic_begin();

#ifdef DDV_ASSERT_SEMAPHORE
    __CPROVER_assert(sem->init, "Semaphore is not initialized");
#endif

    if (sem->locked == 0) {
      sem->locked = 1;
      __CPROVER_atomic_end();
      return -1;
    }
    __CPROVER_atomic_end();
    return 0;
}

void up(struct semaphore * sem)
{
 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
     assert_context_process();
#ifdef DDV_ASSERT_SEMAPHORE
    __CPROVER_assert(sem->locked, "Unlock a not locked semaphore");
#endif
    sem->locked = 0;
    __CPROVER_atomic_end();
}
