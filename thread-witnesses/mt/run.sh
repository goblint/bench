#!/bin/bash

shopt -s extglob

MYBENCHDIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
RESULTSDIR=$MYBENCHDIR/../../../results/mt-900
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
sed -e "s|RESULTSDIR|$RESULTSDIR|" -e "s/LOGDIR/$LOGDIR/" ourtool-validate-protection-read.xml > ourtool-validate-protection-read-tmp.xml
sed -e "s|RESULTSDIR|$RESULTSDIR|" -e "s/LOGDIR/$LOGDIR/" ourtool-validate-mine.xml > ourtool-validate-mine-tmp.xml
sed -e "s|RESULTSDIR|$RESULTSDIR|" -e "s/LOGDIR/$LOGDIR/" ourtool-validate-write+lock.xml > ourtool-validate-write+lock-tmp.xml

# Run validation
cd $MYBENCHDIR/../../../ourtool
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $VALIDATEPARALLEL $MYBENCHDIR/ourtool-validate-protection-read-tmp.xml
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $VALIDATEPARALLEL $MYBENCHDIR/ourtool-validate-mine-tmp.xml
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $VALIDATEPARALLEL $MYBENCHDIR/ourtool-validate-write+lock-tmp.xml

# Merge witness validation results
cd $RESULTSDIR
python3 $MYBENCHDIR/../../../benchexec/contrib/mergeBenchmarkSets.py -o . ourtool.*.results.protection-read.Pthread.xml.bz2 ourtool-validate-protection-read-tmp.*.results.protection-read.Pthread.xml.bz2 ourtool-validate-mine-tmp.*.results.protection-read.Pthread.xml.bz2 ourtool-validate-write+lock-tmp.*.results.protection-read.Pthread.xml.bz2
python3 $MYBENCHDIR/../../../benchexec/contrib/mergeBenchmarkSets.py -o . ourtool.*.results.mine.Pthread.xml.bz2 ourtool-validate-protection-read-tmp.*.results.mine.Pthread.xml.bz2 ourtool-validate-mine-tmp.*.results.mine.Pthread.xml.bz2 ourtool-validate-write+lock-tmp.*.results.mine.Pthread.xml.bz2
python3 $MYBENCHDIR/../../../benchexec/contrib/mergeBenchmarkSets.py -o . ourtool.*.results.write+lock.Pthread.xml.bz2 ourtool-validate-protection-read-tmp.*.results.write+lock.Pthread.xml.bz2 ourtool-validate-mine-tmp.*.results.write+lock.Pthread.xml.bz2 ourtool-validate-write+lock-tmp.*.results.write+lock.Pthread.xml.bz2

# Generate table with merged results and witness validation results
sed -e "s/LOGDIR/$LOGDIR/" $MYBENCHDIR/table-generator.xml > table-generator.xml
table-generator -x table-generator.xml

# Decompress all tool outputs for table HTML links
unzip -o ourtool.*.logfiles.zip
unzip -o ourtool-validate-protection-read-tmp.*.logfiles.zip
unzip -o ourtool-validate-mine-tmp.*.logfiles.zip
unzip -o ourtool-validate-write+lock-tmp.*.logfiles.zip
