# Long Jumps Falling Short - Control-Flow Tracking & Misuse Detection for Non-Local Jumps in C

This page gives additional information on the experiments & implementation
that accompanies our manuscript.

# Basic Setup

On top of this repository, the Goblint Static Analyzer is needed.
The relevant branch is this one: https://github.com/goblint/analyzer/tree/longjmp

Please follow the installation guide given in https://github.com/goblint/analyzer/blob/longjmp/README.md

# Small Examples

The set of 40-ish small examples is integrated into the set of regression tests for the Goblint. To run all regression tests, one may simply call

> make test

In order to run one specific example, one may run

> ./regtest.sh 66 NN

where `NN` is the number at the beginning of the testcase in folder `tests/regression/66-longjmp/NN-one.c`.
One may then inspect a visual representation of the results by serving the
`result` directory and accessing it via a browser. For details, refer to https://goblint.readthedocs.io/en/latest/user-guide/inspecting/


# `Libpng` example

We have used Goblint's support for compilation DBs and the merger that comes with CIL to produce a single program, making it easier to run these tests.

This program can be found inside the libpng folder.

To run the program, execute

>  ./goblint pngtest_combined.c  --conf config.json &> out.txt

Such a run takes about 50min and 35GB of RAM.


# Helpful Links

- https://goblint.readthedocs.io/
- https://goblint.in.tum.de/
