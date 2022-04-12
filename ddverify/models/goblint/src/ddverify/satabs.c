#include <ddverify/satabs.h>

#define nondet2(X, Y) X nondet_##Y() { X val; return val; }
#define nondet(X) nondet2(X, X)

nondet(short)
nondet2(unsigned short, ushort)
nondet(int)
nondet2(unsigned int, uint)
nondet(long)
nondet2(unsigned long, ulong)
nondet(char)
nondet2(unsigned char, uchar)
nondet2(unsigned, unsigned)
nondet(loff_t)
nondet(size_t)
nondet(sector_t)
nondet(u32)
nondet2(char*, pchar)
nondet2(enum __bool, bool)


void noop() {

}


void __CPROVER_atomic_begin() {
    __VERIFIER_atomic_begin();
}

void __CPROVER_atomic_end() {
    __VERIFIER_atomic_end();
}


void __CPROVER_assume(int expression) { if (!expression) { LOOP: goto LOOP; }; return; }
