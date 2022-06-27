#include <pthread.h>
#include <assert.h>

int x;
int y;

// Expose the internal variables inside the threads to reason about properties.
int a;
int b;

void *thread1(void *unused) {
  x = 1;
  a = y;
  return NULL;
}

void *thread2(void *unused) {
  y = 1;
  b = x;
  // b == 0 --> !(a == 0)
  assert(!(b == 0) || (a == 0));
  return NULL;
}

int main() {
  pthread_t t1;
  pthread_t t2;
  x = 0;
  y = 0;
  a = 0;
  b = 0;

  pthread_create(&t1, NULL, thread1, NULL);
  pthread_create(&t2, NULL, thread2, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  return 0;

}
