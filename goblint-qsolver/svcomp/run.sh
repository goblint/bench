#!/bin/bash

shopt -s extglob
set -e

BENCH_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
SV_BENCHMARKS_DIR=/mnt/goblint-svcomp/benchexec/sv-benchmarks
RESULTS_DIR=/mnt/goblint-svcomp/benchexec/results/qsolver-8-svcomp-all-level01-aug10
GOBLINT_DIR=/mnt/ecoop/goblint-qsolver
GOBLINT_PARALLEL=14
GOBLINT_SOLVERS=(td3 slr3 slr3t qss_cwnw qsr qsri qso_cwnw qsr_dead qsr_nosides qsr_nosides_dead)

# read-only and overlay dirs for Value too large for defined data type workaround
BENCHEXEC="benchexec --read-only-dir / --overlay-dir . --overlay-dir /home --outputpath $RESULTS_DIR --results-per-taskset"

mkdir $RESULTS_DIR || true

# Construct verification XML
cd $RESULTS_DIR
for SOLVER in "${GOBLINT_SOLVERS[@]}"; do
    sed -e "s|SV_BENCHMARKS_DIR|$SV_BENCHMARKS_DIR|" -e "s|SOLVER|$SOLVER|" $BENCH_DIR/goblint.xml > goblint-$SOLVER.xml
done

# Run verification
cd $GOBLINT_DIR
for SOLVER in "${GOBLINT_SOLVERS[@]}"; do
    $BENCHEXEC --numOfThreads $GOBLINT_PARALLEL $RESULTS_DIR/goblint-$SOLVER.xml
done

# Generate table
cd $RESULTS_DIR
cp $BENCH_DIR/table-generator.xml table-generator.xml
table-generator -x table-generator.xml

# Decompress all tool outputs for table HTML links
# Uncomment if not using https://github.com/sosy-lab/benchexec/blob/main/contrib/serveFileFromZIP.php
# unzip -o goblint.*.logfiles.zip
