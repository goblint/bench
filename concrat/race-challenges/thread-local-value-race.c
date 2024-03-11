// Thread-local variable flow-sensitive value analysis.
// Extracted from silver searcher.
#include <stdlib.h>
#include <pthread.h>
extern void abort(void);
void assume_abort_if_not(int cond) {
  if(!cond) {abort();}
}
#include <assert.h>
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: {reach_error();abort();}
  }
  return;
}
extern int __VERIFIER_nondet_int();

__thread int data = 0;

int* ptr = NULL;
pthread_mutex_t ptr_mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread(void *arg) {
  pthread_mutex_lock(&ptr_mutex);
  ptr = &data; // pointer to thread-local data escapes
  pthread_mutex_unlock(&ptr_mutex);

  pthread_mutex_lock(&ptr_mutex);
  *ptr = 2; // RACE!
  pthread_mutex_unlock(&ptr_mutex);

  // stay alive to avoid thread-local data deallocation and use after free
  while (1) {
    data = 1; // RACE!
  }
  return NULL;
}

int main() {
  int breads_total = __VERIFIER_nondet_int();
  assume_abort_if_not(breads_total >= 0);

  pthread_t *tids = malloc(breads_total * sizeof(pthread_t));

  // create threads
  for (int i = 0; i < breads_total; i++) {
    pthread_create(&tids[i], NULL, &thread, NULL); // may fail but doesn't matter
  }

  // join threads
  for (int i = 0; i < breads_total; i++) {
    pthread_join(tids[i], NULL);
  }

  free(tids);

  return 0;
}
