#ifndef _ASM_GENERIC_BUG_H
#define _ASM_GENERIC_BUG_H

#include <linux/compiler.h>
#include <linux/config.h>

#define BUG_ON(condition) __CPROVER_assume(condition)

#endif
