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

cd $AUTOACTIVEDIR/generated_yaml
# read-only and overlay dirs for Value too large for defined data type workaround
benchexec --tool-directory $MYBENCHDIR/../../../ourtool --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $OURTOOLPARALLEL ourtool.xml

# Run validation
cp $MYBENCHDIR/ourtool-validate.xml $AUTOACTIVEDIR/generated_yaml/

cd $AUTOACTIVEDIR/generated_yaml
benchexec --tool-directory $MYBENCHDIR/../../../ourtool --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $VALIDATEPARALLEL ourtool-validate.xml

# Merge witness validation results
cd $RESULTSDIR

# Generate table with merged results and witness validation results
table-generator ourtool.*.xml.bz2 ourtool-validate.*.xml.bz2

# Decompress all tool outputs for table HTML links
unzip -o ourtool.*.logfiles.zip
unzip -o ourtool-validate.*.logfiles.zip
