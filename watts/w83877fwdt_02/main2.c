/*
 *	W83877F Computer Watchdog Timer driver
 *
 *      Based on acquirewdt.c by Alan Cox,
 *           and sbc60xxwdt.c by Jakob Oestergaard <jakob@unthought.net>
 *
 *	This program is free software; you can redistribute it and/or
 *	modify it under the terms of the GNU General Public License
 *	as published by the Free Software Foundation; either version
 *	2 of the License, or (at your option) any later version.
 *
 *	The authors do NOT admit liability nor provide warranty for
 *	any of this software. This material is provided "AS-IS" in
 *      the hope that it may be useful for others.
 *
 *	(c) Copyright 2001    Scott Jennings <linuxdrivers@oro.net>
 *
 *           4/19 - 2001      [Initial revision]
 *           9/27 - 2001      Added spinlocking
 *           4/12 - 2002      [rob@osinvestor.com] Eliminate extra comments
 *                            Eliminate fop_read
 *                            Eliminate extra spin_unlock
 *                            Added KERN_* tags to printks
 *                            add CONFIG_WATCHDOG_NOWAYOUT support
 *                            fix possible wdt_is_open race
 *                            changed watchdog_info to correctly reflect what the driver offers
 *                            added WDIOC_GETSTATUS, WDIOC_GETBOOTSTATUS, WDIOC_SETTIMEOUT,
 *                            WDIOC_GETTIMEOUT, and WDIOC_SETOPTIONS ioctls
 *           09/8 - 2003      [wim@iguana.be] cleanup of trailing spaces
 *                            added extra printk's for startup problems
 *                            use module_param
 *                            made timeout (the emulated heartbeat) a module_param
 *                            made the keepalive ping an internal subroutine
 *
 *  This WDT driver is different from most other Linux WDT
 *  drivers in that the driver will ping the watchdog by itself,
 *  because this particular WDT has a very short timeout (1.6
 *  seconds) and it would be insane to count on any userspace
 *  daemon always getting scheduled within that time frame.
 */
#if 0
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/types.h>
#include <linux/timer.h>
#include <linux/jiffies.h>
#include <linux/miscdevice.h>
#include <linux/watchdog.h>
#include <linux/fs.h>
#include <linux/ioport.h>
#include <linux/notifier.h>
#include <linux/reboot.h>
#include <linux/init.h>
#include <asm/io.h>
#include <asm/uaccess.h>
#include <asm/system.h>
#endif
//#include <assert.h>
#include <pthread.h>
#include <stdbool.h>
#include <errno.h>
#include <stdint.h>

#define OUR_NAME "w83877f_wdt"
#define PFX OUR_NAME ": "

#define FULL_CODE 0
// kernel functions
long jiffies;
#define HZ 1
#define time_before(a, b) a + (HZ * b)

// hardware stuff
char wdt_ping_port;
char w83877f_port;
// w83877f_port + 1
char w83877f_port_1;
// end hardware stuff

// userspace buffer for fop_write()
char fops_write_buf;

#define spin_lock(l) \
  do { \
    while (l) { \
      /* spin */ \
    } \
  } while (false)

#define spin_unlock(l) \
  do { \
    l = false; \
  } while (false)

// markus: write v to l. This is a kernel provided function
#define outb(v, l) \
  do { \
    l = v; \
  } while (false)

#define outb_p(v, l) outb(v, l)

#define inb_p(v) v

// markus: ignore delays
#define udelay(t) do { } while (false)
#define mdelay(t) do { } while (false)

// markus: i've simplified this kernel function to remove the memory barries
// and not actual perform the bitwise operation
#define clear_bit(unused, v) \
  do { \
    v = 0; \
  } while (false)
#define pci_enable_device(a) 0
#define pci_resource_start(a, b) 1024

#define up(a) do { a += 1; } while (false);

#define readw(v) v

#define writew(v, l) outb(v, l)

// end kernel functions

#define ENABLE_W83877F_PORT 0x3F0
#define ENABLE_W83877F 0x87
#define DISABLE_W83877F 0xAA
#define WDT_PING 0x443
#define WDT_REGISTER 0x14
#define WDT_ENABLE 0x9C
#define WDT_DISABLE 0x8C

/*
 * The W83877F seems to be fixed at 1.6s timeout (at least on the
 * EMACS PC-104 board I'm using). If we reset the watchdog every
 * ~250ms we should be safe.  */

#define WDT_INTERVAL (HZ/4+1)

/*
 * We must not require too good response from the userspace daemon.
 * Here we require the userspace daemon to send us a heartbeat
 * char to /dev/watchdog every 30 seconds.
 */

#define WATCHDOG_TIMEOUT 30            /* 30 sec default timeout */
int timeout = WATCHDOG_TIMEOUT; /* in seconds, will be multiplied by HZ to get seconds to wait for a ping */
//module_param(timeout, int, 0);
//MODULE_PARM_DESC(timeout, "Watchdog timeout in seconds. (1<=timeout<=3600, default=" __MODULE_STRING(WATCHDOG_TIMEOUT) ")");

#define WATCHDOG_NOWAYOUT 0
int nowayout = WATCHDOG_NOWAYOUT;
//module_param(nowayout, int, 0);
//MODULE_PARM_DESC(nowayout, "Watchdog cannot be stopped once started (default=CONFIG_WATCHDOG_NOWAYOUT)");

void wdt_timer_ping(unsigned long);
//struct timer_list timer;
unsigned long next_heartbeat;
unsigned long wdt_is_open;
char wdt_expect_close;
bool wdt_spinlock;
bool wdt_spinlock_init = false;
bool dev_open = false;
//spinlock_t wdt_spinlock;

/*
 *	Whack the dog
 */

#if 0
static void wdt_timer_ping(unsigned long data)
{
	/* If we got a heartbeat pulse within the WDT_US_INTERVAL
	 * we agree to ping the WDT
	 */
	if(time_before(jiffies, next_heartbeat))
	{
		/* Ping the WDT */
		spin_lock(&wdt_spinlock);

		/* Ping the WDT by reading from WDT_PING */
		inb_p(WDT_PING);

		/* Re-set the timer interval */
		timer.expires = jiffies + WDT_INTERVAL;
		add_timer(&timer);

		spin_unlock(&wdt_spinlock);

	} else {
		printk(KERN_WARNING PFX "Heartbeat lost! Will not ping the watchdog\n");
	}
}
#endif

#define wdt_timer_ping() \
  do { \
    /* If we got a heartbeat pulse within the WDT_US_INTERVAL
     * we agree to ping the WDT
     */ \
    if(time_before(jiffies, next_heartbeat)) { \
      /* Ping the WDT */ \
      spin_lock(wdt_spinlock); \
      /* Ping the WDT by reading from WDT_PING */ \
      inb_p(wdt_ping_port); \
      spin_unlock(&wdt_spinlock); \
    } \
    else { \
      /* markus: do nothing */  \
    } \
  } while (false)

/*
 * Utility routines
 */

#if 0
static void wdt_change(int writeval)
{
	unsigned long flags;
	spin_lock_irqsave(&wdt_spinlock, flags);

	/* buy some time */
	inb_p(WDT_PING);

	/* make W83877F available */
	outb_p(ENABLE_W83877F,  ENABLE_W83877F_PORT);
	outb_p(ENABLE_W83877F,  ENABLE_W83877F_PORT);

	/* enable watchdog */
	outb_p(WDT_REGISTER,    ENABLE_W83877F_PORT);
	outb_p(writeval,        ENABLE_W83877F_PORT+1);

	/* lock the W8387FF away */
	outb_p(DISABLE_W83877F, ENABLE_W83877F_PORT);

	spin_unlock_irqrestore(&wdt_spinlock, flags);
}
#endif
#define wdt_change(writeval) \
  do { \
    spin_lock(wdt_spinlock); \
    /* buy some time */ \
    (char)inb_p(WDT_PING); \
    /* make W83877F available */ \
    outb_p(ENABLE_W83877F,  w83877f_port); \
    outb_p(ENABLE_W83877F,  w83877f_port); \
    /* enable watchdog */ \
    outb_p(WDT_REGISTER,    w83877f_port); \
    outb_p(writeval,        w83877f_port_1); \
    /* lock the W8387FF away */ \
    outb_p(DISABLE_W83877F, w83877f_port); \
    spin_unlock(wdt_spinlock); \
  } while (false)

#if FULL_CODE
static void wdt_startup(void)
{
	next_heartbeat = jiffies + (timeout * HZ);

	/* Start the timer */
	timer.expires = jiffies + WDT_INTERVAL;
	add_timer(&timer);

	wdt_change(WDT_ENABLE);

	printk(KERN_INFO PFX "Watchdog timer is now enabled.\n");
}
#endif

#if 0
static void wdt_turnoff(void)
{
	/* Stop the timer */
	del_timer(&timer);

	wdt_change(WDT_DISABLE);

	printk(KERN_INFO PFX "Watchdog timer is now disabled...\n");
}
#endif
#define wdt_turnoff() \
  do { \
    wdt_change(0);\
  } while (false)

#if 0
static void wdt_keepalive(void)
{
	/* user land ping */
	next_heartbeat = jiffies + (timeout * HZ);
}
#endif
#define wdt_keepalive() \
  do { \
    if (!dev_open) { \
      assert(0); \
    } \
    next_heartbeat = jiffies + (timeout * HZ); \
    assert(dev_open); \
  } while (false)

/*
 * /dev/watchdog handling
 */

#if 0
static ssize_t fop_write(struct file * file, const char __user * buf, size_t count, loff_t * ppos)
{
	/* See if we got the magic character 'V' and reload the timer */
	if(count)
	{
		if (!nowayout)
		{
			size_t ofs;

			/* note: just in case someone wrote the magic character
			 * five months ago... */
			wdt_expect_close = 0;

			/* scan to see whether or not we got the magic character */
			for(ofs = 0; ofs != count; ofs++)
			{
				char c;
				if (get_user(c, buf + ofs))
					return -EFAULT;
				if (c == 'V')
					wdt_expect_close = 42;
			}
		}

		/* someone wrote to us, we should restart timer */
		wdt_keepalive();
	}
	return count;
}
#endif

// markus: macroed, moved userspace argment to global
#define fop_write(count) \
  do { \
    /* See if we got the magic character 'V' and reload the timer */ \
    if(count) \
    { \
      if (!nowayout) \
      { \
        /* size_t ofs; */ \
                    \
        /* note: just in case someone wrote the magic character
         * five months ago... */ \
        wdt_expect_close = 0; \
        /* markus: originally, the buffer would be looped-over here */ \
        if (fops_write_buf == 'V') { \
          wdt_expect_close = 42; \
        } \
      } \
    } \
    wdt_keepalive(); \
  } while (false)

#define wdt_init() \
  do { \
    jiffies = 0; \
    fops_write_buf = '\0'; \
    wdt_expect_close = 0; \
    /* wdt_spinlock_init = true; */ \
    dev_open = true; \
  } while (false)

#if FULL_CODE
static int fop_open(struct inode * inode, struct file * file)
{
	/* Just in case we're already talking to someone... */
	if(test_and_set_bit(0, &wdt_is_open))
		return -EBUSY;

	/* Good, fire up the show */
	wdt_startup();
	return nonseekable_open(inode, file);
}
#endif

#if 0
static int fop_close(struct inode * inode, struct file * file)
{
	if(wdt_expect_close == 42)
		wdt_turnoff();
	else {
		del_timer(&timer);
		printk(KERN_CRIT PFX "device file closed unexpectedly. Will not stop the WDT!\n");
	}
	clear_bit(0, &wdt_is_open);
	wdt_expect_close = 0;
	return 0;
}
#endif

#define fop_close()  \
  do { \
	if(wdt_expect_close == 42) \
		wdt_turnoff(); \
	else { \
    /* markus: timers not modeled */ \
		/* del_timer(&timer); */ \
		/* printk(KERN_CRIT PFX "device file closed unexpectedly. Will not stop the WDT!\n"); */ \
    assert(0); \
	} \
	clear_bit(0, wdt_is_open); \
	wdt_expect_close = 0; \
  } while (false) 

#if FULL_CODE
static int fop_ioctl(struct inode *inode, struct file *file, unsigned int cmd,
	unsigned long arg)
{
	void __user *argp = (void __user *)arg;
	int __user *p = argp;
	static struct watchdog_info ident=
	{
		.options = WDIOF_KEEPALIVEPING | WDIOF_SETTIMEOUT | WDIOF_MAGICCLOSE,
		.firmware_version = 1,
		.identity = "W83877F",
	};

	switch(cmd)
	{
		default:
			return -ENOTTY;
		case WDIOC_GETSUPPORT:
			return copy_to_user(argp, &ident, sizeof(ident))?-EFAULT:0;
		case WDIOC_GETSTATUS:
		case WDIOC_GETBOOTSTATUS:
			return put_user(0, p);
		case WDIOC_KEEPALIVE:
			wdt_keepalive();
			return 0;
		case WDIOC_SETOPTIONS:
		{
			int new_options, retval = -EINVAL;

			if(get_user(new_options, p))
				return -EFAULT;

			if(new_options & WDIOS_DISABLECARD) {
				wdt_turnoff();
				retval = 0;
			}

			if(new_options & WDIOS_ENABLECARD) {
				wdt_startup();
				retval = 0;
			}

			return retval;
		}
		case WDIOC_SETTIMEOUT:
		{
			int new_timeout;

			if(get_user(new_timeout, p))
				return -EFAULT;

			if(new_timeout < 1 || new_timeout > 3600) /* arbitrary upper limit */
				return -EINVAL;

			timeout = new_timeout;
			wdt_keepalive();
			/* Fall through */
		}
		case WDIOC_GETTIMEOUT:
			return put_user(timeout, p);
	}
}

static const struct file_operations wdt_fops = {
	.owner		= THIS_MODULE,
	.llseek		= no_llseek,
	.write		= fop_write,
	.open		= fop_open,
	.release	= fop_close,
	.ioctl		= fop_ioctl,
};

static struct miscdevice wdt_miscdev = {
	.minor	= WATCHDOG_MINOR,
	.name	= "watchdog",
	.fops	= &wdt_fops,
};

/*
 *	Notifier for system down
 */

static int wdt_notify_sys(struct notifier_block *this, unsigned long code,
	void *unused)
{
	if(code==SYS_DOWN || code==SYS_HALT)
		wdt_turnoff();
	return NOTIFY_DONE;
}

/*
 *	The WDT needs to learn about soft shutdowns in order to
 *	turn the timebomb registers off.
 */

static struct notifier_block wdt_notifier=
{
	.notifier_call = wdt_notify_sys,
};

static void __exit w83877f_wdt_unload(void)
{
	wdt_turnoff();

	/* Deregister */
	misc_deregister(&wdt_miscdev);

	unregister_reboot_notifier(&wdt_notifier);
	release_region(WDT_PING,1);
	release_region(ENABLE_W83877F_PORT,2);
}

static int __init w83877f_wdt_init(void)
{
	int rc = -EBUSY;

	spin_lock_init(&wdt_spinlock);

	if(timeout < 1 || timeout > 3600) /* arbitrary upper limit */
	{
		timeout = WATCHDOG_TIMEOUT;
		printk(KERN_INFO PFX "timeout value must be 1<=x<=3600, using %d\n",
			timeout);
	}

	if (!request_region(ENABLE_W83877F_PORT, 2, "W83877F WDT"))
	{
		printk(KERN_ERR PFX "I/O address 0x%04x already in use\n",
			ENABLE_W83877F_PORT);
		rc = -EIO;
		goto err_out;
	}

	if (!request_region(WDT_PING, 1, "W8387FF WDT"))
	{
		printk(KERN_ERR PFX "I/O address 0x%04x already in use\n",
			WDT_PING);
		rc = -EIO;
		goto err_out_region1;
	}

	init_timer(&timer);
	timer.function = wdt_timer_ping;
	timer.data = 0;

	rc = misc_register(&wdt_miscdev);
	if (rc)
	{
		printk(KERN_ERR PFX "cannot register miscdev on minor=%d (err=%d)\n",
			wdt_miscdev.minor, rc);
		goto err_out_region2;
	}

	rc = register_reboot_notifier(&wdt_notifier);
	if (rc)
	{
		printk(KERN_ERR PFX "cannot register reboot notifier (err=%d)\n",
			rc);
		goto err_out_miscdev;
	}

	printk(KERN_INFO PFX "WDT driver for W83877F initialised. timeout=%d sec (nowayout=%d)\n",
		timeout, nowayout);

	return 0;

err_out_miscdev:
	misc_deregister(&wdt_miscdev);
err_out_region2:
	release_region(WDT_PING,1);
err_out_region1:
	release_region(ENABLE_W83877F_PORT,2);
err_out:
	return rc;
}

module_init(w83877f_wdt_init);
module_exit(w83877f_wdt_unload);

MODULE_AUTHOR("Scott and Bill Jennings");
MODULE_DESCRIPTION("Driver for watchdog timer in w83877f chip");
MODULE_LICENSE("GPL");
MODULE_ALIAS_MISCDEV(WATCHDOG_MINOR);
#endif

void *writer1(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer2(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer3(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer4(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer5(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer6(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer7(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer8(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer9(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer10(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer11(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer12(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer13(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer14(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer15(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer16(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer17(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer18(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer19(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer20(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer21(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer22(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer23(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer24(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer25(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer26(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer27(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer28(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer29(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer30(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer31(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer32(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer33(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer34(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer35(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer36(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer37(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer38(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer39(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer40(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer41(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer42(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer43(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer44(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer45(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer46(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer47(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer48(void *unused) {
  fop_write(0);
  return NULL;
}

void *writer49(void *unused) {
  fop_write(0);
  return NULL;
}

void *closer(void *unused) {
  fops_write_buf = 'V';
  fop_write(1);
  fop_close();
  return NULL;
  return NULL;
}

int main(int argc, char *argv[]) {
  wdt_init();

  pthread_t t1;
  pthread_t t2;

  pthread_create(&t2, NULL, writer1, NULL);
  pthread_create(&t2, NULL, writer2, NULL);
  pthread_create(&t2, NULL, writer3, NULL);
  pthread_create(&t2, NULL, writer4, NULL);
  pthread_create(&t2, NULL, writer5, NULL);
  pthread_create(&t2, NULL, writer6, NULL);
  pthread_create(&t2, NULL, writer7, NULL);
  pthread_create(&t2, NULL, writer8, NULL);
  pthread_create(&t2, NULL, writer9, NULL);
  pthread_create(&t2, NULL, writer10, NULL);
  pthread_create(&t2, NULL, writer11, NULL);
  pthread_create(&t2, NULL, writer12, NULL);
  pthread_create(&t2, NULL, writer13, NULL);
  pthread_create(&t2, NULL, writer14, NULL);
  pthread_create(&t2, NULL, writer15, NULL);
  pthread_create(&t2, NULL, writer16, NULL);
  pthread_create(&t2, NULL, writer17, NULL);
  pthread_create(&t2, NULL, writer18, NULL);
  pthread_create(&t2, NULL, writer19, NULL);
  pthread_create(&t2, NULL, writer20, NULL);
  pthread_create(&t2, NULL, writer21, NULL);
  pthread_create(&t2, NULL, writer22, NULL);
  pthread_create(&t2, NULL, writer23, NULL);
  pthread_create(&t2, NULL, writer24, NULL);
  pthread_create(&t2, NULL, writer25, NULL);
  pthread_create(&t2, NULL, writer26, NULL);
  pthread_create(&t2, NULL, writer27, NULL);
  pthread_create(&t2, NULL, writer28, NULL);
  pthread_create(&t2, NULL, writer29, NULL);
  pthread_create(&t2, NULL, writer30, NULL);
  pthread_create(&t2, NULL, writer31, NULL);
  pthread_create(&t2, NULL, writer32, NULL);
  pthread_create(&t2, NULL, writer33, NULL);
  pthread_create(&t2, NULL, writer34, NULL);
  pthread_create(&t2, NULL, writer35, NULL);
  pthread_create(&t2, NULL, writer36, NULL);
  pthread_create(&t2, NULL, writer37, NULL);
  pthread_create(&t2, NULL, writer38, NULL);
  pthread_create(&t2, NULL, writer39, NULL);
  pthread_create(&t2, NULL, writer40, NULL);
  pthread_create(&t2, NULL, writer41, NULL);
  pthread_create(&t2, NULL, writer42, NULL);
  pthread_create(&t2, NULL, writer43, NULL);
  pthread_create(&t2, NULL, writer44, NULL);
  pthread_create(&t2, NULL, writer45, NULL);
  pthread_create(&t2, NULL, writer46, NULL);
  pthread_create(&t2, NULL, writer47, NULL);
  pthread_create(&t2, NULL, writer48, NULL);
  pthread_create(&t2, NULL, writer49, NULL);
  pthread_create(&t1, NULL, closer, NULL);

  pthread_exit(NULL);
}
