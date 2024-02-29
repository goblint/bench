# Goblint benchmark suite

This contains the suite of benchmarks we currently use to evaluate Goblint. To run the benchmarks, make sure this repository is checked out in a directory with the same parent as the Goblint analyzer. 

## Basic Benchmarks

Execute the script `./update_bench.rb` and view the results in bench_result/index.html. The kernel benchmarks rely on linux headers in the analyzer's directory (installed by executing `make headers`). 

The benchmarks descriptions are assumed to be in a file called `bench.txt`. If this is absent it is symlinked to `index/dd.txt`. The idea was that one should locally replace with a hard copy without modifying the default descriptions.

### traces
Beforehand run in Goblint directory:
```console
make privPrecCompare
```

### traces_rel
Beforehand run in Goblint directory:
```console
make apronPrecCompare
```

## Incremental Benchmarks
Beforehand run in Goblint directory:
```console
make messagesCompare
```

1. Create a setup definition, such as `index/defs/incremental.yaml`, to specify the different analyses and parameters to run. Do not add the incremental save and load commands since these are added by some ugly mechanisms.
2. If necessary, edit the benchmark sets, such as `index/sets/posix.yaml`. 
3. Run script with parameters for timeout, conf, and list of benchmark sets, e.g., `./update_bench_incremental.rb 60 index/defs/interactive.yaml index/sets/examples.yaml index/sets/posix.yaml`

Add patches by changing some benchmark and doing, e.g., `git diff --no-prefix dtlk.c > dtlk04.patch`, and then of course restore the file. 

## Other Benchmarking scripts

- [parallel-run.sh](parallel-run.sh) to run the config in that script in parallel and log each program
- [csv-results.ml](csv-results.ml) to extract some numbers from each log and print a csv of it
- [precision.sh](precision.sh) to let goblint compare two variants for each program and write the result to a .precision file

## Incremental test generation
The "Test Automation for Incremental Analysis" is used for testing the incremental analysis. This is done by generating multiple mutation based on input files (e.g. the regression tests). The detailed documentation can be found [here](./incremental-analysis-test-toolchain/README.md).