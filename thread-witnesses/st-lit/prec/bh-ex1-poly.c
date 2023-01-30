#include <assert.h>
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }

int main() {
  int i = 0;
  while (i < 4) {
    int j = 0;
    while (j < 3) {
      i++;
      j += 2;
      __VERIFIER_assert(0 <= j);
      __VERIFIER_assert(j <= 2 * i);
      __VERIFIER_assert(2 * i <= j + 6);
      __VERIFIER_assert(j <= 4);
    }
    __VERIFIER_assert(0 <= j);
    __VERIFIER_assert(j <= 2 * i);
    __VERIFIER_assert(2 * i <= j + 6);
    __VERIFIER_assert(j <= 4);
    i = i - j / 2 + 1;
  }
  return 0;
}
