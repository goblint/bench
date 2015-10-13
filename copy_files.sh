#!/bin/bash
while read p; do
  cp $1/$p linux/$p
done <files.txt
