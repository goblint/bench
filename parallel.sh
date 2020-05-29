#!/bin/bash
files=${1-"single-thread/*.c"}
dir=$(dirname $files | head -n1)
cp ../analyzer/goblint .
case $OSTYPE in darwin*) time="gtime";; *) time="/usr/bin/time";; esac
mkdir -p out/$dir # might not work for files accross directories?
ulimit -Ss 49152 # 48MB
export OCAMLRUNPARAM=s=4M,i=32M,o=150,v=0x015

function finish {
  rm -rf goblint_temp_*
  ag exception out
}
trap finish EXIT

opt="--enable dbg.verbose --enable printstats --set ana.activated \"['base']\" --enable exp.earlyglobs --enable ana.int.interval --disable ana.int.enums --disable ana.int.def_exc --enable exp.full-context --disable exp.widen-context --disable noverify --disable exp.solver.td3.space_restore --disable exp.solver.td3.space --enable exp.solver.td3.term --enable exp.solver.td3.space_cache --enable dbg.trace.context"
# --enable exp.no-interval32-context # needed for wget b/c of mergesort
# --enable exp.no-int-context # needed for '400.perlbench_comb.c 482.sphinx_livepretend_comb.c duff-0.5_comb.c maradns-1.4.06_comb.c'. Only '445.gobmk_comb.c' does not terminate.
# --enable ana.hashcons # no(t much) difference in runtime or max res. size for wget. TODO try rest
# cmd="(date && $time -v ./goblint $opt --sets solver topdown --sets comparesolver topdown_term {1} 2>&1) > out/{1}.cmp.log"
# parallel --noswap --memfree 2G --load 100% --eta --joblog out/jobs.log --tmux --dryrun $cmd ::: single-thread/*.c
# parallel --noswap --load 100% --eta --joblog out/jobs.log $cmd ::: $files
# ag locals out/$dir/*.cmp.log | sort | tee out/$dir.locals

cmd="(date && $time -v ./goblint {2} $opt --sets solver td3 --{1} exp.solver.td3.space 2>&1) > out/{2}.{1}-space.log"
parallel --noswap --load 100% --eta --joblog out/jobs.log $cmd ::: enable disable ::: $files
ag "vars =" out/$dir/*-space.log | sort | tee out/$dir.vars

# ag "exp.no-int-context" out/$dir -l | sort | tee out/$dir.no-int-context
# ag "exp.no-interval32-context" out/$dir -l | sort | tee out/$dir.no-interval32-context
ag -i fixpoint out/$dir | tee out/$dir.fixpoint
ag 'Fatal error:' out/$dir | tee out/$dir.error
ag "terminated by signal" out/$dir | tee out/$dir.terminated
# ag "wall clock" out/coreutils | sed 's/:.*\t/\t/' | sed 's/Elapsed (wall clock) time (h:mm:ss or m:ss): //' | sort -n -k 2 | column -t
# ag "wall clock" out/single-thread/*.wpoint_simple* | sed 's/:.*\t/\t/' | sed 's/Elapsed (wall clock) time (h:mm:ss or m:ss): //' | sort -n -k 2 | xargs -n2 printf "%-75s\t%12s\n"
