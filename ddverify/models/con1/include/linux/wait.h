#ifndef _LINUX_WAIT_H
#define _LINUX_WAIT_H

#include <linux/config.h>
#include <linux/list.h>
#include <linux/stddef.h>
#include <linux/spinlock.h>
#include <asm/system.h>
#include <asm/current.h>

struct __wait_queue {
    int something;
};
typedef struct __wait_queue wait_queue_t;

struct __wait_queue_head {
    int number_process_waiting;
    int wakeup;

  int init;
};
typedef struct __wait_queue_head wait_queue_head_t;


#define DECLARE_WAITQUEUE(name, tsk) wait_queue_t name
#define DECLARE_WAIT_QUEUE_HEAD(name) wait_queue_head_t name = {    \
                 .number_process_waiting = 0,                       \
                 .wakeup = 0,                                       \
                 .init = 1}


#ifdef DDV_ASSERT_WAIT_QUEUE
#define assert_wait_queue(wq)  __CPROVER_assert((wq)->init, "Wait queue is initialized!")
#else
#define assert_wait_queue(wq)  do {} while(0)
#endif

#define wait_event(wq, condition) 					\
do {									\
	if (condition)	 						\
		break;							\
        do {                                                            \
	    wq.number_process_waiting++;                                \
	    do {                                                        \
	    } while(!wq.wakeup);                                        \
	    if (condition)                                              \
		break;                                                  \
	    do {                                                        \
            } while(wq.wakeup);                                         \
	} while (1);                                                    \
} while (0)


#define wait_event_interruptible(wq, condition)				\
({									\
	int __ret = 0;							\
	__ret;								\
})


#define DEFINE_WAIT(name) wait_queue_t name

// DDV: Body is defined in linux/kernel/wait.c
void init_waitqueue_head(wait_queue_head_t *q);
// DDV: TODO
void prepare_to_wait(wait_queue_head_t *q, wait_queue_t *wait, int state);
// DDV: TODO
void finish_wait(wait_queue_head_t *q, wait_queue_t *wait);

// DDV: Body is defined in linux/kernel/wait.c
void wake_up(wait_queue_head_t *q);
// DDV: Body is defined in linux/kernel/wait.c
void wake_up_all(wait_queue_head_t *q);
// DDV: Body is defined in linux/kernel/wait.c
void wake_up_interruptible(wait_queue_head_t *q);

// DDV: TODO
void add_wait_queue(wait_queue_head_t *q, wait_queue_t * wait);
// DDV: TODO
void add_wait_queue_exclusive(wait_queue_head_t *q, wait_queue_t * wait);
// DDV: TODO
void remove_wait_queue(wait_queue_head_t *q, wait_queue_t * wait);

// DDV: TODO
int waitqueue_active(wait_queue_head_t *q);

// DDV: Body is defined in linux/kernel/wait.c
void sleep_on(wait_queue_head_t *q);
// DDV: Body is defined in linux/kernel/wait.c
void interruptible_sleep_on(wait_queue_head_t *q);
#endif
