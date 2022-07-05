#include <stdlib.h>
#include <pthread.h>
#include <assert.h>

#define SIZE 50
#define ERROR -1

volatile int lock1 = 0;
volatile int lock2 = 0;
volatile int counter = 0;

//void __VERIFIER_atomic_acquire1() {
//  __VERIFIER_assume(lock1 == 0);
//  lock1 = 1;
//}
//void __VERIFIER_atomic_release1() {
//  __VERIFIER_assume(lock1 == 1);
//  lock1 = 0;
//u
//void __VERIFIER_atomic_acquire2() {
//  __VERIFIER_assume(lock2 == 0);
//  lock2 = 1;
//}
//void __VERIFIER_atomic_release2() {
//  __VERIFIER_assume(lock2 == 1);
//  lock2 = 0;
//}

void* producer(void *arg) {
  //int batch = __VERIFIER_nondet_int();
  int batch;
  //__VERIFIER_atomic_acquire2();
  //while (lock2) { }
  lock2 = 1;
  //__VERIFIER_atomic_acquire1();
  //while (lock1) { }
  lock1 = 1;
  if (counter > 0) {
    counter++;
    //__VERIFIER_atomic_release1();
    lock1 = 0;
    //__VERIFIER_atomic_release2();
    lock2 = 0;
    return (void *)1;
  } else {
    //__VERIFIER_atomic_release1();
    lock1 = 0;
    counter = 0;
    //while (batch > 0) {
    if (batch > 0) {
      counter++;
      batch--;
    }
    //}
    batch = counter;
    //__VERIFIER_atomic_release2();
    lock2 = 0;
    return (void *)batch;
  }
  return NULL;
}

void* consumer(void *arg) {
  //while (1) {
    //__VERIFIER_atomic_acquire1();
    //while (lock1) { }
    lock1 = 1;
    //if (counter > 0) { break; }
    if (counter > 0) { lock1 = 0; return NULL; }
    //__VERIFIER_atomic_release1();
    lock1 = 0;
  //}
  counter--;
  //__VERIFIER_assert(counter >= 0);
  assert(counter >= 0);
  //__VERIFIER_atomic_release1();
  lock1 = 0;
  return NULL;
}

int main () {
  pthread_t t;
  //counter = 0;
  //lock1 = 0;
  //lock2 = 0;
  int i =0;
  pthread_create(&t, 0, producer, 0);
  pthread_create(&t, 0, consumer, 0);
  return 0;
}
