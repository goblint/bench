/*
 * MixCom Watchdog: A Simple Hardware Watchdog Device
 * Based on Softdog driver by Alan Cox and PC Watchdog driver by Ken Hollis
 *
 * Author: Gergely Madarasz <gorgo@itc.hu>
 *
 * Copyright (c) 1999 ITConsult-Pro Co. <info@itc.hu>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version
 * 2 of the License, or (at your option) any later version.
 *
 * Version 0.1 (99/04/15):
 *		- first version
 *
 * Version 0.2 (99/06/16):
 *		- added kernel timer watchdog ping after close
 *		  since the hardware does not support watchdog shutdown
 *
 * Version 0.3 (99/06/21):
 *		- added WDIOC_GETSTATUS and WDIOC_GETSUPPORT ioctl calls
 *
 * Version 0.3.1 (99/06/22):
 *		- allow module removal while internal timer is active,
 *		  print warning about probable reset
 *
 * Version 0.4 (99/11/15):
 *		- support for one more type board
 *
 * Version 0.5 (2001/12/14) Matt Domsch <Matt_Domsch@dell.com>
 *              - added nowayout module option to override CONFIG_WATCHDOG_NOWAYOUT
 *
 * (2015/06/23) Markus Kusano <mukusano@vt.edu>
 *    Modified to be handled by abstract interpreter
 */
//#include <assert.h>
#include <pthread.h>
#include <stdbool.h>
#include <errno.h>

#define VERSION "0.5"

int mixcomwd_ioports[] = { 0x180, 0x280, 0x380, 0x000 };

#define MIXCOM_WATCHDOG_OFFSET 0xc10
#define MIXCOM_ID 0x11
#define FLASHCOM_WATCHDOG_OFFSET 0x4
#define FLASHCOM_ID 0x18

unsigned long mixcomwd_opened; /* long req'd for setbit --RR */

int watchdog_port;
int mixcomwd_timer_alive;
// markus: userspace timers are not modeled
//DEFINE_TIMER(mixcomwd_timer, NULL, 0, 0);
char expect_close;

// markus: model of userspace buffer passed to mixconwd_write
char mixconwd_write_buf;

// markus: manually set kernel params
#define WATCHDOG_NOWAYOUT 0
int nowayout = WATCHDOG_NOWAYOUT;
//module_param(nowayout, int, 0);
//MODULE_PARM_DESC(nowayout, "Watchdog cannot be stopped once started (default=CONFIG_WATCHDOG_NOWAYOUT)");

// markus: kernel provided functions
// markus: write v to l. This is a kernel provided function
#define outb_p(v, l) \
  do { \
    l = v; \
  } while (false)

// markus: i've simplified this kernel function to remove the memory barries
// and not actual perform the bitwise operation
#define clear_bit(unused, v) \
  do { \
    v = 0; \
  } while (false)
// end kernel functions

#if 0
void mixcomwd_ping(void)
{
	outb_p(55,watchdog_port);
	return;
}
#endif

// markus: macro'd
#define mixcomwd_ping() \
  do { \
    outb_p(55,watchdog_port); \
  } while (false)



void mixcomwd_timerfun(unsigned long d)
{
	mixcomwd_ping();

	//mod_timer(&mixcomwd_timer,jiffies+ 5*HZ);
}

/*
 *	Allow only one person to hold it open
 */

// markus: neither of these arguments are actually used
#if 0
int mixcomwd_open(struct inode *inode, struct file *file)
{
	if(test_and_set_bit(0,&mixcomwd_opened)) {
		return -EBUSY;
	}
	mixcomwd_ping();

	if (nowayout) {
		/*
		 * fops_get() code via open() has already done
		 * a try_module_get() so it is safe to do the
		 * __module_get().
		 */
		__module_get(THIS_MODULE);
	} else {
		if(mixcomwd_timer_alive) {
			del_timer(&mixcomwd_timer);
			mixcomwd_timer_alive=0;
		}
	}
	return nonseekable_open(inode, file);
}
#endif

#if 0
int mixcomwd_release(struct inode *inode, struct file *file)
{
	if (expect_close == 42) {
		if(mixcomwd_timer_alive) {
			printk(KERN_ERR "mixcomwd: release called while internal timer alive");
			return -EBUSY;
		}
		init_timer(&mixcomwd_timer);
		mixcomwd_timer.expires=jiffies + 5 * HZ;
		mixcomwd_timer.function=mixcomwd_timerfun;
		mixcomwd_timer.data=0;
		mixcomwd_timer_alive=1;
		add_timer(&mixcomwd_timer);
	} else {
		printk(KERN_CRIT "mixcomwd: WDT device closed unexpectedly.  WDT will not stop!\n");
	}

	clear_bit(0,&mixcomwd_opened);
	expect_close=0;
	return 0;
}
#endif
// markus: defined this as a macro to force inline
// I've replaced the warning message with an assertion
#define mixconwd_release() \
  do { \
    if (expect_close == 42) { \
      if (mixcomwd_timer_alive) { \
        /* markus: do nothing */ \
			  /* printk(KERN_ERR "mixcomwd: release called while internal timer alive"); */ \
			  /* return -EBUSY; */ \
      } \
      else { \
        /*
         * markus: userspace timers are not modeled
        init_timer(&mixcomwd_timer); \
        mixcomwd_timer.expires=jiffies + 5 * HZ; \
        mixcomwd_timer.function=mixcomwd_timerfun; \
        mixcomwd_timer.data=0; \
        mixcomwd_timer_alive=1; \
        add_timer(&mixcomwd_timer); \
        */ \
      } \
    }  \
    else { \
		  /* printk(KERN_CRIT "mixcomwd: WDT device closed unexpectedly.  WDT will not stop!\n"); */ \
      assert(0); \
    } \
    clear_bit(0, mixcomwd_opened); \
    expect_close = 0; \
  } while (false) 

#if 0
ssize_t mixcomwd_write(struct file *file, const char __user *data, size_t len, loff_t *ppos)
{
	if(len)
	{
		if (!nowayout) {
			size_t i;

			/* In case it was set long ago */
			expect_close = 0;

			for (i = 0; i != len; i++) {
				char c;
				if (get_user(c, data + i))
					return -EFAULT;
				if (c == 'V')
					expect_close = 42;
			}
		}
		mixcomwd_ping();
	}
	return len;
}
#endif 

// markus: i've macroed this and moved the only parameter which
// was used, the buffer from userspace, as a global (see mixconwd_write_buff
#define mixconwd_write(len) \
  do { \
    if (len) { \
      if (!nowayout) { \
			  /* In case it was set long ago */ \
        expect_close = 0; \
        /* markus: originally, the buffer would be looped-over here */ \
        if (mixconwd_write_buf == 'V') { \
          expect_close = 42; \
        } \
      } \
    } \
    mixcomwd_ping();  \
  } while (false)

#if 0
int mixcomwd_ioctl(struct inode *inode, struct file *file,
	unsigned int cmd, unsigned long arg)
{
	void __user *argp = (void __user *)arg;
	int __user *p = argp;
	int status;
	static struct watchdog_info ident = {
		.options = WDIOF_KEEPALIVEPING | WDIOF_MAGICCLOSE,
		.firmware_version = 1,
		.identity = "MixCOM watchdog",
	};

	switch(cmd)
	{
		case WDIOC_GETSTATUS:
			status=mixcomwd_opened;
			if (!nowayout) {
				status|=mixcomwd_timer_alive;
			}
			if (copy_to_user(p, &status, sizeof(int))) {
				return -EFAULT;
			}
			break;
		case WDIOC_GETSUPPORT:
			if (copy_to_user(argp, &ident, sizeof(ident))) {
				return -EFAULT;
			}
			break;
		case WDIOC_KEEPALIVE:
			mixcomwd_ping();
			break;
		default:
			return -ENOTTY;
	}
	return 0;
}

const struct file_operations mixcomwd_fops=
{
	.owner		= THIS_MODULE,
	.llseek		= no_llseek,
	.write		= mixcomwd_write,
	.ioctl		= mixcomwd_ioctl,
	.open		= mixcomwd_open,
	.release	= mixcomwd_release,
};

static struct miscdevice mixcomwd_miscdev=
{
	.minor	= WATCHDOG_MINOR,
	.name	= "watchdog",
	.fops	= &mixcomwd_fops,
};

static int __init mixcomwd_checkcard(int port)
{
	int id;

	port += MIXCOM_WATCHDOG_OFFSET;
	if (!request_region(port, 1, "MixCOM watchdog")) {
		return 0;
	}

	id=inb_p(port) & 0x3f;
	if(id!=MIXCOM_ID) {
		release_region(port, 1);
		return 0;
	}
	return port;
}

static int __init flashcom_checkcard(int port)
{
	int id;

	port += FLASHCOM_WATCHDOG_OFFSET;
	if (!request_region(port, 1, "MixCOM watchdog")) {
		return 0;
	}

	id=inb_p(port);
 	if(id!=FLASHCOM_ID) {
		release_region(port, 1);
		return 0;
	}
 	return port;
 }

static int __init mixcomwd_init(void)
{
	int i;
	int ret;
	int found=0;

	for (i = 0; !found && mixcomwd_ioports[i] != 0; i++) {
		watchdog_port = mixcomwd_checkcard(mixcomwd_ioports[i]);
		if (watchdog_port) {
			found = 1;
		}
	}

	/* The FlashCOM card can be set up at 0x300 -> 0x378, in 0x8 jumps */
	for (i = 0x300; !found && i < 0x380; i+=0x8) {
		watchdog_port = flashcom_checkcard(i);
		if (watchdog_port) {
			found = 1;
		}
	}

	if (!found) {
		printk("mixcomwd: No card detected, or port not available.\n");
		return -ENODEV;
	}

	ret = misc_register(&mixcomwd_miscdev);
	if (ret)
	{
		release_region(watchdog_port, 1);
		return ret;
	}

	printk(KERN_INFO "MixCOM watchdog driver v%s, watchdog port at 0x%3x\n",VERSION,watchdog_port);

	return 0;
}

static void __exit mixcomwd_exit(void)
{
	if (!nowayout) {
		if(mixcomwd_timer_alive) {
			printk(KERN_WARNING "mixcomwd: I quit now, hardware will"
			       " probably reboot!\n");
			del_timer(&mixcomwd_timer);
			mixcomwd_timer_alive=0;
		}
	}
	release_region(watchdog_port,1);
	misc_deregister(&mixcomwd_miscdev);
}

module_init(mixcomwd_init);
module_exit(mixcomwd_exit);

MODULE_AUTHOR("Gergely Madarasz <gorgo@itc.hu>");
MODULE_DESCRIPTION("MixCom Watchdog driver");
MODULE_LICENSE("GPL");
MODULE_ALIAS_MISCDEV(WATCHDOG_MINOR);
#endif

void *writer1(void *unused) {
  mixconwd_write(0);
  return NULL;
}

void *writer2(void *unused) {
  mixconwd_write(0);
  return NULL;
}

void *writer3(void *unused) {
  mixconwd_write(0);
  return NULL;
}

void *writer4(void *unused) {
  mixconwd_write(0);
  return NULL;
}

void *writer5(void *unused) {
  mixconwd_write(0);
  return NULL;
}

void *writer6(void *unused) {
  mixconwd_write(0);
  return NULL;
}

void *writer7(void *unused) {
  mixconwd_write(0);
  return NULL;
}

void *writer8(void *unused) {
  mixconwd_write(0);
  return NULL;
}

void *writer9(void *unused) {
  mixconwd_write(0);
  return NULL;
}

void *writer10(void *unused) {
  mixconwd_write(0);
  return NULL;
}

void *closer(void *unused) {
  mixconwd_write_buf = 'V';
  mixconwd_write(1);
  mixconwd_release();
  return NULL;
}

int main(int argc, char *argv[]) {
  // initialization
  expect_close = 0;
  pthread_t t1;
  pthread_t t2;

  pthread_create(&t1, NULL, writer1, NULL);
  pthread_create(&t1, NULL, writer2, NULL);
  pthread_create(&t1, NULL, writer3, NULL);
  pthread_create(&t1, NULL, writer4, NULL);
  pthread_create(&t1, NULL, writer5, NULL);
  pthread_create(&t1, NULL, writer6, NULL);
  pthread_create(&t1, NULL, writer7, NULL);
  pthread_create(&t1, NULL, writer8, NULL);
  pthread_create(&t1, NULL, writer9, NULL);
  pthread_create(&t1, NULL, writer10, NULL);
  pthread_create(&t2, NULL, closer, NULL);
  pthread_exit(NULL);
}

