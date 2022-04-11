#ifndef _LINUX_DELAY_H
#define _LINUX_DELAY_H

extern unsigned long loops_per_jiffy;

#include <asm/delay.h>


#ifndef mdelay
#define mdelay(n) do {} while(0)
#endif

#ifndef ndelay
#define ndelay(x) do {} while(0)
#endif

// DDV: This function does not need a body!
void msleep(unsigned int msecs);
// DDV: This function does not need a body!
unsigned long msleep_interruptible(unsigned int msecs);

#endif /* defined(_LINUX_DELAY_H) */
