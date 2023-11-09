#ifndef _ASM_HIGHMEM_H
#define _ASM_HIGHMEM_H

#include <linux/interrupt.h>
//#include <linux/threads.h>
#include <asm/kmap_types.h>
//#include <asm/tlbflush.h>


void *kmap(struct page *page);
void kunmap(struct page *page);
void *kmap_atomic(struct page *page, enum km_type type);
void kunmap_atomic(void *kvaddr, enum km_type type);
void *kmap_atomic_pfn(unsigned long pfn, enum km_type type);
struct page *kmap_atomic_to_page(void *ptr);

#endif /* _ASM_HIGHMEM_H */
