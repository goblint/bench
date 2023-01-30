#!/bin/bash

shopt -s extglob

MYBENCHDIR=/mnt/goblint-svcomp/benchexec/my-bench-sv-comp/yaml
RESULTSDIR=/mnt/goblint-svcomp/benchexec/results/yaml-prec-07-guide
GOBLINTPARALLEL=14
CPACHECKERPARALLEL=4
ULTIMATEPARALLEL=4
VALIDATEPARALLEL=14

mkdir $RESULTSDIR

# Run verification
cd /mnt/goblint-svcomp/sv-comp/goblint
# read-only and overlay dirs for Value too large for defined data type workaround
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $GOBLINTPARALLEL $MYBENCHDIR/prec-goblint.xml
cd /mnt/goblint-svcomp/benchexec/autoactive/cpachecker
# read-only and overlay dirs for Value too large for defined data type workaround
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $CPACHECKERPARALLEL $MYBENCHDIR/prec-cpachecker.xml
cd /mnt/goblint-svcomp/benchexec/autoactive/UAutomizer-linux
# read-only and overlay dirs for Value too large for defined data type workaround
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $ULTIMATEPARALLEL $MYBENCHDIR/prec-uautomizer.xml

# Extract witness directory
cd $RESULTSDIR
LOGDIR=`echo prec-goblint.*.files`
echo $LOGDIR
LOGDIR2=`echo prec-cpachecker.*.files`
echo $LOGDIR2
LOGDIR4=`echo prec-uautomizer.*.files`
echo $LOGDIR4

# Construct conversion XMLs
cd $MYBENCHDIR
sed -e "s|RESULTSDIR|$RESULTSDIR|" -e "s/LOGDIR4/$LOGDIR4/" -e "s/LOGDIR2/$LOGDIR2/" -e "s/LOGDIR/$LOGDIR/" prec-convert.xml > prec-convert-tmp.xml

# Run conversion
cd /mnt/goblint-svcomp/benchexec/autoactive/cpachecker
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $CPACHECKERPARALLEL $MYBENCHDIR/prec-convert-tmp.xml

cd $RESULTSDIR
LOGDIR3=`echo prec-convert-tmp.*.files`
echo $LOGDIR3

for dir in $LOGDIR3/prec-cpachecker/* ; do
    echo $dir
    cat $dir/output/invariantWitnesses/*.yaml > $dir/witness.yml
done
for dir in $LOGDIR3/prec-uautomizer/* ; do
    echo $dir
    cat $dir/output/invariantWitnesses/*.yaml > $dir/witness.yml
done

# Construct validation XMLs
cd $MYBENCHDIR
sed -e "s|RESULTSDIR|$RESULTSDIR|" -e "s/LOGDIR3/$LOGDIR3/" -e "s/LOGDIR2/$LOGDIR2/" -e "s/LOGDIR/$LOGDIR/" prec-validate.xml > prec-validate-tmp.xml

# Run validation
cd /mnt/goblint-svcomp/sv-comp/goblint
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $VALIDATEPARALLEL $MYBENCHDIR/prec-validate-tmp.xml

# Merge witness validation results
cd $RESULTSDIR
python3 /mnt/goblint-svcomp/benchexec/benchexec/contrib/mergeBenchmarkSets.py -o . prec-goblint.*.results.prec-goblint.Prec.xml.bz2 prec-validate-tmp.*.results.prec-goblint.Prec.xml.bz2
python3 /mnt/goblint-svcomp/benchexec/benchexec/contrib/mergeBenchmarkSets.py -o . prec-cpachecker.*.results.prec-cpachecker.Prec.xml.bz2 prec-validate-tmp.*.results.prec-cpachecker.Prec.xml.bz2
python3 /mnt/goblint-svcomp/benchexec/benchexec/contrib/mergeBenchmarkSets.py -o . prec-uautomizer.*.results.prec-uautomizer.Prec.xml.bz2 prec-validate-tmp.*.results.prec-uautomizer.Prec.xml.bz2

# Generate table with merged results and witness validation results
sed -e "s/LOGDIR3/$LOGDIR3/" -e "s/LOGDIR2/$LOGDIR2/" -e "s/LOGDIR/$LOGDIR/" $MYBENCHDIR/prec-table-generator.xml > table-generator.xml
table-generator -x table-generator.xml
table-generator -x table-generator.xml --correct-only -n correct

# Decompress all tool outputs for table HTML links
unzip -o prec-goblint.*.logfiles.zip
unzip -o prec-cpachecker.*.logfiles.zip
unzip -o prec-uautomizer.*.logfiles.zip
unzip -o prec-convert-tmp.*.logfiles.zip
unzip -o prec-validate-tmp.*.logfiles.zip
