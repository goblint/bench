#ifndef _LINUX_TTY_DRIVER_H
#define _LINUX_TTY_DRIVER_H


#include <linux/fs.h>
#include <linux/list.h>
#include <linux/cdev.h>

struct tty_struct;


struct tty_operations {
	int  (*open)(struct tty_struct * tty, struct file * filp);
	void (*close)(struct tty_struct * tty, struct file * filp);
	int  (*write)(struct tty_struct * tty,
		      const unsigned char *buf, int count);
	void (*put_char)(struct tty_struct *tty, unsigned char ch);
	void (*flush_chars)(struct tty_struct *tty);
	int  (*write_room)(struct tty_struct *tty);
	int  (*chars_in_buffer)(struct tty_struct *tty);
	int  (*ioctl)(struct tty_struct *tty, struct file * file,
		    unsigned int cmd, unsigned long arg);
	void (*set_termios)(struct tty_struct *tty, struct termios * old);
	void (*throttle)(struct tty_struct * tty);
	void (*unthrottle)(struct tty_struct * tty);
	void (*stop)(struct tty_struct *tty);
	void (*start)(struct tty_struct *tty);
	void (*hangup)(struct tty_struct *tty);
	void (*break_ctl)(struct tty_struct *tty, int state);
	void (*flush_buffer)(struct tty_struct *tty);
	void (*set_ldisc)(struct tty_struct *tty);
	void (*wait_until_sent)(struct tty_struct *tty, int timeout);
	void (*send_xchar)(struct tty_struct *tty, char ch);
	int (*read_proc)(char *page, char **start, off_t off,
			  int count, int *eof, void *data);
	int (*write_proc)(struct file *file, const char __user *buffer,
			  unsigned long count, void *data);
	int (*tiocmget)(struct tty_struct *tty, struct file *file);
	int (*tiocmset)(struct tty_struct *tty, struct file *file,
			unsigned int set, unsigned int clear);
};

struct tty_driver {
	int	magic;		/* magic number for this structure */
	struct cdev cdev;
	struct module	*owner;
	const char	*driver_name;
	const char	*name;
	int	name_base;	/* offset of printed name */
	int	major;		/* major device number */
	int	minor_start;	/* start of minor device number */
	int	minor_num;	/* number of *possible* devices */
	int	num;		/* number of devices allocated */
	short	type;		/* type of tty driver */
	short	subtype;	/* subtype of tty driver */
	struct termios init_termios; /* Initial termios */
	int	flags;		/* tty driver flags */
	int	refcount;	/* for loadable tty drivers */
	struct proc_dir_entry *proc_entry; /* /proc fs entry */

	/*
	 * Interface routines from the upper tty layer to the tty
	 * driver.	Will be replaced with struct tty_operations.
	 */
	int  (*open)(struct tty_struct * tty, struct file * filp);
	void (*close)(struct tty_struct * tty, struct file * filp);
	int  (*write)(struct tty_struct * tty,
		      const unsigned char *buf, int count);
	void (*put_char)(struct tty_struct *tty, unsigned char ch);
	void (*flush_chars)(struct tty_struct *tty);
	int  (*write_room)(struct tty_struct *tty);
	int  (*chars_in_buffer)(struct tty_struct *tty);
	int  (*ioctl)(struct tty_struct *tty, struct file * file,
		    unsigned int cmd, unsigned long arg);
	void (*set_termios)(struct tty_struct *tty, struct termios * old);
	void (*throttle)(struct tty_struct * tty);
	void (*unthrottle)(struct tty_struct * tty);
	void (*stop)(struct tty_struct *tty);
	void (*start)(struct tty_struct *tty);
	void (*hangup)(struct tty_struct *tty);
	void (*break_ctl)(struct tty_struct *tty, int state);
	void (*flush_buffer)(struct tty_struct *tty);
	void (*set_ldisc)(struct tty_struct *tty);
	void (*wait_until_sent)(struct tty_struct *tty, int timeout);
	void (*send_xchar)(struct tty_struct *tty, char ch);
	int (*read_proc)(char *page, char **start, off_t off,
			  int count, int *eof, void *data);
	int (*write_proc)(struct file *file, const char __user *buffer,
			  unsigned long count, void *data);
	int (*tiocmget)(struct tty_struct *tty, struct file *file);
	int (*tiocmset)(struct tty_struct *tty, struct file *file,
			unsigned int set, unsigned int clear);
};


// DDV: is defined in driver/char/tty_io.c
struct tty_driver *alloc_tty_driver(int lines);
// DDV: TODO
void put_tty_driver(struct tty_driver *driver);
// DDV: is defined in driver/char/tty_io.c
void tty_set_operations(struct tty_driver *driver,
			const struct tty_operations *op);

/* tty driver magic number */
#define TTY_DRIVER_MAGIC		0x5402

/*
 * tty driver flags
 * 
 * TTY_DRIVER_RESET_TERMIOS --- requests the tty layer to reset the
 * 	termios setting when the last process has closed the device.
 * 	Used for PTY's, in particular.
 * 
 * TTY_DRIVER_REAL_RAW --- if set, indicates that the driver will
 * 	guarantee never not to set any special character handling
 * 	flags if ((IGNBRK || (!BRKINT && !PARMRK)) && (IGNPAR ||
 * 	!INPCK)).  That is, if there is no reason for the driver to
 * 	send notifications of parity and break characters up to the
 * 	line driver, it won't do so.  This allows the line driver to
 *	optimize for this case if this flag is set.  (Note that there
 * 	is also a promise, if the above case is true, not to signal
 * 	overruns, either.)
 *
 * TTY_DRIVER_DYNAMIC_DEV --- if set, the individual tty devices need
 *	to be registered with a call to tty_register_driver() when the
 *	device is found in the system and unregistered with a call to
 *	tty_unregister_device() so the devices will be show up
 *	properly in sysfs.  If not set, driver->num entries will be
 *	created by the tty core in sysfs when tty_register_driver() is
 *	called.  This is to be used by drivers that have tty devices
 *	that can appear and disappear while the main tty driver is
 *	registered with the tty core.
 *
 * TTY_DRIVER_DEVPTS_MEM -- don't use the standard arrays, instead
 *	use dynamic memory keyed through the devpts filesystem.  This
 *	is only applicable to the pty driver.
 */
#define TTY_DRIVER_INSTALLED		0x0001
#define TTY_DRIVER_RESET_TERMIOS	0x0002
#define TTY_DRIVER_REAL_RAW		0x0004
#define TTY_DRIVER_DYNAMIC_DEV		0x0008
#define TTY_DRIVER_DEVPTS_MEM		0x0010

/* tty driver types */
#define TTY_DRIVER_TYPE_SYSTEM		0x0001
#define TTY_DRIVER_TYPE_CONSOLE		0x0002
#define TTY_DRIVER_TYPE_SERIAL		0x0003
#define TTY_DRIVER_TYPE_PTY		0x0004
#define TTY_DRIVER_TYPE_SCC		0x0005	/* scc driver */
#define TTY_DRIVER_TYPE_SYSCONS		0x0006

/* system subtypes (magic, used by tty_io.c) */
#define SYSTEM_TYPE_TTY			0x0001
#define SYSTEM_TYPE_CONSOLE		0x0002
#define SYSTEM_TYPE_SYSCONS		0x0003
#define SYSTEM_TYPE_SYSPTMX		0x0004

/* pty subtypes (magic, used by tty_io.c) */
#define PTY_TYPE_MASTER			0x0001
#define PTY_TYPE_SLAVE			0x0002

/* serial subtype definitions */
#define SERIAL_TYPE_NORMAL	1


#endif /* #ifdef _LINUX_TTY_DRIVER_H */
