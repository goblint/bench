# Long Jumps Falling Short - Control-Flow Tracking & Misuse Detection for Non-Local Jumps in C

This page gives additional information on the experiments & implementation
that accompanies our manuscript.

# Basic Setup

On top of this repository, the Goblint Static Analyzer is needed.
The relevant branch is this one: https://github.com/goblint/analyzer/tree/longjmp

Please follow the installation guide given in https://github.com/goblint/analyzer/blob/longjmp/README.md

# Small Litmus Tests

The set of 40-ish small examples is integrated into the set of regression tests for the Goblint.
To run all regression tests, one may simply (in the analyzer directory) call

> make test

In order to run one specific example, one may run

> ./regtest.sh 66 NN

where `NN` is the number at the beginning of the testcase in folder `tests/regression/66-longjmp/NN-one.c`.
One may then inspect a visual representation of the results by serving the
`result` directory and accessing it via a browser. For details, refer to https://goblint.readthedocs.io/en/latest/user-guide/inspecting/

The runtime for all these litmus tests is negligable.

# `Libpng` example

## Current Version

We have used Goblint's support for compilation DBs and the merger that comes with CIL to produce a single program, making it easier to run these tests.

This program can be found inside the libpng folder.

To run the program, execute from within this folder/

>  ../path/to/analyzer/repo/goblint pngtest_combined.c  --conf config.json &> pngtest_out.log

Such a run takes about 50min and 35GB of RAM.

Among other warnings about issues such as possible null-pointer dereferences, six warnings related to the usage of
setjmp/longjmp are produced.

- The warnings that we believe to be indicative of a real bug are the two warnings `[Warning][Unknown] accessing poisonous variable row_buf`.
- The three warnings about longjmps leading to potentially invalid targets start with `[Warning][Unknown] Longjmp to potentially invalid target [...]`.
- The warning about jumping to a jump buffer that may receive its value by copying memory is `[Warning][Unknown] The jump buffer *(png_ptr->jmp_buf_ptr) contains values that were copied here instead of being set by setjmp.`.

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
