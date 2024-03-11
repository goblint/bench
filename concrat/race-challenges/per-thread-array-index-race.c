// Per-thread array index passed via argument.
#include <stdlib.h>
#include <pthread.h>
extern void abort(void);
void assume_abort_if_not(int cond) {
  if(!cond) {abort();}
}
extern int __VERIFIER_nondet_int();

int *datas;

void *thread(void *arg) {
  int i = (int)arg;
  i /= 2;
  datas[i] = __VERIFIER_nondet_int(); // RACE!
  return NULL;
}

int main() {
  int breads_total = __VERIFIER_nondet_int();
  assume_abort_if_not(breads_total >= 0);

  pthread_t *tids = malloc(breads_total * sizeof(pthread_t));
  datas = malloc(breads_total * sizeof(int));

  // create threads
  for (int i = 0; i < breads_total; i++) {
    pthread_create(&tids[i], NULL, &thread, (void*)i); // may fail but doesn't matter
  }

  // join threads
  for (int i = 0; i < breads_total; i++) {
    pthread_join(tids[i], NULL);
  }

  free(tids);
  free(datas);

  return 0;
}
