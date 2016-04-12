d=${1-"single-thread"}
mkdir -p out/$d
ulimit -Ss 49152 # 48MB
opt="--enable dbg.verbose --enable dbg.debug --set ana.activated \"['base']\" --enable exp.earlyglobs --enable exp.full-context --enable ana.int.interval --enable ana.int.enums --disable ana.int.trier --sets comparesolver slr3tb --sets solver {1}"
cmd="(date && echo \"Options: $opt\n\" && gtime -v ./goblint $opt --enable keepcpp {2} 2>&1) | tee out/{2}.{1}.log"
# parallel --noswap --memfree 2G --load 100% --eta --joblog out/jobs.log --tmux --dryrun $cmd ::: single-thread/*.c
parallel --noswap --load 100% --eta --joblog out/jobs.log $cmd ::: slr3t slr3tp ::: $d/*.c
