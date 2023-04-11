#include <assert.h>
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }

int main() {
  int i = 0;
  while (i < 100) {
    int j = 0;
    while (j < 100) {
      j++;
      __VERIFIER_assert(j <= 100);
    }
    __VERIFIER_assert(j == 100);
    i++;
    __VERIFIER_assert(i <= 100);
  }
  __VERIFIER_assert(i == 100);
  return 0;
}
