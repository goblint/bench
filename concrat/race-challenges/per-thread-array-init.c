// Per-thread array pointers passed via argument but initialized before thread create.
// Extracted from silver searcher.
#include <stdlib.h>
#include <pthread.h>
extern void abort(void);
void assume_abort_if_not(int cond) {
  if(!cond) {abort();}
}
extern int __VERIFIER_nondet_int();

void *thread(void *arg) {
  int *p = arg;
  int i = *p; // NORACE
  return NULL;
}

int main() {
  int breads_total = __VERIFIER_nondet_int();
  assume_abort_if_not(breads_total >= 0);

  pthread_t *tids = malloc(breads_total * sizeof(pthread_t));
  int *is = malloc(breads_total * sizeof(int));

  // create threads
  for (int i = 0; i < breads_total; i++) {
    is[i] = i; // NORACE
    pthread_create(&tids[i], NULL, &thread, &is[i]); // may fail but doesn't matter
  }

  // join threads
  for (int i = 0; i < breads_total; i++) {
    pthread_join(tids[i], NULL);
  }

  free(tids);
  free(is);

  return 0;
}
