// Race-free due to value-based barrier, main thread only writes before.
// Extracted from silver searcher.
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
extern void abort(void);
void assume_abort_if_not(int cond) {
  if(!cond) {abort();}
}
extern int __VERIFIER_nondet_int();

bool ready = false;
pthread_mutex_t ready_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t ready_cond = PTHREAD_COND_INITIALIZER;

int data = 0;

void *thread(void *arg) {
  // wait for main thread to be ready
  pthread_mutex_lock(&ready_mutex);
  while (!ready) // NORACE
    pthread_cond_wait(&ready_cond, &ready_mutex);
  pthread_mutex_unlock(&ready_mutex);

  int x = data; // NORACE (main thread wrote before ready)
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

  data = __VERIFIER_nondet_int(); // NORACE (write before ready)

  // become ready
  pthread_mutex_lock(&ready_mutex);
  ready = true; // NORACE
  pthread_cond_broadcast(&ready_cond);
  pthread_mutex_unlock(&ready_mutex);

  // join threads
  for (int i = 0; i < breads_total; i++) {
    pthread_join(tids[i], NULL);
  }

  free(tids);

  return 0;
}
