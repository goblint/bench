#include <linux/ioport.h>
#include <ddverify/satabs.h>
#include <ddverify/ddverify.h>
#include <ddverify/ioport.h>

struct resource *request_region(unsigned long start, unsigned long len, const char *name)
{
  unsigned int i;    
    struct resource *resource = (struct resource*)malloc(sizeof(struct resource));

    //    for (i = start; i < start + len; i++) {
    //      ddv_ioport[i] = 1;
    //    }
    ddv_ioport_request_start = start;
    ddv_ioport_request_len = len;

    return resource;
}

void release_region(unsigned long start, unsigned long len)
{
  unsigned int i = 0;

  //  for (i = start; i < start + len; i++) {
  //    ddv_ioport[i] = 0;
  //  }
  
  ddv_ioport_request_start = 0;
  ddv_ioport_request_len = 0;
}

unsigned char inb(unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);
    
    return nondet_uchar();
}

void outb(unsigned char byte, unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);
}

unsigned short inw(unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);

    return nondet_ushort();
}

void outw(unsigned short word, unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);
}

unsigned inl(unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);

    return nondet_unsigned();
}

void outl(unsigned doubleword, unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);
}


unsigned char inb_p(unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);

    return nondet_uchar();
}

void outb_p(unsigned char byte, unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);
}

unsigned short inw_p(unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);

    return nondet_ushort();
}

void outw_p(unsigned short word, unsigned int port)
{
 __CPROVER_HIDE:    
    ddv_correct_port_use(port);
}

unsigned inl_p(unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);

    return nondet_unsigned();
}

void outl_p(unsigned doubleword, unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);
}
