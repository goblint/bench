#ifndef _LINUX_TIME_H
#define _LINUX_TIME_H

#include <linux/types.h>

struct timespec {
	time_t	tv_sec;		/* seconds */
	long	tv_nsec;	/* nanoseconds */
};

struct timeval {
    time_t		tv_sec;		/* seconds */
    suseconds_t	        tv_usec;	/* microseconds */
};


/* Parameters used to convert the timespec values: */
#define MSEC_PER_SEC	1000L
#define USEC_PER_MSEC	1000L
#define NSEC_PER_USEC	1000L
#define NSEC_PER_MSEC	1000000L
#define USEC_PER_SEC	1000000L
#define NSEC_PER_SEC	1000000000L
#define FSEC_PER_SEC	1000000000000000L


void do_gettimeofday(struct timeval *tv);

#endif

