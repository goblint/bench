#!/bin/bash

shopt -s extglob
set -e

MYBENCHDIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
RESULTSDIR=$MYBENCHDIR/../results/eval-prec
GOBLINTPARALLEL=1
CPACHECKERPARALLEL=1
ULTIMATEPARALLEL=1
VALIDATEPARALLEL=1

mkdir $RESULTSDIR || true

# Run verification
cd $MYBENCHDIR/../goblint
# read-only and overlay dirs for Value too large for defined data type workaround
benchexec --no-container --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $GOBLINTPARALLEL $MYBENCHDIR/goblint.xml

cd $MYBENCHDIR/../CPAchecker-2.2-unix
# read-only and overlay dirs for Value too large for defined data type workaround
benchexec --no-container --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $CPACHECKERPARALLEL $MYBENCHDIR/cpachecker.xml

cd $MYBENCHDIR/../UAutomizer-linux
# read-only and overlay dirs for Value too large for defined data type workaround
benchexec --no-container --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $ULTIMATEPARALLEL $MYBENCHDIR/uautomizer.xml

# Extract witness directory
cd $RESULTSDIR
LOGDIR=`echo goblint.*.files`
echo $LOGDIR
LOGDIR2=`echo cpachecker.*.files`
echo $LOGDIR2
LOGDIR4=`echo uautomizer.*.files`
echo $LOGDIR4

# Construct conversion XMLs
cd $MYBENCHDIR
sed -e "s|RESULTSDIR|$RESULTSDIR|" -e "s/LOGDIR4/$LOGDIR4/" -e "s/LOGDIR2/$LOGDIR2/" -e "s/LOGDIR/$LOGDIR/" convert.xml > convert-tmp.xml

# Run conversion
cd $MYBENCHDIR/../CPAchecker-2.2-unix
benchexec --no-container --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $CPACHECKERPARALLEL $MYBENCHDIR/convert-tmp.xml

cd $RESULTSDIR
LOGDIR3=`echo convert-tmp.*.files`
echo $LOGDIR3

for dir in $LOGDIR3/cpachecker/* ; do
    echo $dir
    cat $dir/output/invariantWitnesses/*.yaml | sed -e 's|loop_invariant|location_invariant|g' > $dir/witness.yml
done
for dir in $LOGDIR3/uautomizer/* ; do
    echo $dir
    cat $dir/output/invariantWitnesses/*.yaml | sed -e 's|loop_invariant|location_invariant|g' > $dir/witness.yml
done

# Construct validation XMLs
cd $MYBENCHDIR
sed -e "s|RESULTSDIR|$RESULTSDIR|" -e "s/LOGDIR3/$LOGDIR3/" -e "s/LOGDIR2/$LOGDIR2/" -e "s/LOGDIR/$LOGDIR/" goblint-validate.xml > goblint-validate-tmp.xml

# Run validation
cd $MYBENCHDIR/../goblint
benchexec --no-container --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $VALIDATEPARALLEL $MYBENCHDIR/goblint-validate-tmp.xml

# Merge witness validation results
cd $RESULTSDIR
python3 $MYBENCHDIR/../../../benchexec/contrib/mergeBenchmarkSets.py -o . goblint.*.results.goblint.Prec.xml.bz2 goblint-validate-tmp.*.results.goblint.Prec.xml.bz2
python3 $MYBENCHDIR/../../../benchexec/contrib/mergeBenchmarkSets.py -o . cpachecker.*.results.cpachecker.Prec.xml.bz2 goblint-validate-tmp.*.results.cpachecker.Prec.xml.bz2
python3 $MYBENCHDIR/../../../benchexec/contrib/mergeBenchmarkSets.py -o . uautomizer.*.results.uautomizer.Prec.xml.bz2 goblint-validate-tmp.*.results.uautomizer.Prec.xml.bz2

# Generate table with merged results and witness validation results
sed -e "s/LOGDIR3/$LOGDIR3/" -e "s/LOGDIR2/$LOGDIR2/" -e "s/LOGDIR/$LOGDIR/" $MYBENCHDIR/table-generator.xml > table-generator.xml
table-generator -x table-generator.xml
table-generator -x table-generator.xml --correct-only -n correct

# Decompress all tool outputs for table HTML links
unzip -o goblint.*.logfiles.zip
unzip -o cpachecker.*.logfiles.zip
unzip -o uautomizer.*.logfiles.zip
unzip -o convert-tmp.*.logfiles.zip
unzip -o goblint-validate-tmp.*.logfiles.zip
