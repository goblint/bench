#!/bin/bash

# goblint --conf goblint.json --set result json-messages files.c -o out.json
# gron out.json | sed -n "s/^json.files.*= \"\(.\/\)\+\(.*\)\".*;$/\2/p" | sort | uniq > files.txt

while read p; do
	mkdir -p headers/$(dirname $p)
	cp $1/$p $_
done <files.txt
