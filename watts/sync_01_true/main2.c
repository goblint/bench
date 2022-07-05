// Author: Markus Kusano
// Adapted from svcomp15/pthread/sync01_true-unreach-call.c
//#include <assert.h>
#include <pthread.h>

// Incremented by thread1 and decremented by thread 2
int num = 0;
// Synchronizes the increment/decrement
int cond = 0;

void *thread1(void *unused) {
  num++;
  cond = 1;
  return NULL;
}

void *thread2(void *unused) {
  while (!cond) { }
  //if (cond) {
    int t1 = num;
    t1--;
    num = t1;
    if (t1 != 0) {
      assert(0);
    }
  //}
  return NULL;
}

int main() {
  pthread_t t1;
  pthread_t t2;
  pthread_create(&t1, NULL, thread1, NULL);
  pthread_create(&t2, NULL, thread2, NULL);

  return 0;
}

