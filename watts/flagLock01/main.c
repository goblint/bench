#include <pthread.h>
#include <assert.h>
#include <stdbool.h>
int x;
int flag1;
int flag2;
int victim;

void *thread1(void *args) {
  flag1 = true;
  victim = 1;
  while (flag2 && victim == 1) { }
  x++;
  flag1 = false;
  return NULL;
}

void *thread2(void *args) {
  flag2 = true;
  victim = 2;
  while (flag1 && victim == 2) { }
  x++;
  flag2 = false;
  return NULL;
}

int main() {
  flag1 = false;
  flag2 = false;
  x = 0;
  pthread_t t1;
  pthread_t t2;
  pthread_create(&t1, NULL, thread1, NULL);
  pthread_create(&t2, NULL, thread2, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  assert(x != 1);
  return 0;
}
