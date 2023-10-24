#!/bin/bash

for cfile in *.c
do
    base=$(basename $cfile .c)
    ifile="$base.i"
    echo $base

    gcc -E -P -m32 $cfile -o $ifile
done
