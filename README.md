# Goblint benchmark suite

This contains the suite of benchmarks we currently use to evaluate Goblint. To run the benchmarks, make sure this repository is checked out in a directory with the same parent as the Goblint analyzer. 

## Basic Benchmarks

Execute the script `./update_bench.rb` and view the results in bench_result/index.html. The kernel benchmarks rely on linux headers in the analyzer's directory (installed by executing `make headers`). 

The benchmarks descriptions are assumed to be in a file called `bench.txt`. If this is absent it is symlinked to `index/dd.txt`. The idea was that one should locally replace with a hard copy without modifying the default descriptions. 


## Incremental Benchmarks

1. Edit the file `index/incremental.txt` to set the parameters. Do not add the incremental save and load commands since these are added by some ugly mechanism. (Be happy I'm keeping my hands away from goblint...)
2. Run `./update_bench_incremental.rb`

Add patches by changing some benchmark and doing, e.g., `git diff --no-prefix dtlk.c > dtlk04.patch`, and then of course restore the file. 

## Other Benchmarking scripts

- [parallel-run.sh](https://github.com/goblint/bench/blob/2d8bc2c8cb2cd6499733c535b868643f45bcae49/parallel-run.sh) to run the config in that script in parallel and log each program
- [csv-results.ml](https://github.com/goblint/bench/blob/2d8bc2c8cb2cd6499733c535b868643f45bcae49/csv-results.ml) to extract some numbers from each log and print a csv of it
- [precision.sh](https://github.com/goblint/bench/blob/2d8bc2c8cb2cd6499733c535b868643f45bcae49/precision.sh) to let goblint compare two variants for each program and write the result to a .precision file