# Race Detection Challenges

This suite contains extracted kernels of programs aimed to demonstrate the most important challenges to solve in order to be able to achieve good results on real-world programs.

## Thread Creation and Joining Schemes

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

---

## Per-Thread Data Segmentation

### [per-thread-array-index.c](per-thread-array-index.c) and [join-counter](per-thread-array-join-counter.c)

Classic scheme of having thread `i` storing information at `data[i]` in a global data array. Creates are created in a loop and the index is given as parameter to the thread. In the end, the threads are joined as [above](#thread-join-array-dynamicc), allowing the main thread to process the data.

False Variations:
1. [race.c](per-thread-array-index-race.c) writes to `data[i/2]`, causing conflicting updates.
2. [race-2.c](per-thread-array-index-race-2.c) passes `i/2` as argument when creating the thread.

The original program joins using an [outside counter](#thread-join-counter-outerc) and joins within a dedicated cleanup thread.
This combination is available as [per-thread-array-join-counter.c](per-thread-array-join-counter.c) with false variations.

*Extracted from: smtprc.c.*


---

### [per-thread-array-ptr.c](per-thread-array-ptr.c)

As the previous, but the main thread creates the data array. Threads are created in a for loop, and the address `&data[i]` is given as argument to the thread.

False Variation: [race.c](per-thread-array-ptr-race.c) passes `&data[i/2]` as argument.

A variation of this, [per-thread-array-init.c](per-thread-array-init.c) also initializes the array element with the thread index.

TODO: Is the thread index used for anything?

*Extracted from: [minimap2](../minimap2/), [klib](../klib); [the_silver_searcher](../the_silver_searcher)*

---

### [per-thread-index-inc.c](per-thread-index-inc.c)

In these scheme, the main thread creates the array, but a global counter is used to assign the segment of the data that each thread works on. In the more advanced version, [per-thread-index-bitmask.c](per-thread-index-bitmask.c), a bitmap is used to track live threads and the first "free" index is reused by newly created threads.

*Extracted from [ProcDump-for-Linux](../ProcDump-for-Linux); [nnn](../nnn/).*

### [per-thread-struct.c](per-thread-struct.c)

Each thread is given a dynamically allocated struct by the main thread. As a variation,
[per-thread-struct-in-array.c](per-thread-struct-in-array.c) allocates and stores these in an array `ts` of per-thread structs and gives the corresponding pointer `&ts[i]` to the thread.

*Extracted from [C-Thread-Pool](../C-Thread-Pool/), [snoopy](../snoopy); [ProcDump-for-Linux](../ProcDump-for-Linux/)*

### [per-thread-struct-tid.c](per-thread-struct-tid.c)

TODO: Would make more sense to verify join scheme.



## Other Synchronization Mechanisms

### [semaphore-posix.c](semaphore-posix.c)

### [value-barrier.c](value-barrier.c)

### [thread-local-value.c](thread-local-value.c)

### [atomic-gcc.c](atomic-gcc.c)