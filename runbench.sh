#!/bin/bash

#pushd ../analyzer
#./make.sh opt
#popd

ulimit -Ss 49152
export OCAMLRUNPARAM=s=4M,i=32M,o=150

FILES="single-thread/401.bzip2_comb.c
single-thread/429.mcf_comb.c"

OUTFILE=$1

WARMUP=true
N=2

CMD="../analyzer/goblint --conf conf.json"

if [ -z "$OUTFILE" ]
then
  echo "Output file is not specified"
  exit 1
fi

date > $OUTFILE

for f in $FILES
do
  echo $f
  echo "" >> $OUTFILE
  echo "============================================================" >> $OUTFILE
  echo $f >> $OUTFILE
  # warmup run
  if $WARMUP
  then
    echo "warmup"
	  ($CMD $f 2>&1) >> /dev/null
  fi
  for i in $(seq 1 $N) #{1..$N}
  do
    echo "Run #$i"
    echo "" >> $OUTFILE
    echo "Run #$i" >> $OUTFILE
    echo "------" >> $OUTFILE
	  ($CMD $f 2>&1) >> $OUTFILE
  done
done

