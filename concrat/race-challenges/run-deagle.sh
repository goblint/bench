#!/bin/bash

shopt -s extglob
set -e

MYBENCHDIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
# RESULTSDIR=$MYBENCHDIR/../results/eval-prec
RESULTSDIR=/mnt/goblint-svcomp/benchexec/results/oopsla-3-race-challenges-deagle-pre
DEAGLE23_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi/deagle
DEAGLE23_PARALLEL=2
DEAGLE24_PRE1_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi24/deagle-pre-1
DEAGLE24_PRE1_PARALLEL=2
DEAGLE24_PRE2_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi24/deagle-pre-2
DEAGLE24_PRE2_PARALLEL=2
DEAGLE24_PRE3_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi24/deagle-pre-3
DEAGLE24_PRE3_PARALLEL=2
DEAGLE24_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi24/deagle
DEAGLE24_PARALLEL=2

# read-only and overlay dirs for Value too large for defined data type workaround
BENCHEXEC="benchexec --read-only-dir / --overlay-dir . --overlay-dir /home --outputpath $RESULTSDIR"

mkdir $RESULTSDIR || true

# Run verification
# cd $DEAGLE23_DIR
# $BENCHEXEC --numOfThreads $DEAGLE23_PARALLEL $MYBENCHDIR/deagle23.xml
cd $DEAGLE24_PRE1_DIR
$BENCHEXEC --numOfThreads $DEAGLE24_PRE1_PARALLEL $MYBENCHDIR/deagle24-pre-1.xml
cd $DEAGLE24_PRE2_DIR
$BENCHEXEC --numOfThreads $DEAGLE24_PRE2_PARALLEL $MYBENCHDIR/deagle24-pre-2.xml
cd $DEAGLE24_PRE3_DIR
$BENCHEXEC --numOfThreads $DEAGLE24_PRE3_PARALLEL $MYBENCHDIR/deagle24-pre-3.xml
cd $DEAGLE24_DIR
$BENCHEXEC --numOfThreads $DEAGLE24_PARALLEL $MYBENCHDIR/deagle24.xml

# Generate table with merged results
cd $RESULTSDIR
cp $MYBENCHDIR/table-generator.xml table-generator.xml
table-generator -x table-generator.xml

# Decompress all tool outputs for table HTML links
unzip -o deagle23.*.logfiles.zip
unzip -o deagle24-pre-1.*.logfiles.zip
unzip -o deagle24-pre-2.*.logfiles.zip
unzip -o deagle24-pre-3.*.logfiles.zip
unzip -o deagle24.*.logfiles.zip
