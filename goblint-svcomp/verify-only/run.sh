#!/bin/bash

shopt -s extglob
set -e

BENCH_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
SV_BENCHMARKS_DIR=/mnt/goblint-svcomp/benchexec/sv-benchmarks
RESULTS_DIR=/mnt/goblint-svcomp/benchexec/results/279-all-pr-1818-after
GOBLINT_DIR=/mnt/goblint-svcomp/sv-comp/goblint/scripts/sv-comp
GOBLINT_PARALLEL=2

# read-only and overlay dirs for Value too large for defined data type workaround
BENCHEXEC="benchexec --read-only-dir / --overlay-dir . --overlay-dir /home --outputpath $RESULTS_DIR"

mkdir $RESULTS_DIR || true

# Construct verification XML
cd $RESULTS_DIR
sed -e "s|SV_BENCHMARKS_DIR|$SV_BENCHMARKS_DIR|" $BENCH_DIR/goblint.xml > goblint.xml

# Run verification
cd $GOBLINT_DIR
$BENCHEXEC --numOfThreads $GOBLINT_PARALLEL $RESULTS_DIR/goblint.xml

# Generate table
cd $RESULTS_DIR
cp $BENCH_DIR/table-generator.xml table-generator.xml
table-generator -x table-generator.xml

# Decompress all tool outputs for table HTML links
# Uncomment if not using https://github.com/sosy-lab/benchexec/blob/main/contrib/serveFileFromZIP.php
# unzip -o goblint.*.logfiles.zip
