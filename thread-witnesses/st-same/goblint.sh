#!/bin/bash

shopt -s extglob

MYBENCHDIR=/mnt/goblint-svcomp/benchexec/my-bench-sv-comp/yaml
RESULTSDIR=/mnt/goblint-svcomp/benchexec/results/yaml-19-loops-apron-validate-svcomp22
GOBLINTPARALLEL=14
VALIDATEPARALLEL=14

mkdir $RESULTSDIR

# Run verification
cd /mnt/goblint-svcomp/sv-comp/goblint
# read-only and overlay dirs for Value too large for defined data type workaround
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $GOBLINTPARALLEL $MYBENCHDIR/goblint.xml

# Extract witness directory
cd $RESULTSDIR
LOGDIR=`echo goblint.*.files`
echo $LOGDIR

# Construct validation XMLs
cd $MYBENCHDIR
sed -e "s|RESULTSDIR|$RESULTSDIR|" -e "s/LOGDIR/$LOGDIR/" goblint-validate.xml > goblint-validate-tmp.xml

# Run validation
cd /mnt/goblint-svcomp/sv-comp/goblint
benchexec --read-only-dir / --overlay-dir . --hidden-dir /home --outputpath $RESULTSDIR --numOfThreads $VALIDATEPARALLEL $MYBENCHDIR/goblint-validate-tmp.xml

# Merge witness validation results
cd $RESULTSDIR
# python3 /mnt/goblint-svcomp/benchexec/benchexec/contrib/mergeBenchmarkSets.py -o . goblint.*.results.*.xml.bz2 goblint-validate-tmp.*.results.*.xml.bz2

# python3 /mnt/goblint-svcomp/benchexec/benchexec/contrib/mergeBenchmarkSets.py -o . goblint.*.results.all.ReachSafety-Loops.xml.bz2 goblint-validate-tmp.*.results.all.ReachSafety-Loops.xml.bz2
# python3 /mnt/goblint-svcomp/benchexec/benchexec/contrib/mergeBenchmarkSets.py -o . goblint.*.results.accessed.ReachSafety-Loops.xml.bz2 goblint-validate-tmp.*.results.accessed.ReachSafety-Loops.xml.bz2
python3 /mnt/goblint-svcomp/benchexec/benchexec/contrib/mergeBenchmarkSets.py -o . goblint.*.results.loop-head.ReachSafety-Loops.xml.bz2 goblint-validate-tmp.*.results.loop-head.ReachSafety-Loops.xml.bz2

# python3 /mnt/goblint-svcomp/benchexec/benchexec/contrib/mergeBenchmarkSets.py -o . goblint.*.results.all.ReachSafety-ProductLines.xml.bz2 goblint-validate-tmp.*.results.all.ReachSafety-ProductLines.xml.bz2
# python3 /mnt/goblint-svcomp/benchexec/benchexec/contrib/mergeBenchmarkSets.py -o . goblint.*.results.accessed.ReachSafety-ProductLines.xml.bz2 goblint-validate-tmp.*.results.accessed.ReachSafety-ProductLines.xml.bz2
# python3 /mnt/goblint-svcomp/benchexec/benchexec/contrib/mergeBenchmarkSets.py -o . goblint.*.results.loop-head.ReachSafety-ProductLines.xml.bz2 goblint-validate-tmp.*.results.loop-head.ReachSafety-ProductLines.xml.bz2

# python3 /mnt/goblint-svcomp/benchexec/benchexec/contrib/mergeBenchmarkSets.py -o . goblint.*.results.all.SoftwareSystems-DeviceDriversLinux64-ReachSafety.xml.bz2 goblint-validate-tmp.*.results.all.SoftwareSystems-DeviceDriversLinux64-ReachSafety.xml.bz2
# python3 /mnt/goblint-svcomp/benchexec/benchexec/contrib/mergeBenchmarkSets.py -o . goblint.*.results.accessed.SoftwareSystems-DeviceDriversLinux64-ReachSafety.xml.bz2 goblint-validate-tmp.*.results.accessed.SoftwareSystems-DeviceDriversLinux64-ReachSafety.xml.bz2
# python3 /mnt/goblint-svcomp/benchexec/benchexec/contrib/mergeBenchmarkSets.py -o . goblint.*.results.loop-head.SoftwareSystems-DeviceDriversLinux64-ReachSafety.xml.bz2 goblint-validate-tmp.*.results.loop-head.SoftwareSystems-DeviceDriversLinux64-ReachSafety.xml.bz2

# Generate table with merged results and witness validation results
sed -e "s/LOGDIR/$LOGDIR/" $MYBENCHDIR/table-generator.xml > table-generator.xml
table-generator -x table-generator.xml
table-generator -x table-generator.xml --correct-only -n correct

# Decompress all tool outputs for table HTML links
unzip -o goblint.*.logfiles.zip
unzip -o goblint-validate-tmp.*.logfiles.zip
