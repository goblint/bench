#!/bin/bash
files=${1-"coreutils/*.c single-thread/*.c single-thread-nonterm/*.c"}
mkdir -p $(dirname $files | uniq | sed 's$^$out/$') # create subdirs of $files in out/
cp ../analyzer/goblint .
cp $0 out
cp ./goblint out

case $OSTYPE in darwin*) time="gtime";; *) time="/usr/bin/time";; esac

ulimit -Ss 49152 # increase stack size limit to 48MB; ulimit -s says default is 8192
# export OCAMLRUNPARAM=s=4M,i=32M,o=150,v=0x015

function finish {
  rm -rf goblint_temp_*
  ag 'Fixpoint' out
  ag 'Fatal error:' out
  ag 'terminated by signal' out
  ag 'Command exited' out
  ag 'About to crash' out
}
trap finish EXIT

# defaults: --enable verify --enable solvers.td3.space_cache --disable dbg.trace.context --set solver td3
# --set ana.activated \"['base','mallocWrapper']\"; defaults: "['expRelation','base','threadid','threadflag','escape','mutex', 'mallocWrapper']"
opts="--enable exp.earlyglobs --enable ana.int.interval --disable ana.int.enums --disable ana.int.def_exc --disable ana.context.widen --set ana.base.privatization none\
  --disable solvers.td3.space_restore"
# --disable ana.base.context.interval # needed for wget b/c of mergesort
# --disable ana.base.context.int # needed for '400.perlbench_comb.c 482.sphinx_livepretend_comb.c duff-0.5_comb.c maradns-1.4.06_comb.c'. Only '445.gobmk_comb.c' does not terminate.
# --enable ana.opt.hashcons # no(t much) difference in runtime or max res. size for wget. TODO try rest
# cmd="(date && $time -v ./goblint $opt --set solver topdown --set comparesolver topdown_term {1} 2>&1) > out/{1}.cmp.log"
# parallel --noswap --memfree 2G --load 100% --eta --joblog out/jobs.log --tmux --dryrun $cmd ::: single-thread/*.c
# parallel --noswap --load 100% --eta --joblog out/jobs.log $cmd ::: $files
# ag locals out/$dir/*.cmp.log | sort | tee out/$dir.locals

opt=term
# opt=space
# opt=side_widen # values=cycle(default), always, cycle_self
# pay attention that $opts may overwrite! we place only place $opt first such that the variant is easy to see in htop.
cmd="($time -v ./goblint -v {1} --{2} solvers.td3.$opt $opts --set dbg.timeout 6h --set save_run out/{1}.{2}-$opt 2>&1) > out/{1}.{2}-$opt.log"
parallel --noswap --memfree 2G --eta --joblog out/jobs.log $cmd ::: $files ::: disable enable
# --load 100% (default) Will only start new job if fewer cores are used.
# --memfree If the jobs take up very different amount of RAM, GNU parallel will only start as many as there is memory for. If less than size bytes are free, no more jobs will be started. If less than 50% size bytes are free, the youngest job will be killed, and put back on the queue to be run later.

# ag "vars =" out/$dir/*-space.log | sort | tee out/$dir.vars
# ag -i fixpoint out/$dir | tee out/$dir.fixpoint
# ag 'Fatal error:' out/$dir | tee out/$dir.error
# ag "terminated by signal" out/$dir | tee out/$dir.terminated
# ag "wall clock" out/coreutils | sed 's/:.*\t/\t/' | sed 's/Elapsed (wall clock) time (h:mm:ss or m:ss): //' | sort -n -k 2 | column -t
# ag "wall clock" out/single-thread/*.wpoint_simple* | sed 's/:.*\t/\t/' | sed 's/Elapsed (wall clock) time (h:mm:ss or m:ss): //' | sort -n -k 2 | xargs -n2 printf "%-75s\t%12s\n"
