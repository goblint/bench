#ifndef _LINUX_INIT_H
#define _LINUX_INIT_H

#include <linux/config.h>
#include <linux/compiler.h>

#define module_init(_function) int (* _ddv_tmp_init)(void) = _function
#define module_exit(_function) void (* _ddv_tmp_exit)(void) = _function

#define __init
#define __initdata
#define __exitdata
#define __exit

#define __devinit
#define __devinitdata
#define __devexit
#define __devexitdata
#define __devexit_p(x) x

#define __setup(str, func) int (* _ddv_setup_function)(char *) = func

#endif
