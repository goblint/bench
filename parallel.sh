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

opt="--enable keepcpp --enable dbg.verbose --enable dbg.debug --set ana.activated \"['base']\" --enable exp.earlyglobs --enable exp.full-context --enable ana.int.interval --enable ana.int.enums --disable ana.int.trier --enable printstats"
# --enable exp.no-interval32-context # needed for wget b/c of mergesort
# --enable exp.no-int-context # needed for '400.perlbench_comb.c 482.sphinx_livepretend_comb.c duff-0.5_comb.c maradns-1.4.06_comb.c'. Only '445.gobmk_comb.c' does not terminate.
# --enable ana.hashcons # no(t much) difference in runtime or max res. size for wget. TODO try rest
cmd="(date && $time -v ./goblint $opt --sets solver slr3t --sets comparesolver slr3tp {1} 2>&1) | tee out/{1}.cmp.log"
# parallel --noswap --memfree 2G --load 100% --eta --joblog out/jobs.log --tmux --dryrun $cmd ::: single-thread/*.c
parallel --noswap --load 100% --eta --joblog out/jobs.log $cmd ::: $files
ag locals out/$dir/*.cmp.log | sort | tee out/$dir.locals

cmd="(date && $time -v ./goblint $opt --sets solver {1} {2} 2>&1) | tee out/{2}.{1}-solver.log"
parallel --noswap --load 100% --eta --joblog out/jobs.log $cmd ::: slr3t slr3tp ::: $files
ag "vars =" out/$dir/*-solver.log | sort | tee out/$dir.vars

ag "exp.no-int-context" out/$dir -l | sort | tee out/$dir.no-int-context
ag "exp.no-interval32-context" out/$dir -l | sort | tee out/$dir.no-interval32-context
ag -i fixpoint out/$dir | tee out/$dir.fixpoint
ag exception out/$dir | tee out/$dir.exception
ag "terminated by signal" out/$dir | tee out/$dir.terminated
