d=${1-"single-thread"}
mkdir -p out/$d
ulimit -Ss 49152 # 48MB
opt="--enable keepcpp --enable dbg.verbose --enable dbg.debug --set ana.activated \"['base']\" --enable exp.earlyglobs --enable exp.full-context --enable ana.int.interval --enable ana.int.enums --disable ana.int.trier --enable printstats"
cmd="(date && echo \"Options: $opt\n\" && gtime -v ../analyzer/goblint $opt --sets solver slr3t --sets comparesolver slr3tp {1} 2>&1) | tee out/{2}.cmp.log"
# parallel --noswap --memfree 2G --load 100% --eta --joblog out/jobs.log --tmux --dryrun $cmd ::: single-thread/*.c
parallel --noswap --load 100% --eta --joblog out/jobs.log $cmd ::: $d/*.c
ag locals_ctx out/$d/*.cmp.log

cmd="(date && echo \"Options: $opt\n\" && gtime -v ../analyzer/goblint $opt --sets solver {1} {2} 2>&1) | tee out/{2}.{1}-solver.log"
parallel --noswap --load 100% --eta --joblog out/jobs.log $cmd ::: slr3t slr3tp ::: $d/*.c
ag vars out/$d/*-solver.log
