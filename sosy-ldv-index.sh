#!/bin/bash

# Usage: ./sosy-ldv-index.sh >> index/traces-cpalockator.txt

for file in sosy-ldv/linux-4.2.6-races/*/*.i; do
    name="$(basename "$file" .ko.cil.i)"
    name="${name/?__linux-concurrency_safety__drivers---net---/}"
    echo $name
    echo $name
    echo $file
    echo "--enable ana.sv-comp.functions"
    echo
done