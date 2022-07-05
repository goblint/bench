#include <stdbool.h>
#include <pthread.h>
#include <assert.h>
bool flag; 

void *thread1(void *unused) { 
  // s:
  flag = true; 
  return NULL;
} 
void *thread2(void *unused) { 
  int i = 0; 
  int j = 0; 
  flag = false; 
  while (i + j < 2) { 
    // l:
    bool tmp = flag; 
    if (tmp) { 
      i = i + 1; 
    } 
    else { 
      j = j + 1; 
    } 
  } 
  if (i > 0 && j > 0) { 
    assert(false); // Reachable 
  } 
  return NULL;
}

int main() {
  pthread_t t1;
  pthread_t t2;

  pthread_create(&t1, NULL, thread1, NULL);
  pthread_create(&t2, NULL, thread2, NULL);
  //pthread_join(t1, NULL);
  //pthread_join(t2, NULL);

  return 0;
}


