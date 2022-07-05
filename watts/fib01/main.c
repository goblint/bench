/*
 * Author: Markus Kusano
 * Adapted from: svcomp15/pthread/fib_bench_true-unreach-call.c
 */

extern void __VERIFIER_error() __attribute__ ((__noreturn__));

#include <pthread.h>

int i=1, j=1;

#define NUM 5

void *
t1(void* arg)
{
  int k = 0;

  //for (k = 0; k < NUM; k++)
  //  i+=j;
	// Manually unrolled
  i+=j;
  i+=j;
  i+=j;
  i+=j;
  i+=j;

  pthread_exit(NULL);
}

void *
t2(void* arg)
{
  int k = 0;

	// Manually unrolled
  //for (k = 0; k < NUM; k++)
    //j+=i;
	j+=i;
	j+=i;
	j+=i;
	j+=i;
	j+=i;

  pthread_exit(NULL);
}

int
main(int argc, char **argv)
{
  pthread_t id1, id2;

  pthread_create(&id1, NULL, t1, NULL);
  pthread_create(&id2, NULL, t2, NULL);

	pthread_join(id1, NULL);
	pthread_join(id2, NULL);

  if (i > 144 || j > 144) {
    ERROR: __VERIFIER_error();
  }

  return 0;
}
