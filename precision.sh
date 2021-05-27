#!/bin/bash
# compare the precision of [variants] in [dir]
dir=${1-"out"}
variants=${2-'.'} # e.g. enable|disable
runs=$(find $dir -type d -name '*.c*' | egrep $variants | sort)
programs=$(echo "$runs" | sed 's/\.c.*/\.c/' | sort -u)
for program in $programs; do
  program_runs=$(echo "$runs" | grep $program)
  n=$(echo "$program_runs" | wc -l)
  if [ $n -ne 2 ]; then
    echo "Skipping since it has $n variant(s) instead of 2: $program";
    continue;
  fi
  src=$(echo $program | sed "s/^$dir\///")
  if [ ! -f $src ]; then
    echo "Source $src for $program does not exist!";
    continue;
  fi
  conf="$(echo "$program_runs" | head -n1)/config.json"
  dst=$program.precision
  rm -f $dst
  $dir/goblint --conf $conf --compare_runs $program_runs $src 2>/dev/null | tee $dst
done
ag 'Comparing precision of' -A1 $dir
