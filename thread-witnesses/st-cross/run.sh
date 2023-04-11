#!/bin/bash

shopt -s extglob

MYBENCHDIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
AUTOACTIVEDIR=$MYBENCHDIR/../../../autoactive
RESULTSDIR=$MYBENCHDIR/../../../results/st-cross
OURTOOLPARALLEL=4
CPACHECKERPARALLEL=4
VALIDATEPARALLEL=4

mkdir $RESULTSDIR

# Run verification
cp $MYBENCHDIR/ourtool.xml $AUTOACTIVEDIR/generated_yaml/

cd $AUTOACTIVEDIR/generated_yaml
# read-only and overlay dirs for Value too large for defined data type workaround
benchexec --tool-directory $MYBENCHDIR/../../../ourtool --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $OURTOOLPARALLEL ourtool.xml

# Extract witness directory
cd $RESULTSDIR
LOGDIR=`echo ourtool.*.files`
echo $LOGDIR

# Construct conversion XMLs
cd $MYBENCHDIR
sed -e "s|RESULTSDIR|$RESULTSDIR|" -e "s/LOGDIR/$LOGDIR/" convert.xml > $AUTOACTIVEDIR/generated_yaml/convert.xml

# Run conversion
cd $AUTOACTIVEDIR/generated_yaml
benchexec --tool-directory $MYBENCHDIR/../../../CPAchecker-2.2-unix --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $CPACHECKERPARALLEL convert.xml

cd $RESULTSDIR
LOGDIR3=`echo convert.*.files`
echo $LOGDIR3

for dir in $LOGDIR3/ourtool/* ; do
    echo $dir
    cat $dir/output/invariantWitnesses/*.yaml | sed -e 's|loop_invariant|location_invariant|g' > $dir/witness.yml
done

# Construct validation XMLs
cd $MYBENCHDIR
sed -e "s|RESULTSDIR|$RESULTSDIR|" -e "s/LOGDIR3/$LOGDIR3/" -e "s/LOGDIR/$LOGDIR/" ourtool-validate-self.xml > $AUTOACTIVEDIR/generated_yaml/ourtool-validate-self.xml

# Run validation
cp $MYBENCHDIR/ourtool-validate.xml $AUTOACTIVEDIR/generated_yaml/

cd $AUTOACTIVEDIR/generated_yaml
benchexec --tool-directory $MYBENCHDIR/../../../ourtool --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $VALIDATEPARALLEL ourtool-validate-self.xml
benchexec --tool-directory $MYBENCHDIR/../../../ourtool --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $VALIDATEPARALLEL ourtool-validate.xml

# Merge witness validation results
cd $RESULTSDIR

# Generate table with merged results and witness validation results
table-generator ourtool.*.xml.bz2 ourtool-validate-self.*.xml.bz2 ourtool-validate.*.xml.bz2

# Decompress all tool outputs for table HTML links
unzip -o ourtool.*.logfiles.zip
unzip -o convert.*.logfiles.zip
unzip -o ourtool-validate-self.*.logfiles.zip
unzip -o ourtool-validate.*.logfiles.zip
