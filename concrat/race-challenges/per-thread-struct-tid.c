// Per-thread structs containing thread ID passed via argument.
// Extracted from chrony.
#include <stdlib.h>
#include <pthread.h>
extern void abort(void);
void assume_abort_if_not(int cond) {
  if(!cond) {abort();}
}
extern int __VERIFIER_nondet_int();

struct thread {
  pthread_t tid;
  int data;
};

void *thread(void *arg) {
  struct thread *t = arg;
  t->data = __VERIFIER_nondet_int(); // NORACE
  return NULL;
}

int main() {
  int breads_total = __VERIFIER_nondet_int();
  assume_abort_if_not(breads_total >= 0);

  struct thread **ts = malloc(breads_total * sizeof(struct thread *));

  // create threads
  for (int i = 0; i < breads_total; i++) {
    struct thread *t = malloc(sizeof(struct thread));
    ts[i] = t;
    pthread_create(&t->tid, NULL, &thread, t); // may fail but doesn't matter
  }

  // join threads
  for (int i = 0; i < breads_total; i++) {
    pthread_join(ts[i]->tid, NULL);
    free(ts[i]);
  }

  free(ts);

  return 0;
}
