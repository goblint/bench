#include <pthread.h>
#include <assert.h>
int x = 0;
void *thread1(void *unused) {
  x++;
  return NULL;
}

void *thread2(void *unused) {
  x++;
  return NULL;
}

int main() {
  pthread_t t1;
  pthread_t t2;
  pthread_create(&t1, NULL, thread1, NULL);
  pthread_create(&t2, NULL, thread2, NULL);
  return 0;
}
