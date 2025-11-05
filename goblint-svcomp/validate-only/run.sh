#!/bin/bash

shopt -s extglob
set -e

BENCH_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
SV_BENCHMARKS_DIR=/mnt/goblint-svcomp/benchexec/sv-benchmarks
WITNESSES_DIR=/mnt/goblint-svcomp/benchexec/results/247-all-validate-pr-1709-before
RESULTS_DIR=/mnt/goblint-svcomp/benchexec/results/248-all-validate-pr-1709-before2
GOBLINT_DIR=/mnt/goblint-svcomp/sv-comp/goblint/scripts/sv-comp
GOBLINT_VALIDATE_PARALLEL=4

# read-only and overlay dirs for Value too large for defined data type workaround
BENCHEXEC="benchexec --read-only-dir / --overlay-dir . --overlay-dir /home --outputpath $RESULTS_DIR"

mkdir $RESULTS_DIR || true

# Extract witness directories
cd $WITNESSES_DIR
WITNESS_DIR=`echo goblint.*.files`

# Construct validation XMLs
cd $RESULTS_DIR
sed -e "s|SV_BENCHMARKS_DIR|$SV_BENCHMARKS_DIR|" -e "s|RESULTS_DIR|$WITNESSES_DIR|" -e "s|WITNESS_DIR|$WITNESS_DIR|" $BENCH_DIR/goblint-validate.xml > goblint-validate.xml

# Run validation
cd $GOBLINT_DIR
$BENCHEXEC --numOfThreads $GOBLINT_VALIDATE_PARALLEL $RESULTS_DIR/goblint-validate.xml

# Generate table with witness validation results
cd $RESULTS_DIR

cp $BENCH_DIR/table-generator.xml table-generator.xml
table-generator -x table-generator.xml

# Decompress all tool outputs for table HTML links
# unzip -o goblint-validate.*.logfiles.zip
