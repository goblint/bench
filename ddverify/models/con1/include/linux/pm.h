#ifndef _LINUX_PM_H
#define _LINUX_PM_H

#include <linux/config.h>
#include <linux/list.h>
#include <asm/atomic.h>

typedef struct pm_message {
	int event;
} pm_message_t;

#endif /* _LINUX_PM_H */
