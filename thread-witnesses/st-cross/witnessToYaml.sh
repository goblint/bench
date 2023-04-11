#!/bin/bash

MYBENCHDIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
AUTOACTIVEDIR=$MYBENCHDIR/../../../autoactive
RESULTSGENYAML=resultsgenyaml
GENERATEDYAML=generated_yaml

cp $MYBENCHDIR/witnessToYaml.xml $AUTOACTIVEDIR/plain/

cd $AUTOACTIVEDIR

# rm -rf $RESULTSGENYAML
benchexec --tool-directory ../CPAchecker-2.2-unix -N5 -c1 --read-only-dir / --hidden-dir /home --overlay-dir . plain/witnessToYaml.xml -o $RESULTSGENYAML/

# rm -rf $GENERATEDYAML
for tool in $(cat producers.txt) ; do
  mkdir -p $GENERATEDYAML/$tool ;
  for dir in $RESULTSGENYAML/*files/$tool/* ; do
    echo $dir
    cat $dir/output/invariantWitnesses/*.yaml | sed -e 's|plain|../plain|g' -e 's|loop_invariant|location_invariant|g' > $GENERATEDYAML/$tool/$(basename $dir).witness.yml
  done
done
