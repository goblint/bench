/*
 * workqueue.h --- work queue handling for Linux.
 */

#ifndef _LINUX_WORKQUEUE_H
#define _LINUX_WORKQUEUE_H

#include <linux/timer.h>
//#include <linux/linkage.h>
#include <linux/bitops.h>

struct work_struct {
    unsigned long pending;
    void (*func)(void *);
    void *data;

    int init;
};

#define DECLARE_WORK(n, f, d)					\
	struct work_struct n = {                                \
           .func = (f),                                         \
           .data = (d),                                         \
           .init = 1,                                           \
        }

/*
 * initialize a work-struct's func and data pointers:
 */
#define PREPARE_WORK(_work, _func, _data)			\
	do {							\
		(_work)->func = _func;				\
		(_work)->data = _data;				\
                (_work)->init = 1;                              \
	} while (0)

/*
 * initialize all of a work-struct:
 */
#define INIT_WORK(_work, _func, _data)				\
	do {							\
		PREPARE_WORK((_work), (_func), (_data));	\
	} while (0)

// DDV: Body for this function is defined in linux/kernel/workqueue.c
int schedule_work(struct work_struct *work);
// DDV: TODO
void flush_scheduled_work(void);

#endif
