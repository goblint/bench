#include <assert.h>
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }

int main() {
  int i = 0;
  while (1) {
    i++;
    int j = 0;
    while (j < 10) {
      __VERIFIER_assert(0 <= i);
      __VERIFIER_assert(i <= 10);
      j++;
    }
    if (i > 9)
      i = 0;
  }
  return 0;
}
