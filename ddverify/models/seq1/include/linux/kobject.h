/*
 * kobject.h - generic kernel object infrastructure.
 *
 * Copyright (c) 2002-2003	Patrick Mochel
 * Copyright (c) 2002-2003	Open Source Development Labs
 *
 * This file is released under the GPLv2.
 *
 * 
 * Please read Documentation/kobject.txt before using the kobject
 * interface, ESPECIALLY the parts about reference counts and object
 * destructors. 
 */

#ifndef _KOBJECT_H_
#define _KOBJECT_H_


#include <linux/types.h>
#include <linux/list.h>
#include <linux/sysfs.h>
#include <linux/compiler.h>
#include <linux/spinlock.h>
//#include <linux/rwsem.h>
//#include <linux/kref.h>
#include <linux/kernel.h>
#include <linux/wait.h>
#include <asm/atomic.h>

struct kobject {
  int something;
};

#endif /* _KOBJECT_H_ */
