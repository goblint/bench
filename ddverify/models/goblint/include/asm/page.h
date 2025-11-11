#ifndef _I386_PAGE_H
#define _I386_PAGE_H

/* PAGE_SHIFT determines the page size */
#define PAGE_SHIFT	12
#define PAGE_SIZE	(1UL << PAGE_SHIFT)
#define PAGE_MASK	(~(PAGE_SIZE-1))

//#include <asm-generic/page.h>


// DDV: taken from arch/i386/defconfig
#define CONFIG_PAGE_OFFSET 0xC0000000
// DDV: taken from arch/i386/defconfig
#define CONFIG_PHYSICAL_START 0x100000

#define __PAGE_OFFSET		((unsigned long)CONFIG_PAGE_OFFSET)
#define __PHYSICAL_START	((unsigned long)CONFIG_PHYSICAL_START)

#define PAGE_OFFSET		((unsigned long)__PAGE_OFFSET)
#define VMALLOC_RESERVE		((unsigned long)__VMALLOC_RESERVE)
#define MAXMEM			(-__PAGE_OFFSET-__VMALLOC_RESERVE)

#endif /* _I386_PAGE_H */
