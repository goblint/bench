#!/bin/sh

echo "Group: Toy programs"
echo ""

for file in ./*.c
do
    base=$(basename $file)
    nice=$(echo $base | sed -r 's/[0-9]+-(.*)\.c/\1/')
    echo "$nice"
    echo "$base"
    echo "traces-rel-toy/$base"
    echo "-"
    echo ""
done
