#!/bin/bash

shopt -s extglob
set -e

MYBENCHDIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
RESULTSDIR=$MYBENCHDIR/../results/eval-prec
GOBLINT_PARALLEL=2
CPACHECKER_PARALLEL=2
ULTIMATE_PARALLEL=2

# read-only and overlay dirs for Value too large for defined data type workaround
BENCHEXEC="benchexec --read-only-dir / --overlay-dir . --overlay-dir /home --outputpath $RESULTSDIR"

mkdir $RESULTSDIR || true

# Run verification
cd $MYBENCHDIR/../goblint
$BENCHEXEC --numOfThreads $GOBLINT_PARALLEL $MYBENCHDIR/goblint.xml

cd $MYBENCHDIR/../CPAchecker-2.2-unix
$BENCHEXEC --numOfThreads $CPACHECKER_PARALLEL $MYBENCHDIR/cpachecker.xml

cd $MYBENCHDIR/../UAutomizer-linux
$BENCHEXEC --numOfThreads $ULTIMATE_PARALLEL $MYBENCHDIR/uautomizer.xml

# Extract witness directory
cd $RESULTSDIR
GOBLINT_FILES=`echo goblint.*.files`
echo $GOBLINT_FILES
CPACHECKER_FILES=`echo cpachecker.*.files`
echo $CPACHECKER_FILES
ULTIMATE_FILES=`echo uautomizer.*.files`
echo $ULTIMATE_FILES

# Construct conversion XMLs
cd $MYBENCHDIR
sed -e "s|RESULTSDIR|$RESULTSDIR|" -e "s/ULTIMATE_FILES/$ULTIMATE_FILES/" -e "s/CPACHECKER_FILES/$CPACHECKER_FILES/" witness2invariant.xml > witness2invariant-tmp.xml

# Run conversion
cd $MYBENCHDIR/../CPAchecker-2.2-unix
$BENCHEXEC --numOfThreads $CPACHECKER_PARALLEL $MYBENCHDIR/witness2invariant-tmp.xml

cd $RESULTSDIR
WITNESS2INVARIANT_FILES=`echo witness2invariant-tmp.*.files`
echo $WITNESS2INVARIANT_FILES

for dir in $WITNESS2INVARIANT_FILES/cpachecker/* ; do
    echo $dir
    cat $dir/output/invariantWitnesses/*.yaml | sed -e 's|loop_invariant|location_invariant|g' > $dir/witness.yml
done
for dir in $WITNESS2INVARIANT_FILES/uautomizer/* ; do
    echo $dir
    cat $dir/output/invariantWitnesses/*.yaml | sed -e 's|loop_invariant|location_invariant|g' > $dir/witness.yml
done

# Construct validation XMLs
cd $MYBENCHDIR
sed -e "s|MYBENCHDIR|$MYBENCHDIR|" -e "s|RESULTSDIR|$RESULTSDIR|" -e "s/WITNESS2INVARIANT_FILES/$WITNESS2INVARIANT_FILES/" -e "s/CPACHECKER_FILES/$CPACHECKER_FILES/" -e "s/GOBLINT_FILES/$GOBLINT_FILES/" goblint-guided.xml > goblint-guided-tmp.xml
sed -e "s|MYBENCHDIR|$MYBENCHDIR|" -e "s|RESULTSDIR|$RESULTSDIR|" -e "s/WITNESS2INVARIANT_FILES/$WITNESS2INVARIANT_FILES/" -e "s/CPACHECKER_FILES/$CPACHECKER_FILES/" -e "s/GOBLINT_FILES/$GOBLINT_FILES/" goblint-validate.xml > goblint-validate-tmp.xml

# Run validation
cd $MYBENCHDIR/../goblint
$BENCHEXEC --numOfThreads $GOBLINT_PARALLEL $MYBENCHDIR/goblint-guided-tmp.xml
$BENCHEXEC --numOfThreads $GOBLINT_PARALLEL $MYBENCHDIR/goblint-validate-tmp.xml

# Generate table with merged results and witness validation results
cd $RESULTSDIR
cp $MYBENCHDIR/table-generator.xml table-generator.xml
table-generator -x table-generator.xml
cp $MYBENCHDIR/table-generator-full.xml table-generator-full.xml
table-generator -x table-generator-full.xml -n full

# Decompress all tool outputs for table HTML links
unzip -o goblint.*.logfiles.zip
unzip -o cpachecker.*.logfiles.zip
unzip -o uautomizer.*.logfiles.zip
unzip -o witness2invariant-tmp.*.logfiles.zip
unzip -o goblint-guided-tmp.*.logfiles.zip
unzip -o goblint-validate-tmp.*.logfiles.zip
