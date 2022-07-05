/**
 * Author: Markus Kusano
 *
 * A modified version of an example interrupt service routine for keyboard
 * button presses. The original version is from a Linux Kernel Module tutorial.
 *
 * Based on source from: http://www.tldp.org/LDP/lkmpg/2.6/html/x1256.html
 * Originally: Copyright (C) 2001 by Peter Jay Salzman
 */
#include <assert.h>
#include <stdbool.h>
#include <pthread.h>

bool itemReady;
int status;

// The ``bottom half'' handler. Does the work with the keyboard interrupt data.
void *got_char(void *unused) {
	// TODO: To be more accurate of a model, this could be run in an infinite
	// loop.
	while (!itemReady) { } 
	// Retrieve the status from the irq_handler. The status should always be
	// positive and the itemReady flag should never be false.
	int st = status;
	int rdy = itemReady;
	if (st == 0) {
		assert(false);
	}
	if (rdy == 0) {
		assert(false);
	}
	// Since the work is "processed", reset the flags. Here, we could jump to the
	// begining of the function to simulate the infinite processing of work
	status = 0;
	itemReady = false;
	return NULL;
}

// The ``ISR''. This models getting some data and sending it to be processed by
// the `got_char` thread.
void *irq_handler(void *unused) {
	// To be more accurate of a model, this could be run in an infinite
	// loop

	// ``Retrieve'' the status. This should really use some kind of non
	// deterministic data value (e.g., read [-inf, +inf])
	status = 5; 
	itemReady = true;
	return NULL;
}

int main() { 
	// Initialize globals
	itemReady = false;
	status = 0;

	pthread_t t1, t2;
	pthread_create(&t1, NULL, got_char, NULL); 
	pthread_create(&t2, NULL, irq_handler, NULL);

	return 0;
}
