# Race Detection Challenges

This suite contains extracted kernels of programs aimed to demonstrate the most important challenges to solve in order to be able to achieve good results on real-world programs.

## Thread Joining

### [thread-join-array-const.c](thread-join-array-const.c)

Thread pool constant array sequential joining: create 4 threads in a loop and store IDs in array, iterate over array and join all threads, and access a shared variable after join.

False Variations:
1. [race.c](thread-join-array-const-race.c) does not join the last thread.
2. [race-2.c](thread-join-array-const-race-2.c) skips threads in the join loop.
3. [race-3.c](thread-join-array-const-race-3.c) overwrites previously stored thread id.

*Extracted from: [level-ip](../level-ip/)*

---

### [thread-join-array-dynamic.c](thread-join-array-dynamic.c)

Same as previous, except the array is dynamically allocated. The number of threads is chosen non-deterministically but is fixed at program start.

False Variations: [1](thread-join-array-dynamic-race.c), [2](thread-join-array-dynamic-race-2.c), and [3](thread-join-array-dynamic-race-3.c) are analogous to previous.

*Extracted from: [klib](../klib), [minimap2](../minimap2/)*

---

### [thread-join-binomial.c](thread-join-binomial.c)

Implements a join scheme where each thread joins with its children in a binomial tree. This is also among the communication algorithms [used](https://github.com/open-mpi/ompi/blob/main/ompi/mca/coll/tuned/coll_tuned_decision_fixed.c) in OpenMPI.

False Variations:
1. [race.c](thread-join-binomial-race.c) does not join the root thread.
2. [race-2.c](thread-join-binomial-race-2.c) has each thread skipping the join with its last "child".

*Extracted from: [fzy](../fzy)*

---

### [thread-join-counter-inner.c](thread-join-counter-inner.c)

Threads are created in a loop and detached. Instead of joins, the program relies on a counter `threads_alive` that each thread increments upon start and decrements before returning. The main thread waits for all threads to have started (by checking that the counter reaches a fixed number) and then waits for the counter to reach zero before accessing shared data.

False Variations:
1. [race.c](thread-join-counter-inner-race.c) fails to protect the thread counter, such that increments could be lost and the counter reaching zero with threads still running.
2. [race-2.c](thread-join-counter-inner-race-2.c) has threads accessing shared data after the counter is decremented.
3. [race-3.c](thread-join-counter-inner-race-3.c) is off by one in the counting of threads.
4. [race-4.c](thread-join-counter-inner-race-4.c) decrements threads by two instead of one.
5. [race-5.c](thread-join-counter-inner-race-5.c) does not wait for all threads to have started before checking that the counter is zero, resulting in a potential race with threads incrementing the counter after the check by the main thread.

*Extracted from: [C-Thread-Pool](../C-Thread-Pool/)*

---

### [thread-join-counter-outer.c](thread-join-counter-outer.c)

Similar to the previous, except the outer thread (more precisely, the main thread in the extracted kernel) is responsible for incrementing `threads_alive` counter. The created threads then decrement the counter. As the main thead increments the counter, it does not need to wait and check that all threads have incremented it, but only waits for the counter to reach zero before accessing shared data.

False Variations: [1](thread-join-counter-outer-race.c), [2](thread-join-counter-outer-race-2.c), [3](thread-join-counter-outer-race-3.c), and [4](thread-join-counter-outer-race-4.c) are analogous to the previous.

*Extracted from: [nnn](../nnn)*




