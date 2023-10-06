#!/bin/bash

shopt -s extglob
set -e

MYBENCHDIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
# RESULTSDIR=$MYBENCHDIR/../results/eval-prec
RESULTSDIR=/mnt/goblint-svcomp/benchexec/results/pldi-02-goblint-concrat-svcomp-conf
# GOBLINTDIR=$MYBENCHDIR/../goblint
GOBLINTDIR=/mnt/goblint-svcomp/sv-comp/goblint
GOBLINT_PARALLEL=7
# CPACHECKER_PARALLEL=2
# ULTIMATE_PARALLEL=2

# read-only and overlay dirs for Value too large for defined data type workaround
BENCHEXEC="benchexec --read-only-dir / --overlay-dir . --overlay-dir /home --outputpath $RESULTSDIR"

mkdir $RESULTSDIR || true

# Run verification
cd $GOBLINTDIR
$BENCHEXEC --numOfThreads $GOBLINT_PARALLEL $MYBENCHDIR/goblint.xml

# cd $MYBENCHDIR/../CPAchecker-2.2-unix
# $BENCHEXEC --numOfThreads $CPACHECKER_PARALLEL $MYBENCHDIR/cpachecker.xml

# cd $MYBENCHDIR/../UAutomizer-linux
# $BENCHEXEC --numOfThreads $ULTIMATE_PARALLEL $MYBENCHDIR/uautomizer.xml

# Generate table with merged results and witness validation results
cd $RESULTSDIR
cp $MYBENCHDIR/table-generator.xml table-generator.xml
table-generator -x table-generator.xml
# cp $MYBENCHDIR/table-generator-full.xml table-generator-full.xml
# table-generator -x table-generator-full.xml -n full

# Decompress all tool outputs for table HTML links
unzip -o goblint.*.logfiles.zip
# unzip -o cpachecker.*.logfiles.zip
# unzip -o uautomizer.*.logfiles.zip
# unzip -o witness2invariant-tmp.*.logfiles.zip
# unzip -o goblint-guided-tmp.*.logfiles.zip
# unzip -o goblint-validate-tmp.*.logfiles.zip
