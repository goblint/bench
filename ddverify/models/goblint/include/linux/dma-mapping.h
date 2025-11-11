#ifndef _ASM_LINUX_DMA_MAPPING_H
#define _ASM_LINUX_DMA_MAPPING_H

#include <linux/device.h>
#include <linux/err.h>


#define DMA_64BIT_MASK	(unsigned long long int)0xffffffffffffffff
#define DMA_48BIT_MASK	(unsigned long long int)0x0000ffffffffffff
#define DMA_40BIT_MASK	(unsigned long long int)0x000000ffffffffff
#define DMA_39BIT_MASK	(unsigned long long int)0x0000007fffffffff
#define DMA_32BIT_MASK	(unsigned long long int)0x00000000ffffffff
#define DMA_31BIT_MASK	(unsigned long long int)0x000000007fffffff
#define DMA_30BIT_MASK	(unsigned long long int)0x000000003fffffff
#define DMA_29BIT_MASK	(unsigned long long int)0x000000001fffffff
#define DMA_28BIT_MASK	(unsigned long long int)0x000000000fffffff
#define DMA_24BIT_MASK	(unsigned long long int)0x0000000000ffffff

#endif
