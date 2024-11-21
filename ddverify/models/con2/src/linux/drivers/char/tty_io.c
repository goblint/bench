#include <linux/tty.h>
#include <ddverify/tty.h>

struct tty_driver *alloc_tty_driver(int lines)
{
  if (!global_tty_driver.allocated) {
    global_tty_driver.driver.magic = TTY_DRIVER_MAGIC;
    global_tty_driver.driver.num   = lines;
  } else {
    return NULL;
  }
}

void tty_set_operations(struct tty_driver *driver,
			const struct tty_operations *op)
{
  driver->open = op->open;
  driver->close = op->close;
  driver->write = op->write;
  driver->put_char = op->put_char;
  driver->flush_chars = op->flush_chars;
  driver->write_room = op->write_room;
  driver->chars_in_buffer = op->chars_in_buffer;
  driver->ioctl = op->ioctl;
  driver->set_termios = op->set_termios;
  driver->throttle = op->throttle;
  driver->unthrottle = op->unthrottle;
  driver->stop = op->stop;
  driver->start = op->start;
  driver->hangup = op->hangup;
  driver->break_ctl = op->break_ctl;
  driver->flush_buffer = op->flush_buffer;
  driver->set_ldisc = op->set_ldisc;
  driver->wait_until_sent = op->wait_until_sent;
  driver->send_xchar = op->send_xchar;
  driver->read_proc = op->read_proc;
  driver->write_proc = op->write_proc;
  driver->tiocmget = op->tiocmget;
  driver->tiocmset = op->tiocmset;
}
