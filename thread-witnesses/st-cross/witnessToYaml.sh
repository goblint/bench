#!/bin/bash

MYBENCHDIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
AUTOACTIVEDIR=$MYBENCHDIR/../../../autoactive

cp $MYBENCHDIR/witnessToYaml.xml $AUTOACTIVEDIR/plain/

cd $AUTOACTIVEDIR

# rm -rf resultsgenyaml
benchexec --tool-directory ../CPAchecker-2.2-unix -N5 -c1 --read-only-dir / --hidden-dir /home --overlay-dir . plain/witnessToYaml.xml -o resultsgenyaml2/

# rm -rf generated_yaml
for tool in $(cat producers.txt) ; do
  mkdir -p generated_yaml2/$tool ;
  for dir in resultsgenyaml2/*files/$tool/* ; do
    echo $dir
    cat $dir/output/invariantWitnesses/*.yaml | sed -e 's|plain|../plain|g' -e 's|loop_invariant|location_invariant|g' > generated_yaml2/$tool/$(basename $dir).witness.yml
  done
done
