// Thread-local variable flow-sensitive value analysis.
// Variation that checks if thread-local values are handled by race detectors.

#include <stdlib.h>
#include <pthread.h>

extern void abort(void);
void assume_abort_if_not(int cond) {
  if(!cond) {abort();}
}
extern int __VERIFIER_nondet_int();

__thread int data = 0;
int shared = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread(void *arg) {
  data = 1;
  if (data == 1) pthread_mutex_lock(&mutex);
  shared++; // NORACE
  if (data == 1) pthread_mutex_unlock(&mutex);
  return NULL;
}

int main() {
  int threads_total = __VERIFIER_nondet_int();
  assume_abort_if_not(threads_total >= 0);

  pthread_t *tids = malloc(threads_total * sizeof(pthread_t));

  // create threads
  for (int i = 0; i < threads_total; i++) {
    pthread_create(&tids[i], NULL, &thread, NULL); // may fail but doesn't matter
  }

  // join threads
  for (int i = 0; i < threads_total; i++) {
    pthread_join(tids[i], NULL);
  }

  free(tids);

  return 0;
}
