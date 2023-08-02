#!/bin/bash

shopt -s extglob
set -e

MYBENCHDIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
RESULTSDIR=$MYBENCHDIR/../results/eval-perf
GOBLINT_PARALLEL=2

# read-only and overlay dirs for Value too large for defined data type workaround
BENCHEXEC="benchexec --read-only-dir / --overlay-dir . --overlay-dir /home --outputpath $RESULTSDIR"

mkdir $RESULTSDIR || true

# Run verification
cd $MYBENCHDIR/../goblint
$BENCHEXEC --numOfThreads $GOBLINT_PARALLEL $MYBENCHDIR/goblint.xml

# Construct validation XMLs
cd $MYBENCHDIR
sed -e "s|MYBENCHDIR|$MYBENCHDIR|" goblint-guided.xml > goblint-guided-tmp.xml
sed -e "s|MYBENCHDIR|$MYBENCHDIR|" goblint-validate.xml > goblint-validate-tmp.xml

# Run validation
cd $MYBENCHDIR/../goblint
$BENCHEXEC --numOfThreads $GOBLINT_PARALLEL $MYBENCHDIR/goblint-guided-tmp.xml
$BENCHEXEC --numOfThreads $GOBLINT_PARALLEL $MYBENCHDIR/goblint-validate-tmp.xml

# Generate table with merged results and witness validation results
cd $RESULTSDIR
cp $MYBENCHDIR/table-generator.xml table-generator.xml
table-generator -x table-generator.xml

# Decompress all tool outputs for table HTML links
unzip -o goblint.*.logfiles.zip
unzip -o goblint-guided-tmp.*.logfiles.zip
unzip -o goblint-validate-tmp.*.logfiles.zip
