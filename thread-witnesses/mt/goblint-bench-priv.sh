#!/bin/bash

shopt -s extglob

MYBENCHDIR=/mnt/goblint-svcomp/benchexec/my-bench-sv-comp/yaml
RESULTSDIR=/mnt/goblint-svcomp/benchexec/results/yaml-15-bench-priv-validate2
GOBLINTPARALLEL=14
VALIDATEPARALLEL=14

mkdir $RESULTSDIR

# Run verification
cd /mnt/goblint-svcomp/sv-comp/goblint
# read-only and overlay dirs for Value too large for defined data type workaround
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $GOBLINTPARALLEL $MYBENCHDIR/goblint-bench-priv.xml

# Extract witness directory
cd $RESULTSDIR
LOGDIR=`echo goblint-bench-priv.*.files`
echo $LOGDIR

# Construct validation XMLs
cd $MYBENCHDIR
sed -e "s|RESULTSDIR|$RESULTSDIR|" -e "s/LOGDIR/$LOGDIR/" goblint-bench-priv-validate1.xml > goblint-bench-priv-validate1-tmp.xml
sed -e "s|RESULTSDIR|$RESULTSDIR|" -e "s/LOGDIR/$LOGDIR/" goblint-bench-priv-validate2.xml > goblint-bench-priv-validate2-tmp.xml
sed -e "s|RESULTSDIR|$RESULTSDIR|" -e "s/LOGDIR/$LOGDIR/" goblint-bench-priv-validate3.xml > goblint-bench-priv-validate3-tmp.xml

# Run validation
cd /mnt/goblint-svcomp/sv-comp/goblint
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $VALIDATEPARALLEL $MYBENCHDIR/goblint-bench-priv-validate1-tmp.xml
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $VALIDATEPARALLEL $MYBENCHDIR/goblint-bench-priv-validate2-tmp.xml
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $VALIDATEPARALLEL $MYBENCHDIR/goblint-bench-priv-validate3-tmp.xml

# Merge witness validation results
cd $RESULTSDIR
# python3 /mnt/goblint-svcomp/benchexec/benchexec/contrib/mergeBenchmarkSets.py -o . goblint.*.results.*.xml.bz2 goblint-validate-tmp.*.results.*.xml.bz2
python3 /mnt/goblint-svcomp/benchexec/benchexec/contrib/mergeBenchmarkSets.py -o . goblint-bench-priv.*.results.protection-read.Pthread.xml.bz2 goblint-bench-priv-validate*-tmp.*.results.protection-read.Pthread.xml.bz2
python3 /mnt/goblint-svcomp/benchexec/benchexec/contrib/mergeBenchmarkSets.py -o . goblint-bench-priv.*.results.mine.Pthread.xml.bz2 goblint-bench-priv-validate*-tmp.*.results.mine.Pthread.xml.bz2
python3 /mnt/goblint-svcomp/benchexec/benchexec/contrib/mergeBenchmarkSets.py -o . goblint-bench-priv.*.results.write+lock.Pthread.xml.bz2 goblint-bench-priv-validate*-tmp.*.results.write+lock.Pthread.xml.bz2

# Generate table with merged results and witness validation results
sed -e "s/LOGDIR/$LOGDIR/" $MYBENCHDIR/table-generator-bench-priv.xml > table-generator.xml
table-generator -x table-generator.xml

# Decompress all tool outputs for table HTML links
unzip -o goblint-bench-priv.*.logfiles.zip
unzip -o goblint-bench-priv-validate1-tmp.*.logfiles.zip
unzip -o goblint-bench-priv-validate2-tmp.*.logfiles.zip
unzip -o goblint-bench-priv-validate3-tmp.*.logfiles.zip
