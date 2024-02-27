#!/bin/bash

shopt -s extglob
set -e

MYBENCHDIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
# RESULTSDIR=$MYBENCHDIR/../results/eval-prec
RESULTSDIR=/mnt/goblint-svcomp/benchexec/results/oopsla-1-svcomp24
# GOBLINTDIR=$MYBENCHDIR/../goblint
GOBLINTDIR=/mnt/goblint-svcomp/sv-comp/goblint
GOBLINT_PARALLEL=2
GOBLINT23DIR=/mnt/goblint-svcomp/benchexec/tools-pldi/goblint
GOBLINT23_PARALLEL=1
GOBLINT24DIR=/mnt/goblint-svcomp/benchexec/tools-pldi24/goblint
GOBLINT24_PARALLEL=1
CPACHECKER23_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi/CPAchecker-2.2-unix
CPACHECKER23_PARALLEL=1
CPACHECKER24_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi24/CPAchecker-2.3-unix
CPACHECKER24_PARALLEL=1
DARTAGNAN23_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi/dartagnan
DARTAGNAN23_PARALLEL=1
DARTAGNAN24_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi24/dartagnan
DARTAGNAN24_PARALLEL=1
DEAGLE23_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi/deagle
DEAGLE23_PARALLEL=1
DEAGLE23_PURE_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi/deagle-pure
DEAGLE23_PURE_PARALLEL=1
DEAGLE24_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi24/deagle
DEAGLE24_PARALLEL=1
ESBMC_KIND24_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi24/esbmc-kind
ESBMC_KIND24_PARALLEL=1
LOCKSMITH_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi/locksmith
LOCKSMITH_PARALLEL=1
THETA23_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi/theta
THETA23_PARALLEL=1
THETA24_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi24/Theta
THETA24_PARALLEL=1
ULTIMATE23_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi/UAutomizer-linux
ULTIMATE23_PARALLEL=1
ULTIMATE24_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi24/UAutomizer-linux
ULTIMATE24_PARALLEL=1
RELAY_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi/relay-sv
RELAY_PARALLEL=1
TSAN_DIR=/mnt/goblint-svcomp/benchexec/tools-pldi/sv-sanitizers
TSAN_PARALLEL=2

# read-only and overlay dirs for Value too large for defined data type workaround
BENCHEXEC="benchexec --read-only-dir / --overlay-dir . --overlay-dir /home --outputpath $RESULTSDIR"

mkdir $RESULTSDIR || true

# Run verification
# cd $GOBLINTDIR
# $BENCHEXEC --numOfThreads $GOBLINT_PARALLEL $MYBENCHDIR/goblint.xml

cd $GOBLINT23DIR
$BENCHEXEC --numOfThreads $GOBLINT23_PARALLEL $MYBENCHDIR/goblint23.xml
cd $GOBLINT24DIR
$BENCHEXEC --numOfThreads $GOBLINT24_PARALLEL $MYBENCHDIR/goblint24.xml

cd $CPACHECKER23_DIR
$BENCHEXEC --numOfThreads $CPACHECKER23_PARALLEL $MYBENCHDIR/cpachecker23.xml
cd $CPACHECKER24_DIR
$BENCHEXEC --numOfThreads $CPACHECKER24_PARALLEL $MYBENCHDIR/cpachecker24.xml

cd $DARTAGNAN23_DIR
$BENCHEXEC --numOfThreads $DARTAGNAN23_PARALLEL $MYBENCHDIR/dartagnan23.xml
cd $DARTAGNAN24_DIR
$BENCHEXEC --numOfThreads $DARTAGNAN24_PARALLEL $MYBENCHDIR/dartagnan24.xml

cd $DEAGLE23_DIR
$BENCHEXEC --numOfThreads $DEAGLE23_PARALLEL $MYBENCHDIR/deagle23.xml
# cd $DEAGLE23_PURE_DIR
# $BENCHEXEC --numOfThreads $DEAGLE23_PURE_PARALLEL $MYBENCHDIR/deagle23-pure.xml
cd $DEAGLE24_DIR
$BENCHEXEC --numOfThreads $DEAGLE24_PARALLEL $MYBENCHDIR/deagle24.xml

cd $ESBMC_KIND24_DIR
$BENCHEXEC --numOfThreads $ESBMC_KIND24_PARALLEL $MYBENCHDIR/esbmc-kind24.xml

cd $LOCKSMITH_DIR
$BENCHEXEC --numOfThreads $LOCKSMITH_PARALLEL $MYBENCHDIR/locksmith.xml

cd $THETA23_DIR
$BENCHEXEC --numOfThreads $THETA23_PARALLEL $MYBENCHDIR/theta23.xml
cd $THETA24_DIR
$BENCHEXEC --numOfThreads $THETA24_PARALLEL $MYBENCHDIR/theta24.xml

cd $ULTIMATE23_DIR
$BENCHEXEC --numOfThreads $ULTIMATE23_PARALLEL $MYBENCHDIR/uautomizer23.xml
cd $ULTIMATE24_DIR
$BENCHEXEC --numOfThreads $ULTIMATE24_PARALLEL $MYBENCHDIR/uautomizer24.xml

# cd $RELAY_DIR
# $BENCHEXEC --numOfThreads $RELAY_PARALLEL $MYBENCHDIR/relay.xml

# cd $TSAN_DIR
# $BENCHEXEC --numOfThreads $TSAN_PARALLEL $MYBENCHDIR/tsan.xml

# Generate table with merged results
cd $RESULTSDIR
cp $MYBENCHDIR/table-generator.xml table-generator.xml
table-generator -x table-generator.xml

# Decompress all tool outputs for table HTML links
# unzip -o goblint.*.logfiles.zip
unzip -o goblint23.*.logfiles.zip
unzip -o goblint24.*.logfiles.zip
unzip -o cpachecker23.*.logfiles.zip
unzip -o cpachecker24.*.logfiles.zip
unzip -o dartagnan23.*.logfiles.zip
unzip -o dartagnan24.*.logfiles.zip
unzip -o deagle23.*.logfiles.zip
# unzip -o deagle23-pure.*.logfiles.zip
unzip -o deagle24.*.logfiles.zip
unzip -o esbmc-kind24.*.logfiles.zip
unzip -o locksmith.*.logfiles.zip
unzip -o theta23.*.logfiles.zip
unzip -o theta24.*.logfiles.zip
unzip -o uautomizer23.*.logfiles.zip
unzip -o uautomizer24.*.logfiles.zip
# unzip -o relay.*.logfiles.zip
# unzip -o tsan.*.logfiles.zip
