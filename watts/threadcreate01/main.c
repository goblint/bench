#include <assert.h>
#include <pthread.h>

int shared = 0;

void *thread1(void *unused) {
  // This is actually too strong of an assertion. In reality, shared must be
  // two. This thread cannot see the global initialization since main
  // overwrites the value before the creation.
  assert(shared == 0 || shared == 2);
  return NULL;
}

int main() {
  // main updates the value of shared before creating a thread. The created
  // thread should only be able to see the latest value before the create
  shared = 1;
  shared = 2;

  pthread_t t1;
  pthread_create(&t1, NULL, thread1, NULL);

  pthread_exit((void *) 0);
}
