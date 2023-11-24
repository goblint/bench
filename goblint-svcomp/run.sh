#!/bin/bash

shopt -s extglob
set -e

BENCH_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
SV_BENCHMARKS_DIR=/mnt/goblint-svcomp/benchexec/sv-benchmarks
RESULTS_DIR=/mnt/goblint-svcomp/benchexec/results/140
GOBLINT_DIR=/mnt/goblint-svcomp/sv-comp/goblint-clean/goblint
GOBLINT_PARALLEL=2
GOBLINT_VALIDATE_PARALLEL=4

# read-only and overlay dirs for Value too large for defined data type workaround
BENCHEXEC="benchexec --read-only-dir / --overlay-dir . --overlay-dir /home --outputpath $RESULTS_DIR"

mkdir $RESULTS_DIR || true

# Construct verification XML
cd $RESULTS_DIR
sed -e "s|SV_BENCHMARKS_DIR|$SV_BENCHMARKS_DIR|" $BENCH_DIR/goblint.xml > goblint.xml

# Run verification
cd $GOBLINT_DIR
$BENCHEXEC --numOfThreads $GOBLINT_PARALLEL $RESULTS_DIR/goblint.xml

# Extract witness directory
cd $RESULTS_DIR
WITNESS_DIR=`echo goblint.*.files`
echo $WITNESS_DIR

# Construct validation XML
cd $RESULTS_DIR
sed -e "s|SV_BENCHMARKS_DIR|$SV_BENCHMARKS_DIR|" -e "s|RESULTS_DIR|$RESULTS_DIR|" -e "s|WITNESS_DIR|$WITNESS_DIR|" $BENCH_DIR/goblint-validate.xml > goblint-validate.xml

# Run validation
cd $GOBLINT_DIR
$BENCHEXEC --numOfThreads $GOBLINT_VALIDATE_PARALLEL $RESULTS_DIR/goblint-validate.xml

# Generate table with merged results and witness validation results
cd $RESULTS_DIR

for i in goblint.*.results.*.xml.bz2; do
    $BENCH_DIR/adjust_results_verifiers.py $i goblint-validate.*.${i#*.results.}
done

cp $BENCH_DIR/table-generator.xml table-generator.xml
table-generator -x table-generator.xml

# Decompress all tool outputs for table HTML links
unzip -o goblint.*.logfiles.zip
unzip -o goblint-validate.*.logfiles.zip
