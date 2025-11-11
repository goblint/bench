#ifndef _I386_BITOPS_H
#define _I386_BITOPS_H

void set_bit(int nr, unsigned long * addr);

int test_and_set_bit(int nr, unsigned long * addr);
int test_and_clear_bit(int nr, unsigned long * addr);
int test_and_change_bit(int nr, unsigned long* addr);
int test_bit(int nr, const void * addr);
void clear_bit(int nr, volatile unsigned long * addr);
int find_first_zero_bit(const unsigned long *addr, unsigned size);

#endif /* _I386_BITOPS_H */
