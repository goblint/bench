#include <pthread.h>
//#include <assert.h>

int flag = 0;
int x = 0;

void *thread1(void *unused) {
  x = 4;
  x = 5;
  flag = 1;
  return NULL;
}

void *thread2(void *unused) {
  int b1 = flag;
  if (b1) {
    int t1 = x;
    assert(t1 == 5);
  }
  return NULL;
}

int main() {
  pthread_t t1, t2;
  pthread_create(&t1, NULL, thread1, NULL);
  pthread_create(&t2, NULL, thread2, NULL);

  pthread_exit((void *) 0);
}
