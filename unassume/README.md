## Precision evaluation

TODO move from thread-witnesses.

## Performance evaluation

### aget
```console
goblint --conf bench-yaml.json ../pthread/aget_comb.c -v
goblint --conf bench-yaml-validate.json ../pthread/aget_comb.c --set witness.yaml.unassume ../pthread/aget_comb.witness.manual.yml -v --enable witness.invariant.other
```

Goblint: d480bbcf3e17488e9ea0504730183c49701aef59
* evals: 7138 → 4683 = 34.4%
* solving cputime: 2.237s → 1.604s = 28.3%

Goblint: f5a1641ef64a4b6d5242098c3dbcc0340f63e557
* evals: 7932 → 4683 = 41.0%
* solving cputime: 2.590 → 1.689s = 34.8%

Evals bisect:
* master: 8022
* regression e94b0cce9a15ebbd5a20f063dcf08ba8a17289da
* 7c365ba98: 5735
* orig: 7138



### pfscan
```console
goblint --conf bench-yaml.json ../pthread/pfscan_comb.c -v
goblint --conf bench-yaml-validate.json ../pthread/pfscan_comb.c --set witness.yaml.unassume ../pthread/pfscan_comb.witness.manual.yml -v --enable witness.invariant.other
```

Goblint: d480bbcf3e17488e9ea0504730183c49701aef59
* evals: 4194 → 2919 = 30.4%
* solving cputime: 0.823s → 0.681s = 17.3%

Goblint: f5a1641ef64a4b6d5242098c3dbcc0340f63e557
* evals: 4194 → 2919 = 30.4%
* solving cputime: 1.024s → 0.651s = 36.4%



### smtprc
```console
goblint --conf bench-yaml.json ./eval-perf/pthread/smtprc_comb.c -v
goblint --conf bench-yaml-validate.json ./eval-perf/pthread/smtprc_comb.c --set witness.yaml.unassume ./eval-perf/manual/smtprc_comb.yml -v --enable witness.invariant.other
```

Goblint: 22f6061df7d2c7bd3584c000389b9f0a7abf010e
* evals: 48559 → 24091 = 50.4%
* solving cputime: 18.566s → 9.720s = 47.6%


### knot
* evals: 29588 → 21461 = 27.5%
