#include <linux/wait.h>

inline void init_waitqueue_head(wait_queue_head_t *q)
{
  q->init = 1;
}

inline void wake_up(wait_queue_head_t *q)
{
#ifdef DDV_ASSERT_WAIT_QUEUE
 __CPROVER_HIDE:
    __CPROVER_assert(q->init, "Wait queue is initialized!");
#endif
}

inline void wake_up_all(wait_queue_head_t *q)
{
#ifdef DDV_ASSERT_WAIT_QUEUE
 __CPROVER_HIDE:
    __CPROVER_assert(q->init, "Wait queue is initialized!");
#endif
}

inline void wake_up_interruptible(wait_queue_head_t *q)
{
#ifdef DDV_ASSERT_WAIT_QUEUE
 __CPROVER_HIDE:
    __CPROVER_assert(q->init, "Wait queue is initialized!");
#endif
}

inline void sleep_on(wait_queue_head_t *q)
{
#ifdef DDV_ASSERT_WAIT_QUEUE
 __CPROVER_HIDE:
    __CPROVER_assert(q->init, "Wait queue is initialized!");
#endif
}

inline void interruptible_sleep_on(wait_queue_head_t *q)
{
#ifdef DDV_ASSERT_WAIT_QUEUE
 __CPROVER_HIDE:
    __CPROVER_assert(q->init, "Wait queue is initialized!");
#endif
}
