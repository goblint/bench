#ifndef _LINUX_MODULE_H
#define _LINUX_MODULE_H

#include <linux/sched.h>
#include <linux/spinlock.h>
#include <linux/compiler.h>
#include <linux/moduleparam.h>
#include <linux/stringify.h>
#include <linux/stat.h>

#define MODULE_AUTHOR(_author) char _ddv_module_author[] = _author
#define MODULE_LICENSE(_license) char _ddv_module_license[] = _license
#define MODULE_DESCRIPTION(_description) char _ddv_module_description[] = _description
#define MODULE_SUPPORTED_DEVICE(_device) char _ddv_module_supported_device[] = _device
#define MODULE_PARM_DESC(_param, _description) char _ddv_module_param_##_param [] = _description
#define MODULE_ALIAS(_whatever) void
#define MODULE_ALIAS_CHARDEV_MAJOR(_major) int _ddv_module_param_major = _major
#define MODULE_ALIAS_BLOCKDEV_MAJOR(_major) int _ddv_module_param_major = _major
#define MODULE_ALIAS_MISCDEV(_dev) void
#define MODULE_DEVICE_TABLE(type,name) void

#define THIS_MODULE ((struct module *) 0)

struct module {
    int something;
};

#define __MODULE_STRING(x) #x

void __module_get(struct module *module);

#endif
