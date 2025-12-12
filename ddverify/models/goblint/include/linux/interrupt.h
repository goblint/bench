/* interrupt.h */
#ifndef _LINUX_INTERRUPT_H
#define _LINUX_INTERRUPT_H

#include <linux/config.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <asm/ptrace.h>

/*
 * These flags used only by the kernel as part of the
 * irq handling routines.
 *
 * IRQF_DISABLED - keep irqs disabled when calling the action handler
 * IRQF_SAMPLE_RANDOM - irq is used to feed the random generator
 * IRQF_SHARED - allow sharing the irq among several devices
 * IRQF_PROBE_SHARED - set by callers when they expect sharing mismatches to occur
 * IRQF_TIMER - Flag to mark this interrupt as timer interrupt
 */
#define IRQF_DISABLED		0x00000020
#define IRQF_SAMPLE_RANDOM	0x00000040
#define IRQF_SHARED		0x00000080
#define IRQF_PROBE_SHARED	0x00000100
#define IRQF_TIMER		0x00000200
#define IRQF_PERCPU		0x00000400


typedef int irqreturn_t;

#define IRQ_NONE	(0)
#define IRQ_HANDLED	(1)
#define IRQ_RETVAL(x)	((x) != 0)

struct tasklet_struct
{
    atomic_t count;
    void (*func)(unsigned long);
    unsigned long data;

    int init;
};

#define DECLARE_TASKLET(name, func, data) \
  struct tasklet_struct name = { 0, func, data, 1 }

#define DECLARE_TASKLET_DISABLED(name, func, data) \
  struct tasklet_struct name = { 1, func, data, 1 }

// DDV: Body is defined in linux/kernel/softirq.c
void tasklet_schedule(struct tasklet_struct *t);

static inline void tasklet_disable(struct tasklet_struct *t)
{
    t->count++;
}

static inline void tasklet_enable(struct tasklet_struct *t)
{
    t->count++;
}

// DDV: TODO
void tasklet_kill(struct tasklet_struct *t);
// DDV: Body is defined in linux/kernel/softirq.c
void tasklet_init(struct tasklet_struct *t,
		  void (*func)(unsigned long), unsigned long data);

#ifdef OLD_INTERRUPT_HANDLER
typedef irqreturn_t (*irq_handler_t)(int, void *);
#else
typedef irqreturn_t (*irq_handler_t)(int, void *, struct pt_regs *);
#endif

// DDV: Body for this function is defined in linux/kernel/irq/manage.c
int request_irq(unsigned int, irq_handler_t handler,
		       unsigned long, const char *, void *);
// DDV: Body for this function is defined in linux/kernel/irq/manage.c
void free_irq(unsigned int, void *);

// DDV: TODO
unsigned long probe_irq_on(void);
// DDV: TODO
int probe_irq_off(unsigned long);
// DDV: TODO
unsigned int probe_irq_mask(unsigned long);

// DDV: TODO
void cli(void);
// DDV: TODO
void sti(void);
// DDV: TODO
void save_flags(unsigned long x);
// DDV: TODO
void restore_flags(unsigned long x);

#endif
