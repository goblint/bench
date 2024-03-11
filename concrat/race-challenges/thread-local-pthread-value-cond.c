// Thread-local pthread variable flow-sensitive value analysis.
// Variation that checks if thread-local values are handled by race detectors.
#include <stdlib.h>
#include <pthread.h>
extern void abort(void);
void assume_abort_if_not(int cond) {
  if(!cond) {abort();}
}
extern int __VERIFIER_nondet_int();

pthread_key_t key;

int shared = 0;
pthread_mutex_t shared_mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread(void *arg) {
  int x, y;
  pthread_setspecific(key, &x);
  pthread_setspecific(key, &y);
  if (pthread_getspecific(key) == &y) {
    pthread_mutex_lock(&shared_mutex);
  }
  shared++; // NORACE
  if (pthread_getspecific(key) == &y) {
    pthread_mutex_unlock(&shared_mutex);
  }
  return NULL;
}

int main() {
  pthread_key_create(&key, NULL);

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
