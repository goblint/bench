#include <assert.h>
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }
extern _Bool __VERIFIER_nondet_bool();

int main() {
  int v = 0;
  while (__VERIFIER_nondet_bool() == 0) {
    __VERIFIER_assert(0 <= v);
    __VERIFIER_assert(v <= 1);
    if (v == 0)
      v = 1;
    // ...
  }
  return 0;
}
