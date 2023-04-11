#!/bin/bash

shopt -s extglob

MYBENCHDIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
RESULTSDIR=$MYBENCHDIR/../../../results/st-same
OURTOOLPARALLEL=4
VALIDATEPARALLEL=4

mkdir $RESULTSDIR

# Run verification
cd $MYBENCHDIR/../../../ourtool
# read-only and overlay dirs for Value too large for defined data type workaround
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $OURTOOLPARALLEL $MYBENCHDIR/ourtool.xml

# Extract witness directory
cd $RESULTSDIR
LOGDIR=`echo ourtool.*.files`
echo $LOGDIR

# Construct validation XMLs
cd $MYBENCHDIR
sed -e "s|RESULTSDIR|$RESULTSDIR|" -e "s/LOGDIR/$LOGDIR/" ourtool-validate.xml > ourtool-validate-tmp.xml

# Run validation
cd $MYBENCHDIR/../../../ourtool
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $VALIDATEPARALLEL $MYBENCHDIR/ourtool-validate-tmp.xml

# Merge witness validation results
cd $RESULTSDIR
python3 $MYBENCHDIR/../../../benchexec/contrib/mergeBenchmarkSets.py -o . ourtool.*.results.loop-head.ReachSafety-Loops.xml.bz2 ourtool-validate-tmp.*.results.loop-head.ReachSafety-Loops.xml.bz2

# Generate table with merged results and witness validation results
sed -e "s/LOGDIR/$LOGDIR/" $MYBENCHDIR/table-generator.xml > table-generator.xml
table-generator -x table-generator.xml
table-generator -x table-generator.xml --correct-only -n correct

# Decompress all tool outputs for table HTML links
unzip -o ourtool.*.logfiles.zip
unzip -o ourtool-validate-tmp.*.logfiles.zip
