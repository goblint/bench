/* 
 * Testcase from Threader's distribution. For details see:
 * http://www.model.in.tum.de/~popeea/research/threader
 */
#include <pthread.h>
//#include <assert.h>
//#define assert(e) if (!(e)) ERROR: __VERIFIER_error();

// boolean flags
int flag1 = 0, flag2 = 0;
// integer variable to hold the ID of the thread whose turn is it
int turn = 1;
// boolean variable to test mutual exclusion
int x;

void *thr1(void *unused) {
	flag1 = 1;
	while (flag2 >= 1) {
		if (turn != 0) {
			flag1 = 0; // flag1 == 0 && turn == 1
			while (turn != 0) {};
			flag1 = 1; // flag1 == 1 && turn == 0
		}
	}
	// begin: critical section
	//assert(!flag2 || turn == 0);
	//assert(turn == 0);
	// !flag2 --> !turn
	assert(flag2 || !turn);
	x = 0;
	//assert(x<=0);
	// end: critical section
	turn = 1;
	flag1 = 0;
	return NULL;
}

void *thr2(void *unused) {
	flag2 = 1;
	while (flag1 >= 1) {
		if (turn != 1) {
			flag2 = 0; // flag2 == 0 && turn == 0
			while (turn != 1) {};
			flag2 = 1; // flag2 == 1 && turn == 1
		}
	}
	// begin: critical section
	x = 1;
	//assert(x>=1);
	// end: critical section
	turn = 0;
	flag2 = 0;
	return NULL;
}

int main() {
	pthread_t t1, t2;
	//__VERIFIER_assume(0<=turn && turn<=1);
	turn = 0;
	pthread_create(&t1, 0, thr1, 0);
	pthread_create(&t2, 0, thr2, 0);
	//pthread_join(t1, 0);
	//pthread_join(t2, 0);
	return 0;
}
