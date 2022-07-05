//#include <assert.h>
#include <pthread.h>

int shared = 0;

void *thread1(void *unused) {
  // The only modification visible to this thread is its initial state. All of
  // the interferences are post-dominated by the thread's creation in main.
  assert(shared == 3);
  return NULL;
}

int main(int argc, char *argvp[]) {
  // main updates the value of shared before creating a thread. The created
  // thread should only be able to see the latest value before the create

  if (argc) {
    shared = 1;
  }
  else {
    shared = 2;
  }
  shared = 3;
  pthread_t t1;
  pthread_create(&t1, NULL, thread1, NULL);

  pthread_exit((void *) 0);
}
