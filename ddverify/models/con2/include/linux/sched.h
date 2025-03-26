#ifndef _LINUX_SCHED_H
#define _LINUX_SCHED_H

#include <linux/capability.h>
#include <linux/types.h>
#include <linux/jiffies.h>
#include <linux/errno.h>
#include <linux/time.h>
#include <linux/timer.h>
#include <linux/percpu.h>

#include <asm/processor.h>

#include <linux/signal.h>

#define TASK_RUNNING		0
#define TASK_INTERRUPTIBLE	1
#define TASK_UNINTERRUPTIBLE	2
#define TASK_STOPPED		4
#define TASK_TRACED		8

#define TASK_COMM_LEN 16

struct sighand_struct {
    spinlock_t		siglock;
};

struct task_struct {
    long state;	                   /* -1 unrunnable, 0 runnable, >0 stopped */
    pid_t pid;
    char comm[TASK_COMM_LEN];

    sigset_t blocked, real_blocked;

    struct sighand_struct *sighand;
};

#include <asm/current.h>

int signal_pending(struct task_struct *p);

// DDV: Body is defined in linux/kernel/sched.c
void schedule(void);
// DDV: Body is defined in linux/kernel/sched.c
long schedule_timeout(long timeout);
// DDV: TODO
int need_resched(void);

// DDV: TODO
extern int dequeue_signal(struct task_struct *tsk, sigset_t *mask, siginfo_t *info);

// DDV: TODO
void yield(void);

// DDV: No body for this function
void set_current_state(int);

// DDV: TODO
extern int kill_proc(pid_t, int, int);
// DDV: TODO
extern void recalc_sigpending(void);
#endif
