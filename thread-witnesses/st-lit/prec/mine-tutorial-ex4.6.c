#include <assert.h>
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }

int main() {
  int x = 40;
  while (x != 0) {
    __VERIFIER_assert(x <= 40);
    x--;
    __VERIFIER_assert(x >= 0);
  }
  __VERIFIER_assert(x == 0); // no witness needed, just by invariant
  return 0;
}
