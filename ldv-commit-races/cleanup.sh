#!/bin/sh
#requires file system to set atime

echo ./run_rc.sh > /dev/null
echo ./run_nr.sh > /dev/null

find arch/ -amin +3 -type f -print -exec rm {} \;
find arch/ -type d -empty -print -delete
find include/ -amin +3 -type f -print -exec rm {} \;
find include/ -type d -empty -print -delete
find drivers/ -amin +3 -type f -print -exec rm {} \;
find drivers/ -type d -empty -print -delete

