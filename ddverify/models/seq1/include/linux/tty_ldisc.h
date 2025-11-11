#ifndef _LINUX_TTY_LDISC_H
#define _LINUX_TTY_LDISC_H


#include <linux/fs.h>
#include <linux/wait.h>

struct tty_ldisc {
	int	magic;
	char	*name;
	int	num;
	int	flags;
	
	/*
	 * The following routines are called from above.
	 */
	int	(*open)(struct tty_struct *);
	void	(*close)(struct tty_struct *);
	void	(*flush_buffer)(struct tty_struct *tty);
	ssize_t	(*chars_in_buffer)(struct tty_struct *tty);
	ssize_t	(*read)(struct tty_struct * tty, struct file * file,
			unsigned char __user * buf, size_t nr);
	ssize_t	(*write)(struct tty_struct * tty, struct file * file,
			 const unsigned char * buf, size_t nr);	
	int	(*ioctl)(struct tty_struct * tty, struct file * file,
			 unsigned int cmd, unsigned long arg);
	void	(*set_termios)(struct tty_struct *tty, struct termios * old);
	unsigned int (*poll)(struct tty_struct *, struct file *,
			     struct poll_table_struct *);
	int	(*hangup)(struct tty_struct *tty);
	
	/*
	 * The following routines are called from below.
	 */
	void	(*receive_buf)(struct tty_struct *, const unsigned char *cp,
			       char *fp, int count);
	void	(*write_wakeup)(struct tty_struct *);

	struct  module *owner;
	
	int refcount;
};

#define TTY_LDISC_MAGIC	0x5403

#define LDISC_FLAG_DEFINED	0x00000001

#define MODULE_ALIAS_LDISC(ldisc) \
	MODULE_ALIAS("tty-ldisc-" __stringify(ldisc))

#endif /* _LINUX_TTY_LDISC_H */
