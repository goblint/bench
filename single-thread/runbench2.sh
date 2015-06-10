#!/bin/sh

pushd ../analyzer2
./make.sh opt
popd

ulimit -Ss 49152
export OCAMLRUNPARAM=s=32M,i=32M,o=150

CMD="../analyzer2/goblint --conf bench.json"

echo "begin"
#echo ${CMD} --sets solver widen1 445.*.c 
#${CMD} --sets solver widen1 445.*.c > "result.2widen1.txt"
#echo ${CMD} --sets solver slr1   445.*.c 
#${CMD} --sets solver slr1   445.*.c > "result.2slr1.txt"
#echo ${CMD} --sets solver slr2   445.*.c 
#${CMD} --sets solver slr2   445.*.c > "result.2slr2.txt"
echo ${CMD} --sets solver slr3   445.*.c 
${CMD} --sets solver slr3   445.*.c > "result.2slr3.txt"
#echo ${CMD} --sets solver slr4   445.*.c 
#${CMD} --sets solver slr4   445.*.c > "result.2slr4.txt"
echo "done"

#mv result.txt result.sens.widen.txt
