/*
 *  MachZ ZF-Logic Watchdog Timer driver for Linux
 *
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version
 *  2 of the License, or (at your option) any later version.
 *
 *  The author does NOT admit liability nor provide warranty for
 *  any of this software. This material is provided "AS-IS" in
 *  the hope that it may be useful for others.
 *
 *  Author: Fernando Fuganti <fuganti@conectiva.com.br>
 *
 *  Based on sbc60xxwdt.c by Jakob Oestergaard
 *
 *
 *  We have two timers (wd#1, wd#2) driven by a 32 KHz clock with the
 *  following periods:
 *      wd#1 - 2 seconds;
 *      wd#2 - 7.2 ms;
 *  After the expiration of wd#1, it can generate a NMI, SCI, SMI, or
 *  a system RESET and it starts wd#2 that unconditionaly will RESET
 *  the system when the counter reaches zero.
 *
 *  14-Dec-2001 Matt Domsch <Matt_Domsch@dell.com>
 *      Added nowayout module option to override CONFIG_WATCHDOG_NOWAYOUT
 *  23-Jun-2015 Markus Kusano <mukusano@vt.edu>
 *      Modified to test with abstract interpreter
 */
#include <pthread.h>
#include <assert.h>
#include <stdbool.h>
#include <errno.h>

/* ports */
#define ZF_IOBASE	0x218
#define INDEX		0x218
#define DATA_B		0x219
#define DATA_W		0x21A
#define DATA_D		0x21A

/* indexes */			/* size */
#define ZFL_VERSION	0x02	/* 16   */
#define CONTROL 	0x10	/* 16   */
#define STATUS		0x12	/* 8    */
#define COUNTER_1	0x0C	/* 16   */
#define COUNTER_2	0x0E	/* 8    */
#define PULSE_LEN	0x0F	/* 8    */

/* controls */
#define ENABLE_WD1	0x0001
#define ENABLE_WD2	0x0002
#define RESET_WD1	0x0010
#define RESET_WD2	0x0020
#define GEN_SCI		0x0100
#define GEN_NMI		0x0200
#define GEN_SMI		0x0400
#define GEN_RESET	0x0800


/* utilities */

#define WD1	0
#define WD2	1


// simulated value for INDEX
char index_port;
// simulated value for DATA_W
char data_w_port;
// simulated value for DATA_B
char data_b_port;

// markus: these are kernel defined functions. They originally write to
// hardware ports. Any hardware ports are simulated with global variables
#define outb(v, port) do { port = v; } while (false)
#define outw(v, port) do { port = v; } while (false)
#define inw(p) p 

// markus: i've simplified this kernel function to remove the memory barries
// and not actual perform the bitwise operation
#define clear_bit(unused, v) \
  do { \
    v = 0; \
  } while (false)

// markus: spin lock are provided by the kernel. Here, I just set them to
// basically do nothing in order to over-approximate the behavior (i.e., there
// may be spurious atomicity violations). They do nothing since the value of l
// is never set.
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

// markus: these macros were modified to use the simulated hardware ports
// (e.g., index_port instead of INDEX)
#define zf_writew(port, data)  { outb(port, index_port); outw(data, data_w_port); }
#define zf_writeb(port, data)  { outb(port, index_port); outb(data, data_b_port); }
#define zf_get_ZFL_version()   zf_readw(ZFL_VERSION)

unsigned short zf_readw(unsigned char port)
{
	outb(port, index_port);
	return inw(data_w_port);
}

// markus: ignore these kernel metadata things
// MODULE_AUTHOR("Fernando Fuganti <fuganti@conectiva.com.br>");
// MODULE_DESCRIPTION("MachZ ZF-Logic Watchdog driver");
// MODULE_LICENSE("GPL");
// MODULE_ALIAS_MISCDEV(WATCHDOG_MINOR);

// markus: manually set default value for NOWAYOUT
#define WATCHDOG_NOWAYOUT 0;
int nowayout = WATCHDOG_NOWAYOUT;
//module_param(nowayout, int, 0);
//MODULE_PARM_DESC(nowayout, "Watchdog cannot be stopped once started (default=CONFIG_WATCHDOG_NOWAYOUT)");

#define PFX "machzwd"

// markus: ignoring this for now, it is only used in ioctl
//static struct watchdog_info zf_info = {
//	.options		= WDIOF_KEEPALIVEPING | WDIOF_MAGICCLOSE,
//	.firmware_version	= 1,
//	.identity		= "ZF-Logic watchdog",
//};


/*
 * action refers to action taken when watchdog resets
 * 0 = GEN_RESET
 * 1 = GEN_SMI
 * 2 = GEN_NMI
 * 3 = GEN_SCI
 * defaults to GEN_RESET (0)
 */
int action = 0;
// markus: ignore kernel options, just use default
//module_param(action, int, 0);
//MODULE_PARM_DESC(action, "after watchdog resets, generate: 0 = RESET(*)  1 = SMI  2 = NMI  3 = SCI");


int zf_action = GEN_RESET;
unsigned long zf_is_open;
char zf_expect_close;
// Replace spin locks with manually defined locks
bool zf_lock;
bool zf_port_lock;
// markus: the timer used by the character device is not modeled
//struct timer_list zf_timer;
unsigned long next_heartbeat = 0;

// markus: user space value passed to zf_write
char zf_write_buf;

/* timeout for user land heart beat (10 seconds) */
#define ZF_USER_TIMEO (HZ*10)

/* timeout for hardware watchdog (~500ms) */
#define ZF_HW_TIMEO (HZ/2)

/* number of ticks on WD#1 (driven by a 32KHz clock, 2s) */
#define ZF_CTIMEOUT 0xffff

#ifndef ZF_DEBUG
#	define dprintk(format, args...)
#else
#	define dprintk(format, args...) printk(KERN_DEBUG PFX ":%s:%d: " format, __FUNCTION__, __LINE__ , ## args)
#endif


inline void zf_set_status(unsigned char new)
{
	zf_writeb(STATUS, new);
}


/* CONTROL register functions */

inline unsigned short zf_get_control(void)
{
	return zf_readw(CONTROL);
}

inline void zf_set_control(unsigned short new)
{
	zf_writew(CONTROL, new);
}


/* WD#? counter functions */
/*
 *	Just set counter value
 */

inline void zf_set_timer(unsigned short new, unsigned char n)
{
	switch(n){
		case WD1:
			zf_writew(COUNTER_1, new);
		case WD2:
			zf_writeb(COUNTER_2, new > 0xff ? 0xff : new);
		default:
			return;
	}
}

/*
 * stop hardware timer
 */
// markus: modified to macro function to force inlining. This function mostly
// wrote to hardware ports which are not being modeled.
#define zf_timer_off() \
  do { \
    unsigned int ctrl_reg = 0; \
    unsigned long flags;          \
                                  \
    /* stop internal ping */      \
    /* del_timer_sync(&zf_timer); */ \
                                  \
    /* spin_lock_irqsave(&zf_port_lock, flags); */ \
    spin_lock(zf_port_lock); \
    /* stop watchdog timer */ \
    /*ctrl_reg = zf_get_control(); */ \
    /*ctrl_reg |= (ENABLE_WD1|ENABLE_WD2);	*/ /* disable wd1 and wd2 */ \
    /* ctrl_reg &= ~(ENABLE_WD1|ENABLE_WD2); */ \
    /* zf_set_control(ctrl_reg); */ \
    /* spin_unlock_irqrestore(&zf_port_lock, flags); */ \
    spin_unlock(zf_port_lock);  \
                                \
    /* printk(KERN_INFO PFX ": Watchdog timer is now disabled\n"); */ \
  } while (false)


/*
 * start hardware timer
 */
void zf_timer_on(void)
{
	unsigned int ctrl_reg = 0;
	unsigned long flags;

	//spin_lock_irqsave(&zf_port_lock, flags);
	spin_lock(zf_port_lock);

	zf_writeb(PULSE_LEN, 0xff);

	zf_set_timer(ZF_CTIMEOUT, WD1);

	/* user land ping */
	//next_heartbeat = jiffies + ZF_USER_TIMEO;

	/* start the timer for internal ping */
	//zf_timer.expires = jiffies + ZF_HW_TIMEO;

	//add_timer(&zf_timer);

	/* start watchdog timer */
	ctrl_reg = zf_get_control();
	ctrl_reg |= (ENABLE_WD1|zf_action);
	zf_set_control(ctrl_reg);
	//spin_unlock_irqrestore(&zf_port_lock, flags);
	spin_unlock(zf_port_lock);

	//printk(KERN_INFO PFX ": Watchdog timer is now enabled\n");
}


void zf_ping(unsigned long data)
{
	unsigned int ctrl_reg = 0;
	unsigned long flags;

	zf_writeb(COUNTER_2, 0xff);

	//if(time_before(jiffies, next_heartbeat)){

		//dprintk("time_before: %ld\n", next_heartbeat - jiffies);

		/*
		 * reset event is activated by transition from 0 to 1 on
		 * RESET_WD1 bit and we assume that it is already zero...
		 */

		//spin_lock_irqsave(&zf_port_lock, flags);
		spin_lock(zf_port_lock);
		ctrl_reg = zf_get_control();
		ctrl_reg |= RESET_WD1;
		zf_set_control(ctrl_reg);

		/* ...and nothing changes until here */
		ctrl_reg &= ~(RESET_WD1);
		zf_set_control(ctrl_reg);
		//spin_unlock_irqrestore(&zf_port_lock, flags);
		spin_unlock(zf_port_lock);

		//zf_timer.expires = jiffies + ZF_HW_TIMEO;
		//add_timer(&zf_timer);
	//}else{
		//printk(KERN_CRIT PFX ": I will reset your machine\n");
    // markus: this should never happen?
    //assert(0);
	//}
}

#if 0
size_t zf_write(struct file *file, const char __user *buf, size_t count,
								loff_t *ppos)
{
	/* See if we got the magic character */
	if(count){

		/*
		 * no need to check for close confirmation
		 * no way to disable watchdog ;)
		 */
		if (!nowayout) {
			size_t ofs;

			/*
			 * note: just in case someone wrote the magic character
			 * five months ago...
			 */
			zf_expect_close = 0;

			/* now scan */
			for (ofs = 0; ofs != count; ofs++){
				char c;
				if (get_user(c, buf + ofs))
					return -EFAULT;
				if (c == 'V'){
					zf_expect_close = 42;
					//dprintk("zf_expect_close = 42\n");
				}
			}
		}

		/*
		 * Well, anyhow someone wrote to us,
		 * we should return that favour
		 */
		//next_heartbeat = jiffies + ZF_USER_TIMEO;
		//dprintk("user ping at %ld\n", jiffies);

	}

	return count;
}
#endif
// markus: originially, this function took a file, a userspace data buffer, and
// a loff_t. The file and loff_t were not used. I've simplified the userspace
// buffer to be a single character handled by a global (see tco_write_buf). The
// single passed parameter if set to non-zero will cause the buffer to be read,
// otherwise the buffer will not be read
#define zf_write(count) \
  do { \
	  /* See if we got the magic character */ \
    if (count) { \
                 \
		/*
		 * no need to check for close confirmation
		 * no way to disable watchdog ;)
		 */ \
      if (!nowayout) { \
        /*
         * note: just in case someone wrote the magic character
         * five months ago...
         */ \
        zf_expect_close = 0; \
        /* markus: originally, the buffer would be looped-over here */ \
        if (zf_write_buf == 'V') { \
          zf_expect_close = 42; \
					/* dprintk("zf_expect_close = 42\n"); */ \
        } \
      } \
    } \
      \
		/*
		 * Well, anyhow someone wrote to us,
		 * we should return that favour
		 */ \
		/* next_heartbeat = jiffies + ZF_USER_TIMEO; */ \
		/* dprintk("user ping at %ld\n", jiffies); */ \
  } while (false)

#if 0
int zf_ioctl(struct inode *inode, struct file *file, unsigned int cmd,
	unsigned long arg)
{
	void __user *argp = (void __user *)arg;
	int __user *p = argp;
	switch(cmd){
		case WDIOC_GETSUPPORT:
			if (copy_to_user(argp, &zf_info, sizeof(zf_info)))
				return -EFAULT;
			break;

		case WDIOC_GETSTATUS:
			return put_user(0, p);

		case WDIOC_KEEPALIVE:
			zf_ping(0);
			break;

		default:
			return -ENOTTY;
	}

	return 0;
}
#endif

#if 0
int zf_open(struct inode *inode, struct file *file)
{
	spin_lock(&zf_lock);
	if(test_and_set_bit(0, &zf_is_open)) {
		spin_unlock(&zf_lock);
		return -EBUSY;
	}

	if (nowayout)
		__module_get(THIS_MODULE);

	spin_unlock(&zf_lock);

	zf_timer_on();

	return nonseekable_open(inode, file);
}
#endif

#if 0
int zf_close(struct inode *inode, struct file *file)
{
	if(zf_expect_close == 42){
		zf_timer_off();
	} else {
		del_timer(&zf_timer);
		//printk(KERN_ERR PFX ": device file closed unexpectedly. Will not stop the WDT!\n");
    assert(0);
	}

	spin_lock(&zf_lock);
	clear_bit(0, &zf_is_open);
	spin_unlock(&zf_lock);

	zf_expect_close = 0;

	return 0;
}
#endif
#define zf_close() \
  do { \
    if (zf_expect_close == 42) { \
      zf_timer_off(); \
    } else { \
		  /* del_timer(&zf_timer); */ \
      /* printk(KERN_CRIT PFX "Unexpected close, not stopping watchdog!\n"); 
       * */ \
      assert(0); \
    } \
	  spin_lock(zf_lock); \
    clear_bit(0, zf_is_open); \
	  spin_unlock(zf_lock); \
                          \
    zf_expect_close = 0; \
  } while (false) 

void *writer1(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer2(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer3(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer4(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer5(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer6(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer7(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer8(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer9(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer10(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer11(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer12(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer13(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer14(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer15(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer16(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer17(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer18(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer19(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer20(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer21(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer22(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer23(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer24(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer25(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer26(void *unused) {
  zf_write(0);
  return NULL;
}

void *writer27(void *unused) {
  zf_write(0);
  return NULL;
}



void *closer(void *unused) {
  zf_write_buf = 'V';
  zf_write(1);
  zf_close();
  return NULL;
}

int main(int argc, char *argv[]) {
  // initialization
  zf_expect_close = 0;
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
  pthread_create(&t1, NULL, writer11, NULL);
  pthread_create(&t1, NULL, writer12, NULL);
  pthread_create(&t1, NULL, writer13, NULL);
  pthread_create(&t1, NULL, writer14, NULL);
  pthread_create(&t1, NULL, writer15, NULL);
  pthread_create(&t1, NULL, writer16, NULL);
  pthread_create(&t1, NULL, writer17, NULL);
  pthread_create(&t1, NULL, writer18, NULL);
  pthread_create(&t1, NULL, writer19, NULL);
  pthread_create(&t1, NULL, writer20, NULL);
  pthread_create(&t1, NULL, writer21, NULL);
  pthread_create(&t1, NULL, writer22, NULL);
  pthread_create(&t1, NULL, writer23, NULL);
  pthread_create(&t1, NULL, writer24, NULL);
  pthread_create(&t1, NULL, writer25, NULL);
  pthread_create(&t1, NULL, writer26, NULL);
  pthread_create(&t1, NULL, writer27, NULL);
  pthread_create(&t2, NULL, closer, NULL);
  pthread_exit(NULL);
}

/*
 * Notifier for system down
 */

#if 0
int zf_notify_sys(struct notifier_block *this, unsigned long code,
								void *unused)
{
	if(code == SYS_DOWN || code == SYS_HALT){
		zf_timer_off();
	}

	return NOTIFY_DONE;
}
#endif 



#if 0
const struct file_operations zf_fops = {
	.owner          = THIS_MODULE,
	.llseek         = no_llseek,
	.write          = zf_write,
	.ioctl          = zf_ioctl,
	.open           = zf_open,
	.release        = zf_close,
};
#endif

#if 0
struct miscdevice zf_miscdev = {
	.minor = WATCHDOG_MINOR,
	.name = "watchdog",
	.fops = &zf_fops,
};
#endif 
 

/*
 * The device needs to learn about soft shutdowns in order to
 * turn the timebomb registers off.
 */
#if 0
struct notifier_block zf_notifier = {
	.notifier_call = zf_notify_sys,
};
#endif

#if 0
void __init zf_show_action(int act)
{
	char *str[] = { "RESET", "SMI", "NMI", "SCI" };

	printk(KERN_INFO PFX ": Watchdog using action = %s\n", str[act]);
}
#endif

#if 0
int __init zf_init(void)
{
	int ret;

	printk(KERN_INFO PFX ": MachZ ZF-Logic Watchdog driver initializing.\n");

	ret = zf_get_ZFL_version();
	if ((!ret) || (ret == 0xffff)) {
		printk(KERN_WARNING PFX ": no ZF-Logic found\n");
		return -ENODEV;
	}

	if((action <= 3) && (action >= 0)){
		zf_action = zf_action>>action;
	} else
		action = 0;

	zf_show_action(action);

	spin_lock_init(&zf_lock);
	spin_lock_init(&zf_port_lock);

	ret = misc_register(&zf_miscdev);
	if (ret){
		printk(KERN_ERR "can't misc_register on minor=%d\n",
							WATCHDOG_MINOR);
		goto out;
	}

	if(!request_region(ZF_IOBASE, 3, "MachZ ZFL WDT")){
		printk(KERN_ERR "cannot reserve I/O ports at %d\n",
							ZF_IOBASE);
		ret = -EBUSY;
		goto no_region;
	}

	ret = register_reboot_notifier(&zf_notifier);
	if(ret){
		printk(KERN_ERR "can't register reboot notifier (err=%d)\n",
									ret);
		goto no_reboot;
	}

	zf_set_status(0);
	zf_set_control(0);

	/* this is the timer that will do the hard work */
	init_timer(&zf_timer);
	zf_timer.function = zf_ping;
	zf_timer.data = 0;

	return 0;

no_reboot:
	release_region(ZF_IOBASE, 3);
no_region:
	misc_deregister(&zf_miscdev);
out:
	return ret;
}
#endif 


#if 0
void __exit zf_exit(void)
{
	zf_timer_off();

	misc_deregister(&zf_miscdev);
	unregister_reboot_notifier(&zf_notifier);
	release_region(ZF_IOBASE, 3);
}
#endif

// markus: ignoring these for now
//module_init(zf_init);
//module_exit(zf_exit);
