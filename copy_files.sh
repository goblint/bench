#!/bin/bash
while read p; do
	mkdir -p linux/$(dirname $p)
	cp $1/$p $_
done <files.txt
