#ifndef __LINUX_PARPORT_PC_H
#define __LINUX_PARPORT_PC_H

#include <asm/io.h>

/* --- register definitions ------------------------------- */

#define ECONTROL(p) ((p)->base_hi + 0x2)
#define CONFIGB(p)  ((p)->base_hi + 0x1)
#define CONFIGA(p)  ((p)->base_hi + 0x0)
#define FIFO(p)     ((p)->base_hi + 0x0)
#define EPPDATA(p)  ((p)->base    + 0x4)
#define EPPADDR(p)  ((p)->base    + 0x3)
#define CONTROL(p)  ((p)->base    + 0x2)
#define STATUS(p)   ((p)->base    + 0x1)
#define DATA(p)     ((p)->base    + 0x0)

struct parport_pc_private {
  int something;
};

struct parport_pc_via_data
{
  int something;
};

void parport_pc_write_data(struct parport *p, unsigned char d);
unsigned char parport_pc_read_data(struct parport *p);
void parport_pc_data_reverse (struct parport *p);
void parport_pc_data_forward (struct parport *p);
void parport_pc_write_control (struct parport *p, unsigned char d);
unsigned char parport_pc_read_control(struct parport *p);
unsigned char parport_pc_frob_control (struct parport *p,
				       unsigned char mask,
				       unsigned char val);
unsigned char parport_pc_read_status(struct parport *p);
void parport_pc_disable_irq(struct parport *p);
void parport_pc_enable_irq(struct parport *p);
void parport_pc_release_resources(struct parport *p);
int parport_pc_claim_resources(struct parport *p);

#endif
