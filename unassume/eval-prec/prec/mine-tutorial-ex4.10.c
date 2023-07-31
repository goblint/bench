#include <assert.h>
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }

int main() {
  int v = 1; // Not explicitly stated in Miné's example
  while (v <= 50) {
    __VERIFIER_assert(1 <= v);
    v += 2;
    __VERIFIER_assert(v <= 52);
  }
  __VERIFIER_assert(51 <= v);
  __VERIFIER_assert(v <= 52);
  return 0;
}
