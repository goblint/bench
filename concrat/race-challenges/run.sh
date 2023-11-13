#!/bin/bash

shopt -s extglob
set -e

MYBENCHDIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
# RESULTSDIR=$MYBENCHDIR/../results/eval-prec
RESULTSDIR=/mnt/goblint-svcomp/benchexec/results/pldi-23-race-challenges-relay
# GOBLINTDIR=$MYBENCHDIR/../goblint
GOBLINTDIR=/mnt/goblint-svcomp/sv-comp/goblint
GOBLINT_PARALLEL=2
GOBLINT23DIR=/mnt/goblint-svcomp/benchexec/tools-pldi/goblint
GOBLINT23_PARALLEL=2
CPACHECKER_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi/CPAchecker-2.2-unix
CPACHECKER_PARALLEL=2
DARTAGNAN_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi/dartagnan
DARTAGNAN_PARALLEL=2
DEAGLE_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi/deagle
DEAGLE_PARALLEL=2
DEAGLE_PURE_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi/deagle-pure
DEAGLE_PURE_PARALLEL=2
LOCKSMITH_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi/locksmith
LOCKSMITH_PARALLEL=2
THETA_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi/theta
THETA_PARALLEL=2
ULTIMATE_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi/UAutomizer-linux
ULTIMATE_PARALLEL=2
RELAY_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi/relay-sv
RELAY_PARALLEL=2
TSAN_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi/sv-sanitizers
TSAN_PARALLEL=2

# read-only and overlay dirs for Value too large for defined data type workaround
BENCHEXEC="benchexec --read-only-dir / --overlay-dir . --overlay-dir /home --outputpath $RESULTSDIR"

mkdir $RESULTSDIR || true

# Run verification
# cd $GOBLINTDIR
# $BENCHEXEC --numOfThreads $GOBLINT_PARALLEL $MYBENCHDIR/goblint.xml

# cd $GOBLINT23DIR
# $BENCHEXEC --numOfThreads $GOBLINT23_PARALLEL $MYBENCHDIR/goblint23.xml

# cd $CPACHECKER_DIR
# $BENCHEXEC --numOfThreads $CPACHECKER_PARALLEL $MYBENCHDIR/cpachecker.xml

# cd $DARTAGNAN_DIR
# $BENCHEXEC --numOfThreads $DARTAGNAN_PARALLEL $MYBENCHDIR/dartagnan.xml

# cd $DEAGLE_DIR
# $BENCHEXEC --numOfThreads $DEAGLE_PARALLEL $MYBENCHDIR/deagle.xml

# cd $DEAGLE_PURE_DIR
# $BENCHEXEC --numOfThreads $DEAGLE_PURE_PARALLEL $MYBENCHDIR/deagle-pure.xml

# cd $LOCKSMITH_DIR
# $BENCHEXEC --numOfThreads $LOCKSMITH_PARALLEL $MYBENCHDIR/locksmith.xml

# cd $THETA_DIR
# $BENCHEXEC --numOfThreads $THETA_PARALLEL $MYBENCHDIR/theta.xml

# cd $ULTIMATE_DIR
# $BENCHEXEC --numOfThreads $ULTIMATE_PARALLEL $MYBENCHDIR/uautomizer.xml

cd $RELAY_DIR
$BENCHEXEC --numOfThreads $RELAY_PARALLEL $MYBENCHDIR/relay.xml

# cd $TSAN_DIR
# $BENCHEXEC --numOfThreads $TSAN_PARALLEL $MYBENCHDIR/tsan.xml

# Generate table with merged results
cd $RESULTSDIR
cp $MYBENCHDIR/table-generator.xml table-generator.xml
table-generator -x table-generator.xml

# Decompress all tool outputs for table HTML links
# unzip -o goblint.*.logfiles.zip
# unzip -o goblint23.*.logfiles.zip
# unzip -o cpachecker.*.logfiles.zip
# unzip -o dartagnan.*.logfiles.zip
# unzip -o deagle.*.logfiles.zip
# unzip -o deagle-pure.*.logfiles.zip
# unzip -o locksmith.*.logfiles.zip
# unzip -o theta.*.logfiles.zip
# unzip -o uautomizer.*.logfiles.zip
unzip -o relay.*.logfiles.zip
# unzip -o tsan.*.logfiles.zip
