#ifndef _SYSFS_H_
#define _SYSFS_H_

#include <linux/compiler.h>
#include <asm/atomic.h>

struct kobject;
struct module;

struct attribute {
	const char		* name;
	struct module 		* owner;
	mode_t			mode;
};

struct attribute_group {
	const char		* name;
	struct attribute	** attrs;
};



/**
 * Use these macros to make defining attributes easier. See include/linux/device.h
 * for examples..
 */

#define __ATTR(_name,_mode,_show,_store) { \
	.attr = {.name = __stringify(_name), .mode = _mode, .owner = THIS_MODULE },	\
	.show	= _show,					\
	.store	= _store,					\
}

#define __ATTR_RO(_name) { \
	.attr	= { .name = __stringify(_name), .mode = 0444, .owner = THIS_MODULE },	\
	.show	= _name##_show,	\
}

#define __ATTR_NULL { .attr = { .name = NULL } }

#define attr_name(_attr) (_attr).attr.name

#endif /* _SYSFS_H_ */
