#ifndef __ASM_MSR_H
#define __ASM_MSR_H

#define rdmsr(msr, val1, val2) \
   do {                        \
     val1 = nondet_u32();      \
     val2 = nondet_u32();      \
   } while(0);

#endif
