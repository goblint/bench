#ifndef _I386_CURRENT_H
#define _I386_CURRENT_H

//#include <linux/thread_info.h>
#include <linux/sched.h>

struct task_struct;

struct task_struct *get_current(void);
 
#define current get_current()

#endif /* !(_I386_CURRENT_H) */

