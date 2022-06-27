#!/bin/sh

echo "Group: Toy programs"
echo ""

for file in ./*.c
do
    base=$(basename $file)
    echo "$base"
    echo "$base"
    echo "traces-rel-toy/$base"
    echo "-"
    echo ""
done
