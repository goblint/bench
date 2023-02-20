#!/bin/bash

shopt -s extglob

MYBENCHDIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
RESULTSDIR=$MYBENCHDIR/../../../results/st-lit-location
OURTOOLPARALLEL=14
CPACHECKERPARALLEL=4
ULTIMATEPARALLEL=4
VALIDATEPARALLEL=14

mkdir $RESULTSDIR

# Run verification
cd $MYBENCHDIR/../../../ourtool
# read-only and overlay dirs for Value too large for defined data type workaround
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $OURTOOLPARALLEL $MYBENCHDIR/ourtool.xml

cd $MYBENCHDIR/../../../CPAchecker-2.2-unix
# read-only and overlay dirs for Value too large for defined data type workaround
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $CPACHECKERPARALLEL $MYBENCHDIR/cpachecker.xml

cd $MYBENCHDIR/../../../UAutomizer-linux
# read-only and overlay dirs for Value too large for defined data type workaround
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $ULTIMATEPARALLEL $MYBENCHDIR/uautomizer.xml

# Extract witness directory
cd $RESULTSDIR
LOGDIR=`echo ourtool.*.files`
echo $LOGDIR
LOGDIR2=`echo cpachecker.*.files`
echo $LOGDIR2
LOGDIR4=`echo uautomizer.*.files`
echo $LOGDIR4

# Construct conversion XMLs
cd $MYBENCHDIR
sed -e "s|RESULTSDIR|$RESULTSDIR|" -e "s/LOGDIR4/$LOGDIR4/" -e "s/LOGDIR2/$LOGDIR2/" -e "s/LOGDIR/$LOGDIR/" convert.xml > convert-tmp.xml

# Run conversion
cd $MYBENCHDIR/../../../CPAchecker-2.2-unix
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $CPACHECKERPARALLEL $MYBENCHDIR/convert-tmp.xml

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
sed -e "s|RESULTSDIR|$RESULTSDIR|" -e "s/LOGDIR3/$LOGDIR3/" -e "s/LOGDIR2/$LOGDIR2/" -e "s/LOGDIR/$LOGDIR/" ourtool-validate.xml > ourtool-validate-tmp.xml

# Run validation
cd $MYBENCHDIR/../../../ourtool
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $VALIDATEPARALLEL $MYBENCHDIR/ourtool-validate-tmp.xml

# Merge witness validation results
cd $RESULTSDIR
python3 $MYBENCHDIR/../../../benchexec/contrib/mergeBenchmarkSets.py -o . ourtool.*.results.ourtool.Prec.xml.bz2 ourtool-validate-tmp.*.results.ourtool.Prec.xml.bz2
python3 $MYBENCHDIR/../../../benchexec/contrib/mergeBenchmarkSets.py -o . cpachecker.*.results.cpachecker.Prec.xml.bz2 ourtool-validate-tmp.*.results.cpachecker.Prec.xml.bz2
python3 $MYBENCHDIR/../../../benchexec/contrib/mergeBenchmarkSets.py -o . uautomizer.*.results.uautomizer.Prec.xml.bz2 ourtool-validate-tmp.*.results.uautomizer.Prec.xml.bz2

# Generate table with merged results and witness validation results
sed -e "s/LOGDIR3/$LOGDIR3/" -e "s/LOGDIR2/$LOGDIR2/" -e "s/LOGDIR/$LOGDIR/" $MYBENCHDIR/table-generator.xml > table-generator.xml
table-generator -x table-generator.xml
table-generator -x table-generator.xml --correct-only -n correct

# Decompress all tool outputs for table HTML links
unzip -o ourtool.*.logfiles.zip
unzip -o cpachecker.*.logfiles.zip
unzip -o uautomizer.*.logfiles.zip
unzip -o convert-tmp.*.logfiles.zip
unzip -o ourtool-validate-tmp.*.logfiles.zip
