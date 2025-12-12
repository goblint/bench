#ifndef _LINUX_KERNEL_H
#define _LINUX_KERNEL_H

/*
 * 'kernel.h' contains some often-used function prototypes etc
 */

#include <ddverify/satabs.h>
#include <linux/bitops.h>
#include <linux/stddef.h>
#include <linux/compiler.h>
#include <asm/byteorder.h>
#include <asm/bug.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define FIELD_SIZEOF(t, f) (sizeof(((t*)0)->f))
#define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))
#define roundup(x, y) ((((x) + ((y) - 1)) / (y)) * (y))

#define	KERN_EMERG	"<0>"	/* system is unusable			*/
#define	KERN_ALERT	"<1>"	/* action must be taken immediately	*/
#define	KERN_CRIT	"<2>"	/* critical conditions			*/
#define	KERN_ERR	"<3>"	/* error conditions			*/
#define	KERN_WARNING	"<4>"	/* warning conditions			*/
#define	KERN_NOTICE	"<5>"	/* normal but significant condition	*/
#define	KERN_INFO	"<6>"	/* informational			*/
#define	KERN_DEBUG	"<7>"	/* debug-level messages			*/

unsigned long simple_strtoul(const char *,char **,unsigned int);
long simple_strtol(const char *,char **,unsigned int);
unsigned long long simple_strtoull(const char *,char **,unsigned int);
long long simple_strtoll(const char *,char **,unsigned int);

int printk(const char * fmt, ...);
int sprintf(char * buf, const char * fmt, ...);
int snprintf(char * buf, size_t size, const char * fmt, ...);

extern int cond_resched(void);

extern int get_option(char **str, int *pint);
extern char *get_options(const char *str, int nints, int *ints);

/* Values used for system_state */
extern enum system_states {
	SYSTEM_BOOTING,
	SYSTEM_RUNNING,
	SYSTEM_HALT,
	SYSTEM_POWER_OFF,
	SYSTEM_RESTART,
	SYSTEM_SUSPEND_DISK,
} system_state;

#define TAINT_PROPRIETARY_MODULE	(1<<0)
#define TAINT_FORCED_MODULE		(1<<1)
#define TAINT_UNSAFE_SMP		(1<<2)
#define TAINT_FORCED_RMMOD		(1<<3)
#define TAINT_MACHINE_CHECK		(1<<4)
#define TAINT_BAD_PAGE			(1<<5)

extern void dump_stack(void);

/*
 * min()/max() macros that also do
 * strict type-checking.. See the
 * "unnecessary" pointer comparison.
 */
#define min(x,y) ({ \
	typeof(x) _x = (x);	\
	typeof(y) _y = (y);	\
	(void) (&_x == &_y);		\
	_x < _y ? _x : _y; })

#define max(x,y) ({ \
	typeof(x) _x = (x);	\
	typeof(y) _y = (y);	\
	(void) (&_x == &_y);		\
	_x > _y ? _x : _y; })

/*
 * ..and if you can't take the strict
 * types, you can specify one yourself.
 *
 * Or not use min/max at all, of course.
 */
#define min_t(type,x,y) \
	({ type __x = (x); type __y = (y); __x < __y ? __x: __y; })
#define max_t(type,x,y) \
	({ type __x = (x); type __y = (y); __x > __y ? __x: __y; })

/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:	the pointer to the member.
 * @type:	the type of the container struct this is embedded in.
 * @member:	the name of the member within the struct.
 *
 */
#define container_of(ptr, type, member) ({			\
        typeof( ((type *)0)->member ) *__mptr = (ptr);	\
        (type *)( (char *)__mptr - offsetof(type,member) );})


#define pr_debug(fmt,arg...) \
	do { } while (0)

#define BUILD_BUG_ON(condition) \
        do { } while (0)

#define BUILD_BUG_ON_ZERO(condition) \
        do { } while (0)


/* Trap pasters of __FUNCTION__ at compile-time */
#define __FUNCTION__ (__func__)

#endif
