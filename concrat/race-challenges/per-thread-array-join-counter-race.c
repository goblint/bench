// PARAM: --set ana.activated[+] symb_locks
// Per-thread array index passed via argument.
// Thread pool joining via threads alive counter decremented based on thread array values.
// Extracted from smtprc.
// TODO: symb_locks doesn't work for datas and datas_mutex here
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
extern void abort(void);
void assume_abort_if_not(int cond) {
  if(!cond) {abort();}
}
extern int __VERIFIER_nondet_int();

int threads_total;
int threads_alive = 0;

pthread_t *tids;
bool *datas;
pthread_mutex_t *datas_mutex;

void *thread(void *arg) {
  int i = arg;
  pthread_mutex_lock(&datas_mutex[i]);
  datas[i] = true; // NORACE
  pthread_mutex_unlock(&datas_mutex[i]);
  return NULL;
}

void *cleaner(void *arg) {
  while (1) {
    for (int i = 0; i < threads_total; i++) {
      pthread_mutex_lock(&datas_mutex[i]);
      if (datas[i]) { // NORACE
        pthread_join(tids[i], NULL); // NORACE
        threads_alive--; // RACE!
        datas[i] = false; // NORACE
      }
      pthread_mutex_unlock(&datas_mutex[i]);
    }
  }
  return NULL;
}

int main() {
  threads_total = __VERIFIER_nondet_int();
  assume_abort_if_not(threads_total >= 1);

  tids = malloc(threads_total * sizeof(pthread_t));
  datas = calloc(threads_total, sizeof(bool));
  datas_mutex = malloc(threads_total * sizeof(pthread_mutex_t));

  for (int i = 0; i < threads_total; i++)
    pthread_mutex_init(&datas_mutex[i], NULL);

  // create threads
  pthread_t cleaner_tid;
  pthread_create(&cleaner_tid, NULL, &cleaner, NULL);

  for (int i = 0; i < threads_total; i++) {
    pthread_create(&tids[i], NULL, &thread, i); // NORACE may fail but doesn't matter

    threads_alive++; // RACE!
  }

  // wait for all threads to stop
  while (threads_alive); // RACE!

  free(tids);

  return datas[0]; // NORACE (all threads stopped)
}
