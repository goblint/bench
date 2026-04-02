
| Program file | Goblint version | CIL version | Configuration file | Machine | Analysis time | Live/dead lines | Comment (changed what based on what) |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `rsync-v3.4.1-gcc.i` | `heads/master-0-ga13b7e196` | `2.0.9-72-g2243aad` | `unit` | Simmo's laptop | 4.452s | 23476/2494 | Example |
| `rsync-v3.4.1-gcc.i` | `remotes/origin/loop-unrolling-dead-branch-7-gb909b8720` | `0913d6a` | `unit` | Tartu goblint-new server | 2.853s | 23476/2494 | |
| `rsync-v3.4.1-gcc.i` | `remotes/origin/loop-unrolling-dead-branch-7-gb909b8720` | `0913d6a` | `large-program-string-unit` | Tartu goblint-new server | 2590.437s | 24005/1992 | With `perf -F 10` |
| `rsync-v3.4.1-gcc.i` | `remotes/origin/loop-unrolling-dead-branch-7-gb909b8720` | `0913d6a` | `large-program-string-unit` with `--disable ana.opt.hashcons` | Tartu goblint-new server | 2299.233s | 24005/1992 | Disabled hashconsing. With `perf -F 10` |
| `rsync-v3.4.1-gcc.i` e46af7a2 | `3bd3da151` |  | `large-program.json` | Jevgenij's laptop |  |  | Initial attempt at analysis, resulted in [#1955](https://github.com/goblint/analyzer/pull/1955) |
| `rsync-v3.4.1-gcc.i` e46af7a2 | `bd3da151` |  | above + `strings: unit` | Jevgenij's laptop |  |  | First terminating attempt at analysis, ~30 minutes |
| `rsync-v3.4.1-gcc.i` e46af7a2 | `2692a088e`  |  | above + extraspecials | Jevgenij's laptop |  |  | Stubbed `pool_alloc`, `pool_free`, resulted in [#1950](https://github.com/goblint/analyzer/issues/1950) and [#1951](https://github.com/goblint/analyzer/issues/1951) |
| `rsync-v3.4.1-gcc.i` de7208be | `2692a088e`  |  | above | Jevgenij's laptop |  |  | Removed duplicate structure definitions from the benchmark => less Goblint warnings |
| `rsync-v3.4.1-gcc.i` de7208be | `2692a088e`  |  | above + `callString: 2` | Jevgenij's laptop |  |  | Slower analysis, but less memory consumed |
| `rsync-v3.4.1-gcc.i` de7208be | `ed66a5365`  |  | large program, strings unit, more extraspecials | Jevgenij's laptop |  |  | More stubbing, reduction of analysis time |
| `rsync-v3.4.1-gcc.i` de7208be | `b4e433494`  |  | large program, strings unit, more extraspecials | Jevgenij's laptop |  |  | Revert of [#1659](https://github.com/goblint/analyzer/pull/1659), presumbly improving analysis time, but actual impact unclear |
| `rsync-v3.4.1-gcc.i` de7208be | `b4e433494`  |  | above, remove race analysis | Jevgenij's laptop |  |  | Attempt to clean up activated analyses |
| `rsync-v3.4.1-gcc-nosignal.i` | `b4e433494`  |  | above | Jevgenij's laptop |  |  | Removal of signal handling from benchmark, less warnings from Goblint |
| `rsync-v3.4.1-gcc-nosignal.i` | `b4e433494`  |  | above + extraspecials | Jevgenij's laptop |  |  | Reducing analysis time down to ~11 minutes |
| `rsync-v3.4.1-gcc-nosignal.i` | `b4e433494`  |  | above + single-threaded + threadflag | Jevgenij's laptop |  |  | Attempt to make global analysis path-sensitive |
| `rsync-v3.4.1-gcc-nosignal.i` | `b4e433494`  |  | above + earlyglobs off | Jevgenij's laptop |  |  | Did not terminate |
| `rsync-v3.4.1-gcc-nosignal.i` | `b4e433494`  |  | `jprotopopov.json` | Jevgenij's laptop |  |  | More stubbing, terminates in 31.5 hours |
| `rsync-v3.4.1-gcc-nosignal.i` | `e962088f9`  |  | `jprotopopov-call-string-0.json` | None |  |  | Presumably terminates faster, based on early globs on estimation |
| `rsync-v3.4.1-gcc-nosignal.i` | `e962088f9`  |  | `jprotopopov-call-string-1.json` | None |  |  | Presumably terminates faster, based on early globs on estimation |
| `rsync-v3.4.1-gcc-nosignal.i` | `b3c79e88f`  |  | `jprotopopov.json` | None |  |  | Stubbed zlib functions |
