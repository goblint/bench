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
};

int data = 0;
pthread_mutex_t data_mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread(void *arg) {
  pthread_mutex_lock(&data_mutex);
  data = __VERIFIER_nondet_int(); // NORACE
  pthread_mutex_unlock(&data_mutex);
  return NULL;
}

int main() {
  int threads_total = __VERIFIER_nondet_int();
  assume_abort_if_not(threads_total >= 0);

  struct thread **ts = malloc(threads_total * sizeof(struct thread *));

  // create threads
  for (int i = 0; i < threads_total; i++) {
    struct thread *t = malloc(sizeof(struct thread));
    ts[i] = t;
    pthread_create(&t->tid, NULL, &thread, t); // may fail but doesn't matter
  }

  // join threads
  for (int i = 0; i < threads_total; i++) {
    pthread_join(ts[i]->tid, NULL);
    free(ts[i]);
  }

  free(ts);

  return data; // NORACE (all thread stopped)
}
