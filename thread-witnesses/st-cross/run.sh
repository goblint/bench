#!/bin/bash

shopt -s extglob

MYBENCHDIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
AUTOACTIVEDIR=$MYBENCHDIR/../../../autoactive
RESULTSDIR=$MYBENCHDIR/../../../results/st-cross
OURTOOLPARALLEL=14
VALIDATEPARALLEL=14

mkdir $RESULTSDIR

# Run verification
cp $MYBENCHDIR/ourtool.xml $AUTOACTIVEDIR/generated_yaml/

cd $MYBENCHDIR/../../../ourtool
# read-only and overlay dirs for Value too large for defined data type workaround
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $OURTOOLPARALLEL $AUTOACTIVEDIR/generated_yaml/ourtool.xml

# Run validation
cp $MYBENCHDIR/ourtool-validate.xml $AUTOACTIVEDIR/generated_yaml/

cd $MYBENCHDIR/../../../ourtool
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $VALIDATEPARALLEL $AUTOACTIVEDIR/generated_yaml/ourtool-validate.xml

# Merge witness validation results
cd $RESULTSDIR

# Generate table with merged results and witness validation results
table-generator ourtool.*.xml.bz2 ourtool-validate.*.xml.bz2

# Decompress all tool outputs for table HTML links
unzip -o ourtool.*.logfiles.zip
unzip -o ourtool-validate.*.logfiles.zip
