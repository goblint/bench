#!/bin/bash

shopt -s extglob
set -e

BENCH_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
RESULTS_DIR=/mnt/goblint-svcomp/benchexec/results/concrat-1-issue-1758-before
GOBLINT_DIR=/mnt/goblint-svcomp/sv-comp/goblint
GOBLINT_PARALLEL=2

# read-only and overlay dirs for Value too large for defined data type workaround
BENCHEXEC="benchexec --read-only-dir / --overlay-dir . --overlay-dir /home --outputpath $RESULTS_DIR"

mkdir $RESULTS_DIR || true

# Run verification
cd $GOBLINT_DIR
$BENCHEXEC --numOfThreads $GOBLINT_PARALLEL $BENCH_DIR/goblint.xml

# Generate table
cd $RESULTS_DIR
cp $BENCH_DIR/table-generator.xml table-generator.xml
table-generator -x table-generator.xml

# Decompress all tool outputs for table HTML links
# Uncomment if not using https://github.com/sosy-lab/benchexec/blob/main/contrib/serveFileFromZIP.php
# unzip -o goblint.*.logfiles.zip
