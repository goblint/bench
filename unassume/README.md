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

### pfscan
```console
goblint --conf bench-yaml.json ../pthread/pfscan_comb.c -v
goblint --conf bench-yaml-validate.json ../pthread/pfscan_comb.c --set witness.yaml.unassume ../pthread/pfscan_comb.witness.manual.yml -v --enable witness.invariant.other
```

Goblint: d480bbcf3e17488e9ea0504730183c49701aef59
* evals: 4194 → 2919 = 30.4%
* solving cputime: 0.823s → 0.681s = 17.3%
