# Long Jumps Falling Short - Control-Flow Tracking & Misuse Detection for Non-Local Jumps in C

This page gives additional information on the experiments & implementation
that accompanies our manuscript.

# Basic Setup

On top of this repository, the Goblint Static Analyzer is needed.
The relevant tag is this one: https://github.com/goblint/analyzer/tree/v2.1.0-longjmp

Please follow the installation guide given in https://github.com/goblint/analyzer/tree/v2.1.0-longjmp#readme

# Small Litmus Tests
## General

The set of 40-ish small examples is integrated into the set of regression tests for the Goblint.
To run all regression tests, one may simply (in the analyzer directory) call

~~~console
make test
~~~

In order to run one specific example, one may run

~~~console
./regtest.sh 68 NN
~~~

where `NN` is the number at the beginning of the testcase in folder `tests/regression/68-longjmp/NN-one.c`.
One may then inspect a visual representation of the results by serving the
`result` directory and accessing it via a browser. For details, refer to https://goblint.readthedocs.io/en/latest/user-guide/inspecting/.
The runtime for all these litmus tests is negligible.

## Abstract Stack Unwinding

We would like to particularly point out test `68/22` that demonstrates the need for abstract stack unwinding:
 - `main` calls `setjmp`
 - A pointer to `val` is passed to `fun` which sets `val` to `1`.
 - `fun` then calls `foo`. `foo` is not passed a pointer to `val`, and thus `val` does not appear in its local state.
 - `foo` causes a `longjmp` back to `main`

Here, in order to account for the modification of `val`, it is necessary to pass values up the callstack, and calling $\textsf{combine}^\sharp$ while unwinding the stack.

# `Libpng` example

## Current Version

We have used Goblint's support for compilation DBs and the merger that comes with CIL to produce a single program, making it easier to run these tests.

This program can be found inside the libpng folder.

To run the program, execute from within this folder/

~~~console
../path/to/analyzer/repo/goblint pngtest_combined.c  --conf config.json &> pngtest_out.log
~~~

Such a run takes about 55min and 26GB of RAM.

Among other warnings about internal issues of the analyzer related to precision loss, six warnings related to the usage of
setjmp/longjmp are produced.

- The warnings that we believe to be indicative of a real bug are the two warnings `[Warning][Behavior > Undefined > Other] Reading poisonous variable row_buf`.
- The three warnings about longjmps leading to potentially invalid targets start with `[Warning][Behavior > Undefined > Other] Longjmp to potentially invalid target [...]` or `[Warning][Imprecise] Longjmp to potentially invalid target [...]`.
- The warning about jumping to a jump buffer that may receive its value by copying memory is `[Warning][Behavior > Undefined > Other] The jump buffer *(png_ptr->jmp_buf_ptr) contains values that were copied here instead of being set by setjmp. This is Undefined Behavior.`.

## Exhibiting the Memory Leak

The potential clobbering of `row_buf` can lead to a memory leak; however,
the program as currently implemented reads and writes single lines using the libpng function:
```c 
png_read_rows(read_ptr, (png_bytepp)&row_buf, NULL, 1);
```

The address of `row_buf` is given to an external function, so the compiler *most likely* treats it as volatile.
This is dangerous because an innocuous change will result in a real memory leak, namely,
if one uses the more natural method of reading/writing single lines:
```c
png_read_row(read_ptr, row_buf, NULL);
```

We can then witness a memory leak, similar to [this issue](https://github.com/glennrp/libpng/issues/265), where the freeing of `row_buf` was missing. This has been [fixed](https://github.com/pnggroup/libpng/commit/8439534daa1d3a5705ba92e653eda9251246dd61#diff-71224f3104c9fad7ed296177dd09ee5ce90a3604b61e8edbb84eab5d33eea43dR960), but the same leak happens if the pointer is clobbered. To replicate this, execute the following commands in our `libpng` directory (or copy the referenced files):
```bash
git clone https://github.com/glennrp/libpng.git
cd libpng
git checkout v1.6.39
patch -p1 < ../no-escape.patch
export CC=/usr/bin/clang CFLAGS="-g -O2  -fsanitize=address"
./configure
make
./pngtest ../leak_30925
```

## Bug Injection

We have also injected a bug akin to the one in ImageMagick described in
[this blog post](https://patrakov.blogspot.com/2009/07/dangers-of-setjmplongjmp.html).
The corresponding program is also in the libpng folder (`pngtest_seeded_bug.c`).
To understand the way in which the bug was introduced, it may be helpful to use a diff tool and compare
`pngtest_combined.c` and `pngtest_seeded_bug.c`.

Goblint can be run on it in the same way as the unmodified program.

The inserted bug is that the variable `png_pixels` is accessed when it has indeterminate value.
This is reflected in the extra warnings `[Warning][Unknown] accessing poisonous variable png_pixels`.

# Helpful Links

- https://goblint.readthedocs.io/
- https://goblint.in.tum.de/
