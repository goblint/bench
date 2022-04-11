#include <linux/ioport.h>
#include <ddverify/satabs.h>
#include <ddverify/ddverify.h>
#include <ddverify/ioport.h>

int ddv_ioport_request_start;
int ddv_ioport_request_len;

inline struct resource *request_region(unsigned long start, unsigned long len, const char *name)
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

inline void release_region(unsigned long start, unsigned long len)
{
  unsigned int i = 0;

  //  for (i = start; i < start + len; i++) {
  //    ddv_ioport[i] = 0;
  //  }
  
  ddv_ioport_request_start = 0;
  ddv_ioport_request_len = 0;
}

inline unsigned char inb(unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);
    
    return nondet_uchar();
}

inline void outb(unsigned char byte, unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);
}

inline unsigned short inw(unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);

    return nondet_ushort();
}

inline void outw(unsigned short word, unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);
}

inline unsigned inl(unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);

    return nondet_unsigned();
}

inline void outl(unsigned doubleword, unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);
}

inline unsigned char inb_p(unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);

    return nondet_uchar();
}

inline void outb_p(unsigned char byte, unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);
}

inline unsigned short inw_p(unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);

    return nondet_ushort();
}

inline void outw_p(unsigned short word, unsigned int port)
{
 __CPROVER_HIDE:    
    ddv_correct_port_use(port);
}

inline unsigned inl_p(unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);

    return nondet_unsigned();
}

inline void outl_p(unsigned doubleword, unsigned int port)
{
 __CPROVER_HIDE:
    ddv_correct_port_use(port);
}
