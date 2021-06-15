#!/bin/bash

# Usage: ./sosy-ldv-index.sh >> index/traces-cpalockator.txt

for subdir in Safes Unknowns Unsafes; do
    echo "Group: CPALockator linux-4.2.6-races ($subdir)"
    echo
    for file in sosy-ldv/linux-4.2.6-races/$subdir/*.i; do
        name="$(basename "$file" .ko.cil.i)"
        name="${name/?__linux-concurrency_safety__drivers---net---/}"

        if ! grep -q "^$name$" ./sosy-ldv-failed.txt; then
            echo $name
            echo $name
            echo $file
            echo "--enable ana.sv-comp.functions"
            echo
        fi
    done
done
