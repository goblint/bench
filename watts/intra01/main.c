// Author: Markus Kusano
//
// Testing intra-thread load-store constraints.
// Consider the following thread:
//
// t1 = load x
// store 5 x
// t2 = load x
//
// if t1 loads from some interference, then t2 should not be able to read
// from the same interference. This is because the store dominating the load
// will overwrite the interference
#include <pthread.h>
#include <assert.h>

int x = 0;
void *thread1(void *unused) {
  int t1 = x;
  if (t1 == 10) {
    x = 5;
    if (x != 5) {
      assert(0);
    }
  }
  return NULL;
}

void *thread2(void *unused) {
  x = 10;
  return NULL;
}

int main() {
  pthread_t t1;
  pthread_t t2;

  pthread_create(&t1, NULL, thread1, NULL);
  pthread_create(&t2, NULL, thread2, NULL);

  return 0;
}
