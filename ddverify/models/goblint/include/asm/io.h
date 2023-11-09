#ifndef _ASM_IO_H
#define _ASM_IO_H

void * phys_to_virt(unsigned long);

#define bus_to_virt phys_to_virt

void *ioremap(unsigned long offset, unsigned long size);
void *ioremap_nocache(unsigned long offset, unsigned long size);
void iounmap(void *addr);


// DDV: Bodies for these functions are defined in linux/kernel/resource.c
unsigned char inb(unsigned int);
void outb(unsigned char byte, unsigned int);
unsigned short inw(unsigned int);
void outw(unsigned short word, unsigned int);
unsigned inl(unsigned int);
void outl(unsigned doubleword, unsigned int);


// DDV: Bodies for these functions are defined in linux/kernel/resource.c
unsigned char inb_p(unsigned int);
void outb_p(unsigned char byte, unsigned int);
unsigned short inw_p(unsigned int);
void outw_p(unsigned short word, unsigned int);
unsigned inl_p(unsigned int);
void outl_p(unsigned doubleword, unsigned int);



unsigned insb(unsigned int, void *addr, unsigned long count);
void outsb(unsigned int, void *addr, unsigned long count);

unsigned insw(unsigned int, void *addr, unsigned long count);
void outsw(unsigned int, void *addr, unsigned long count);

unsigned insl(unsigned int, void *addr, unsigned long count);
void outsl(unsigned int, void *addr, unsigned long count);



unsigned int ioread8(void *addr);
unsigned int ioread16(void *addr);
unsigned int ioread32(void *addr);

void iowrite8(u8 value, void *addr);
void iowrite16(u16 value, void *addr);
void iowrite32(u32 value, void *addr);

void ioread8_rep(void *addr, void *buf, unsigned long count);
void ioread16_rep(void *addr, void *buf, unsigned long count);
void ioread32_rep(void *addr, void *buf, unsigned long count);

void iowrite8_rep(void *addr, const void *buf, unsigned long count);
void iowrite16_rep(void *addr, const void *buf, unsigned long count);
void iowrite32_rep(void *addr, const void *buf, unsigned long count);

// DDV: no bodies required for these functions:
unsigned char readb(const void *);
unsigned short readw(const void *);
unsigned int readl(const void *);

// DDV: no bodies required for these functions:
void writeb(unsigned char, void *);
void writew(unsigned short, void *);
void writel(unsigned int, void *);

#endif
