/**
 * Author: Markus Kusano
 *
 * Apated from Farzan and Kincaid: Verification of parameterized concurrent
 * programs by modular reasoning about data and control. POPL 2012.
 *
 * This program is based on the motivating example in their paper.
 *
 */
#include <assert.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 50
#define ERROR -1

int lock1 = INT_MAX;
int lock2 = INT_MAX;
int counter = INT_MAX;

// Manually un-rolled
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

void *producer(void *arg) {
  while (lock2) {
    // spin
  }
  // Lock acquire
  lock2 = 1;
  while (lock1) { 
    // spin
  }
  // Lock acquire
  if (counter > 0) {
    lock1 = 0;
    lock2 = 0;
    return NULL;
  }
  else {
    lock1 = 1;
    counter++;
    lock1 = 0;
    return NULL;
  }
}

void *consumer(void *arg) {
  while (lock1) { 
    // spin
  } 
  // acquire lock
  lock1 = 1;
  if (counter <= 0) { 
    lock1 = 0; 
    return NULL;
  }
  counter--;
  if (counter < 0) {
    assert(0);
  }
  lock1 = 0;
  return NULL;
}

int main() {
  lock1 = 0;
  counter = 0;
  pthread_t t1, t2;
  pthread_create(&t1, NULL, producer, NULL);
  pthread_create(&t2, NULL, consumer, NULL);
  pthread_exit(NULL);
}
