#ifndef _LINUX_MODULE_PARAMS_H
#define _LINUX_MODULE_PARAMS_H

#include <linux/init.h>
#include <linux/stringify.h>
#include <linux/kernel.h>

#define module_param(var, type, arg) void
#define module_param_named(name, var, type, arg) void
#define module_param_array(name, type, nump, perm) void

#endif
