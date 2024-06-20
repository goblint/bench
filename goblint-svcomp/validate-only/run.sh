#!/bin/bash

shopt -s extglob
set -e

BENCH_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
SV_BENCHMARKS_DIR=../../sv-benchmarks # TODO: needs setup
WITNESSES_DIR=/mnt/goblint-svcomp/benchexec/sv-benchmarks # TODO
RESULTS_DIR=/mnt/goblint-svcomp/benchexec/results/142-concurrency-witnesses
GOBLINT_DIR=/mnt/goblint-svcomp/sv-comp/goblint
GOBLINT_PARALLEL=2
GOBLINT_VALIDATE_PARALLEL=4

# read-only and overlay dirs for Value too large for defined data type workaround
BENCHEXEC="benchexec --read-only-dir / --overlay-dir . --overlay-dir /home --outputpath $RESULTS_DIR"

mkdir $RESULTS_DIR || true

# Extract witness directories
cd $WITNESSES_DIR
CPACHECKER_WITNESS_DIR=`echo cpachecker.*.files`
CPV_WITNESS_DIR=`echo cpv.*.files`
SYMBIOTIC_WITNESS_DIR=`echo symbiotic.*.files`

# Construct validation XMLs
cd $RESULTS_DIR
sed -e "s|SV_BENCHMARKS_DIR|$SV_BENCHMARKS_DIR|" -e "s|RESULTS_DIR|$WITNESSES_DIR|" -e "s|WITNESS_DIR|$CPACHECKER_WITNESS_DIR|" $BENCH_DIR/goblint-validate.xml > goblint-validate-cpachecker.xml
sed -e "s|SV_BENCHMARKS_DIR|$SV_BENCHMARKS_DIR|" -e "s|RESULTS_DIR|$WITNESSES_DIR|" -e "s|WITNESS_DIR|$CPV_WITNESS_DIR|" $BENCH_DIR/goblint-validate.xml > goblint-validate-cpv.xml
sed -e "s|SV_BENCHMARKS_DIR|$SV_BENCHMARKS_DIR|" -e "s|RESULTS_DIR|$WITNESSES_DIR|" -e "s|WITNESS_DIR|$SYMBIOTIC_WITNESS_DIR|" $BENCH_DIR/goblint-validate.xml > goblint-validate-symbiotic.xml

# Run validation
cd $GOBLINT_DIR

# Hack for SV-COMP witnesses
$BENCHEXEC --numOfThreads $GOBLINT_VALIDATE_PARALLEL $RESULTS_DIR/goblint-validate-cpachecker.xml
$BENCHEXEC --numOfThreads $GOBLINT_VALIDATE_PARALLEL $RESULTS_DIR/goblint-validate-cpv.xml
$BENCHEXEC --numOfThreads $GOBLINT_VALIDATE_PARALLEL $RESULTS_DIR/goblint-validate-symbiotic.xml

# Generate table with merged results and witness validation results
cd $RESULTS_DIR

cp $BENCH_DIR/table-generator.xml table-generator.xml
table-generator -x table-generator.xml

# Decompress all tool outputs for table HTML links
unzip -o goblint-validate-cpachecker.*.logfiles.zip
unzip -o goblint-validate-cpv.*.logfiles.zip
unzip -o goblint-validate-symbiotic.*.logfiles.zip
