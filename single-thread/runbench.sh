#!/bin/sh

pushd ../analyzer2
./make.sh opt
popd

ulimit -Ss 49152
export OCAMLRUNPARAM=s=32M,i=32M,o=150

CMD="../analyzer2/goblint --conf bench.json"

date > result.txt;


for f in `ls *.c` 
do
  echo ${f};
  echo "" >> result.txt;
  echo ${f} >> result.txt ;
	${CMD} ${f};
done

#mv result.txt result.sens.widen.txt
