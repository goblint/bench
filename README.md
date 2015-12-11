# Goblint benchmark suite

[![Gitter](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/goblint/bench?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

This contains the suite of benchmarks we currently use to evaluate Goblint. To run the benchmarks, make sure this repository is checked out in a directory with the same parent as the Goblint analyzer. Then, you can execute the script `./update_bench.rb` and view the results in bench_result/index.html. The kernel benchmarks rely on linux headers in the analyzer's directory (installed by executing `make headers`).
