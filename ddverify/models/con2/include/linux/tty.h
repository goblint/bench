#ifndef _LINUX_TTY_H
#define _LINUX_TTY_H

#include <linux/fs.h>
#include <linux/major.h>
#include <linux/termios.h>
#include <linux/workqueue.h>
#include <linux/tty_driver.h>
#include <linux/tty_ldisc.h>
#include <linux/mutex.h>

#include <asm/system.h>


/*
 * The pty uses char_buf and flag_buf as a contiguous buffer
 */
#define PTY_BUF_SIZE	4*TTY_FLIPBUF_SIZE

/*
 * When a break, frame error, or parity error happens, these codes are
 * stuffed into the flags buffer.
 */
#define TTY_NORMAL	0
#define TTY_BREAK	1
#define TTY_FRAME	2
#define TTY_PARITY	3
#define TTY_OVERRUN	4


#define INTR_CHAR(tty) ((tty)->termios->c_cc[VINTR])
#define QUIT_CHAR(tty) ((tty)->termios->c_cc[VQUIT])
#define ERASE_CHAR(tty) ((tty)->termios->c_cc[VERASE])
#define KILL_CHAR(tty) ((tty)->termios->c_cc[VKILL])
#define EOF_CHAR(tty) ((tty)->termios->c_cc[VEOF])
#define TIME_CHAR(tty) ((tty)->termios->c_cc[VTIME])
#define MIN_CHAR(tty) ((tty)->termios->c_cc[VMIN])
#define SWTC_CHAR(tty) ((tty)->termios->c_cc[VSWTC])
#define START_CHAR(tty) ((tty)->termios->c_cc[VSTART])
#define STOP_CHAR(tty) ((tty)->termios->c_cc[VSTOP])
#define SUSP_CHAR(tty) ((tty)->termios->c_cc[VSUSP])
#define EOL_CHAR(tty) ((tty)->termios->c_cc[VEOL])
#define REPRINT_CHAR(tty) ((tty)->termios->c_cc[VREPRINT])
#define DISCARD_CHAR(tty) ((tty)->termios->c_cc[VDISCARD])
#define WERASE_CHAR(tty) ((tty)->termios->c_cc[VWERASE])
#define LNEXT_CHAR(tty)	((tty)->termios->c_cc[VLNEXT])
#define EOL2_CHAR(tty) ((tty)->termios->c_cc[VEOL2])

#define _I_FLAG(tty,f)	((tty)->termios->c_iflag & (f))
#define _O_FLAG(tty,f)	((tty)->termios->c_oflag & (f))
#define _C_FLAG(tty,f)	((tty)->termios->c_cflag & (f))
#define _L_FLAG(tty,f)	((tty)->termios->c_lflag & (f))

#define I_IGNBRK(tty)	_I_FLAG((tty),IGNBRK)
#define I_BRKINT(tty)	_I_FLAG((tty),BRKINT)
#define I_IGNPAR(tty)	_I_FLAG((tty),IGNPAR)
#define I_PARMRK(tty)	_I_FLAG((tty),PARMRK)
#define I_INPCK(tty)	_I_FLAG((tty),INPCK)
#define I_ISTRIP(tty)	_I_FLAG((tty),ISTRIP)
#define I_INLCR(tty)	_I_FLAG((tty),INLCR)
#define I_IGNCR(tty)	_I_FLAG((tty),IGNCR)
#define I_ICRNL(tty)	_I_FLAG((tty),ICRNL)
#define I_IUCLC(tty)	_I_FLAG((tty),IUCLC)
#define I_IXON(tty)	_I_FLAG((tty),IXON)
#define I_IXANY(tty)	_I_FLAG((tty),IXANY)
#define I_IXOFF(tty)	_I_FLAG((tty),IXOFF)
#define I_IMAXBEL(tty)	_I_FLAG((tty),IMAXBEL)
#define I_IUTF8(tty)	_I_FLAG((tty),IUTF8)

#define O_OPOST(tty)	_O_FLAG((tty),OPOST)
#define O_OLCUC(tty)	_O_FLAG((tty),OLCUC)
#define O_ONLCR(tty)	_O_FLAG((tty),ONLCR)
#define O_OCRNL(tty)	_O_FLAG((tty),OCRNL)
#define O_ONOCR(tty)	_O_FLAG((tty),ONOCR)
#define O_ONLRET(tty)	_O_FLAG((tty),ONLRET)
#define O_OFILL(tty)	_O_FLAG((tty),OFILL)
#define O_OFDEL(tty)	_O_FLAG((tty),OFDEL)
#define O_NLDLY(tty)	_O_FLAG((tty),NLDLY)
#define O_CRDLY(tty)	_O_FLAG((tty),CRDLY)
#define O_TABDLY(tty)	_O_FLAG((tty),TABDLY)
#define O_BSDLY(tty)	_O_FLAG((tty),BSDLY)
#define O_VTDLY(tty)	_O_FLAG((tty),VTDLY)
#define O_FFDLY(tty)	_O_FLAG((tty),FFDLY)

#define C_BAUD(tty)	_C_FLAG((tty),CBAUD)
#define C_CSIZE(tty)	_C_FLAG((tty),CSIZE)
#define C_CSTOPB(tty)	_C_FLAG((tty),CSTOPB)
#define C_CREAD(tty)	_C_FLAG((tty),CREAD)
#define C_PARENB(tty)	_C_FLAG((tty),PARENB)
#define C_PARODD(tty)	_C_FLAG((tty),PARODD)
#define C_HUPCL(tty)	_C_FLAG((tty),HUPCL)
#define C_CLOCAL(tty)	_C_FLAG((tty),CLOCAL)
#define C_CIBAUD(tty)	_C_FLAG((tty),CIBAUD)
#define C_CRTSCTS(tty)	_C_FLAG((tty),CRTSCTS)

#define L_ISIG(tty)	_L_FLAG((tty),ISIG)
#define L_ICANON(tty)	_L_FLAG((tty),ICANON)
#define L_XCASE(tty)	_L_FLAG((tty),XCASE)
#define L_ECHO(tty)	_L_FLAG((tty),ECHO)
#define L_ECHOE(tty)	_L_FLAG((tty),ECHOE)
#define L_ECHOK(tty)	_L_FLAG((tty),ECHOK)
#define L_ECHONL(tty)	_L_FLAG((tty),ECHONL)
#define L_NOFLSH(tty)	_L_FLAG((tty),NOFLSH)
#define L_TOSTOP(tty)	_L_FLAG((tty),TOSTOP)
#define L_ECHOCTL(tty)	_L_FLAG((tty),ECHOCTL)
#define L_ECHOPRT(tty)	_L_FLAG((tty),ECHOPRT)
#define L_ECHOKE(tty)	_L_FLAG((tty),ECHOKE)
#define L_FLUSHO(tty)	_L_FLAG((tty),FLUSHO)
#define L_PENDIN(tty)	_L_FLAG((tty),PENDIN)
#define L_IEXTEN(tty)	_L_FLAG((tty),IEXTEN)


struct tty_struct {
	int	magic;
	struct tty_driver *driver;
	int index;
	struct termios *termios, *termios_locked;
	char name[64];

	unsigned long flags;
	int count;
	unsigned char stopped:1, hw_stopped:1, flow_stopped:1, packet:1;
	unsigned int receive_room;	/* Bytes free for queue */

	wait_queue_head_t write_wait;
	wait_queue_head_t read_wait;
	void *disc_data;
	void *driver_data;

	unsigned char closing:1;
};


/* tty magic number */
#define TTY_MAGIC		0x5401

/*
 * These bits are used in the flags field of the tty structure.
 * 
 * So that interrupts won't be able to mess up the queues,
 * copy_to_cooked must be atomic with respect to itself, as must
 * tty->write.  Thus, you must use the inline functions set_bit() and
 * clear_bit() to make things atomic.
 */
#define TTY_THROTTLED 		0	/* Call unthrottle() at threshold min */
#define TTY_IO_ERROR 		1	/* Canse an I/O error (may be no ldisc too) */
#define TTY_OTHER_CLOSED 	2	/* Other side (if any) has closed */
#define TTY_EXCLUSIVE 		3	/* Exclusive open mode */
#define TTY_DEBUG 		4	/* Debugging */
#define TTY_DO_WRITE_WAKEUP 	5	/* Call write_wakeup after queuing new */
#define TTY_PUSH 		6	/* n_tty private */
#define TTY_CLOSING 		7	/* ->close() in progress */
#define TTY_LDISC 		9	/* Line discipline attached */
#define TTY_HW_COOK_OUT 	14	/* Hardware can do output cooking */
#define TTY_HW_COOK_IN 		15	/* Hardware can do input cooking */
#define TTY_PTY_LOCK 		16	/* pty private */
#define TTY_NO_WRITE_SPLIT 	17	/* Preserve write boundaries to driver */
#define TTY_HUPPED 		18	/* Post driver->hangup() */

extern struct termios tty_std_termios;


extern int tty_check_change(struct tty_struct * tty);
extern int tty_register_ldisc(int disc, struct tty_ldisc *new_ldisc);
extern int tty_unregister_ldisc(int disc);
extern int tty_register_driver(struct tty_driver *driver);
extern int tty_unregister_driver(struct tty_driver *driver);

extern void tty_wait_until_sent(struct tty_struct * tty, long timeout);


extern void tty_hangup(struct tty_struct * tty);
extern int tty_hung_up_p(struct file * filp);
extern void do_SAK(struct tty_struct *tty);
extern void tty_flip_buffer_push(struct tty_struct *tty);
extern int tty_get_baud_rate(struct tty_struct *tty);

extern void tty_wakeup(struct tty_struct *tty);
extern void tty_ldisc_flush(struct tty_struct *tty);
#endif
