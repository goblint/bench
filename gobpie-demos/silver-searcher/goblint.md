# Analysis of warning messages and justifications for configuration and annotations for the silver searcher

## Configuration

TODO: Explain/analyse the impact of activated analyses?

### `cil.merge.inlines = true`

Removes a lot of duplicate accesses, due to producing only one merged CFG for an inline function that is used several times
instead of one CFG with a separate duplicate path per each call of the function.

```
[Warning][Race] Memory location opts.color_match@src/options.h:95:20-95:24 (race with conf. 110):
  read with mhp:{tid=search_file_worker; created=All Threads} (conf. 80)  (exp: (char ** __restrict  )__lineptr) (/usr/include/x86_64-linux-gnu/bits/stdio.h:120:3-120:53)
  read with [mhp:{tid=main; created=All Threads}, thread:main] (conf. 80)  (exp: (char ** __restrict  )__lineptr) (/usr/include/x86_64-linux-gnu/bits/stdio.h:120:3-120:53)
  read with mhp:{tid=search_file_worker; created=All Threads} (conf. 80)  (exp: (char ** __restrict  )__lineptr) (/usr/include/x86_64-linux-gnu/bits/stdio.h:120:3-120:53)
  read with [mhp:{tid=main; created=All Threads}, thread:main] (conf. 80)  (exp: (char ** __restrict  )__lineptr) (/usr/include/x86_64-linux-gnu/bits/stdio.h:120:3-120:53)
  read with mhp:{tid=search_file_worker; created=All Threads} (conf. 80)  (exp: (char ** __restrict  )__lineptr) (/usr/include/x86_64-linux-gnu/bits/stdio.h:120:3-120:53)
  read with [mhp:{tid=main; created=All Threads}, thread:main] (conf. 80)  (exp: (char ** __restrict  )__lineptr) (/usr/include/x86_64-linux-gnu/bits/stdio.h:120:3-120:53)
  read with mhp:{tid=search_file_worker; created=All Threads} (conf. 80)  (exp: (char ** __restrict  )__lineptr) (/usr/include/x86_64-linux-gnu/bits/stdio.h:120:3-120:53)
  read with [mhp:{tid=main; created=All Threads}, thread:main] (conf. 80)  (exp: (char ** __restrict  )__lineptr) (/usr/include/x86_64-linux-gnu/bits/stdio.h:120:3-120:53)
  read with mhp:{tid=search_file_worker; created=All Threads} (conf. 80)  (exp: (char ** __restrict  )__lineptr) (/usr/include/x86_64-linux-gnu/bits/stdio.h:120:3-120:53)
  read with [mhp:{tid=main; created=All Threads}, thread:main] (conf. 80)  (exp: (char ** __restrict  )__lineptr) (/usr/include/x86_64-linux-gnu/bits/stdio.h:120:3-120:53)
  read with mhp:{tid=search_file_worker; created=All Threads} (conf. 80)  (exp: (char ** __restrict  )__lineptr) (/usr/include/x86_64-linux-gnu/bits/stdio.h:120:3-120:53)
  read with [mhp:{tid=main; created=All Threads}, thread:main] (conf. 80)  (exp: (char ** __restrict  )__lineptr) (/usr/include/x86_64-linux-gnu/bits/stdio.h:120:3-120:53)
  read with mhp:{tid=search_file_worker; created=All Threads} (conf. 80)  (exp: (char ** __restrict  )__lineptr) (/usr/include/x86_64-linux-gnu/bits/stdio.h:120:3-120:53)
  read with [mhp:{tid=main; created=All Threads}, thread:main] (conf. 80)  (exp: (char ** __restrict  )__lineptr) (/usr/include/x86_64-linux-gnu/bits/stdio.h:120:3-120:53)
  read with mhp:{tid=search_file_worker; created=All Threads} (conf. 80)  (exp: (char ** __restrict  )__lineptr) (/usr/include/x86_64-linux-gnu/bits/stdio.h:120:3-120:53)
  read with [mhp:{tid=main; created=All Threads}, thread:main] (conf. 80)  (exp: (char ** __restrict  )__lineptr) (/usr/include/x86_64-linux-gnu/bits/stdio.h:120:3-120:53)
  read with mhp:{tid=search_file_worker; created=All Threads} (conf. 80)  (exp: (char ** __restrict  )__lineptr) (/usr/include/x86_64-linux-gnu/bits/stdio.h:120:3-120:53)
  read with [mhp:{tid=main; created=All Threads}, thread:main] (conf. 80)  (exp: (char ** __restrict  )__lineptr) (/usr/include/x86_64-linux-gnu/bits/stdio.h:120:3-120:53)
  read with mhp:{tid=search_file_worker; created=All Threads} (conf. 80)  (exp: (char ** __restrict  )__lineptr) (/usr/include/x86_64-linux-gnu/bits/stdio.h:120:3-120:53)
  read with [mhp:{tid=main; created=All Threads}, thread:main] (conf. 80)  (exp: (char ** __restrict  )__lineptr) (/usr/include/x86_64-linux-gnu/bits/stdio.h:120:3-120:53)
```


## Annotating

----------------------

### Split paths using annotation `__goblint_split_begin(matches == NULL);` on line 39 in `search.c`. Requires activating `expsplit` analysis.

Will remove the following warnings:

```
[Warning][Race] Memory location (struct __anonstruct_match_t_73278319).start (race with conf. 100):
  write with mhp:{tid=search_file_worker; created=All Threads} (exp: & (matches + matches_len)->start) (src/search.c:103:13-103:57)
  write with [mhp:{tid=main; created=All Threads}, thread:main] (exp: & (matches + matches_len)->start) (src/search.c:103:13-103:57)
  write with mhp:{tid=search_file_worker; created=All Threads} (exp: & (matches + matches_len)->start) (src/search.c:129:17-129:62)
  write with [mhp:{tid=main; created=All Threads}, thread:main] (exp: & (matches + matches_len)->start) (src/search.c:129:17-129:62)
  write with mhp:{tid=search_file_worker; created=All Threads} (exp: & (matches + matches_len)->start) (src/search.c:161:21-161:80)
  write with [mhp:{tid=main; created=All Threads}, thread:main] (exp: & (matches + matches_len)->start) (src/search.c:161:21-161:80)
  write with mhp:{tid=search_file_worker; created=All Threads} (exp: & (matches + inverted_match_count)->start) (src/util.c:277:17-277:75)
  write with [mhp:{tid=main; created=All Threads}, thread:main] (exp: & (matches + inverted_match_count)->start) (src/util.c:277:17-277:75)
  write with mhp:{tid=search_file_worker; created=All Threads} (exp: & (matches + inverted_match_count)->start) (src/util.c:285:13-285:71)
  write with [mhp:{tid=main; created=All Threads}, thread:main] (exp: & (matches + inverted_match_count)->start) (src/util.c:285:13-285:71)
  read with [mhp:{tid=search_file_worker; created=All Threads}, lock:{print_mtx}] (exp: & (matches + cur_match)->start) (src/print.c:176:13-176:69)
  read with [mhp:{tid=main; created=All Threads}, lock:{print_mtx}, thread:main] (exp: & (matches + cur_match)->start) (src/print.c:176:13-176:69)
  read with [mhp:{tid=search_file_worker; created=All Threads}, lock:{print_mtx}] (exp: & (matches + print_context.last_printed_match)->start) (src/print.c:228:32-228:139)
  read with [mhp:{tid=main; created=All Threads}, lock:{print_mtx}, thread:main] (exp: & (matches + print_context.last_printed_match)->start) (src/print.c:228:32-228:139)
  read with [mhp:{tid=search_file_worker; created=All Threads}, lock:{print_mtx}] (exp: & (matches + print_context.last_printed_match)->start) (src/print.c:229:25-231:129)
  read with [mhp:{tid=main; created=All Threads}, lock:{print_mtx}, thread:main] (exp: & (matches + print_context.last_printed_match)->start) (src/print.c:229:25-231:129)
  read with [mhp:{tid=search_file_worker; created=All Threads}, lock:{print_mtx}] (exp: & (matches + print_context.last_printed_match)->start) (src/print.c:278:29-278:131)
  read with [mhp:{tid=main; created=All Threads}, lock:{print_mtx}, thread:main] (exp: & (matches + print_context.last_printed_match)->start) (src/print.c:278:29-278:131)
  read with mhp:{tid=search_file_worker; created=All Threads} (exp: & (matches + matches_len)->start) (src/search.c:104:13-104:83)
  read with [mhp:{tid=main; created=All Threads}, thread:main] (exp: & (matches + matches_len)->start) (src/search.c:104:13-104:83)
  read with mhp:{tid=search_file_worker; created=All Threads} (exp: & (matches + matches_len)->start) (src/search.c:106:13-106:108)
  read with [mhp:{tid=main; created=All Threads}, thread:main] (exp: & (matches + matches_len)->start) (src/search.c:106:13-106:108)
  read with mhp:{tid=search_file_worker; created=All Threads} (exp: & (matches + i)->start) (src/util.c:301:9-301:93)
  read with [mhp:{tid=main; created=All Threads}, thread:main] (exp: & (matches + i)->start) (src/util.c:301:9-301:93)
```
and
```
[Warning][Race] Memory location (struct __anonstruct_match_t_73278319).end (race with conf. 100):
  write with mhp:{tid=search_file_worker; created=All Threads} (exp: & (matches + matches_len)->end) (src/search.c:104:13-104:83)
  write with [mhp:{tid=main; created=All Threads}, thread:main] (exp: & (matches + matches_len)->end) (src/search.c:104:13-104:83)
  write with mhp:{tid=search_file_worker; created=All Threads} (exp: & (matches + matches_len)->end) (src/search.c:130:17-130:60)
  write with [mhp:{tid=main; created=All Threads}, thread:main] (exp: & (matches + matches_len)->end) (src/search.c:130:17-130:60)
  write with mhp:{tid=search_file_worker; created=All Threads} (exp: & (matches + matches_len)->end) (src/search.c:162:21-162:78)
  write with [mhp:{tid=main; created=All Threads}, thread:main] (exp: & (matches + matches_len)->end) (src/search.c:162:21-162:78)
  write with mhp:{tid=search_file_worker; created=All Threads} (exp: & (matches + inverted_match_count)->end) (src/util.c:278:17-278:70)
  write with [mhp:{tid=main; created=All Threads}, thread:main] (exp: & (matches + inverted_match_count)->end) (src/util.c:278:17-278:70)
  write with mhp:{tid=search_file_worker; created=All Threads} (exp: & (matches + inverted_match_count)->end) (src/util.c:286:13-286:50)
  write with [mhp:{tid=main; created=All Threads}, thread:main] (exp: & (matches + inverted_match_count)->end) (src/util.c:286:13-286:50)
  read with [mhp:{tid=search_file_worker; created=All Threads}, lock:{print_mtx}] (exp: & (matches + cur_match)->end) (src/print.c:207:13-207:67)
  read with [mhp:{tid=main; created=All Threads}, lock:{print_mtx}, thread:main] (exp: & (matches + cur_match)->end) (src/print.c:207:13-207:67)
  read with [mhp:{tid=search_file_worker; created=All Threads}, lock:{print_mtx}] (exp: & (matches + print_context.last_printed_match)->end) (src/print.c:229:25-231:129)
  read with [mhp:{tid=main; created=All Threads}, lock:{print_mtx}, thread:main] (exp: & (matches + print_context.last_printed_match)->end) (src/print.c:229:25-231:129)
  read with [mhp:{tid=search_file_worker; created=All Threads}, lock:{print_mtx}] (exp: & (matches + print_context.last_printed_match)->end) (src/print.c:254:29-254:129)
  read with [mhp:{tid=main; created=All Threads}, lock:{print_mtx}, thread:main] (exp: & (matches + print_context.last_printed_match)->end) (src/print.c:254:29-254:129)
  read with mhp:{tid=search_file_worker; created=All Threads} (exp: & (matches + matches_len)->end) (src/search.c:105:13-105:50)
  read with [mhp:{tid=main; created=All Threads}, thread:main] (exp: & (matches + matches_len)->end) (src/search.c:105:13-105:50)
  read with mhp:{tid=search_file_worker; created=All Threads} (exp: & (matches + i)->end) (src/util.c:301:9-301:93)
  read with [mhp:{tid=main; created=All Threads}, thread:main] (exp: & (matches + i)->end) (src/util.c:301:9-301:93)
```

### Explanation

Data races identified incorrectly (false positives).  
All these accesses involve variable `matches`.  
`matches` is allocated in if-branch on line 47 in `search.c`: `matches = ag_malloc(matches_size * sizeof(match_t));`
and in else-branch assigned value `NULL` on line 51 in `search.c`: `matches = NULL;`.  
In another if-branch starting from line 55 in `search.c` `matches` is allocated in case it is `NULL`: `matches = matches == NULL ? ag_malloc(matches_size * sizeof(match_t)) : matches;`
and in else-branch on line 101 `realloc_matches(&matches, &matches_size, matches_len + matches_spare);` is called.  
In `realloc_matches` if `(matches_len < *matches_size)` it just returns, leaving `matches` with value `NULL`, but `matches` is reallocated otherwise.  
From `search.c` lines:
* 34 (`matches_len = 0;`),
* 50 (`matches_size = 0;`), 
* 52 (`matches_spare = 0;`)  
we know that `matches_len < *matches_size` is always false in case `matches` is `NULL`.

----------------------

### Assume that all threads have been joined.  
Adding `"threadJoins"` to `ana.activated` in Goblint configuration and  
Goblint annotation `__goblint_assume_join(workers[i].thread);` after the for loop on line 210
(right before the `if (opts.stats) {`) will get rid of the following 4 warnings for `stats.*` and the read access of `opts.match_found`.

```
[Warning][Race] Memory location opts.match_found@src/options.h:95:20-95:24 (race with conf. 110):
  write with mhp:{tid=search_file_worker; created=All Threads} (src/search.c:210:9-210:29)
  write with [mhp:{tid=main; created=All Threads}, thread:main] (src/search.c:210:9-210:29)
  write with mhp:{tid=search_file_worker; created=All Threads} (src/search.c:424:9-424:29)
  write with [mhp:{tid=main; created=All Threads}, thread:main] (src/search.c:424:9-424:29)
  write with [mhp:{tid=main; created=All Threads}, thread:main] (src/search.c:641:21-641:41)
  read with [mhp:{tid=main; created=All Threads}, thread:main] (src/main.c:239:5-239:29)
```

### Explanation

Data race between read and the other writes identified incorrectly (false positive).  
The read from `!opts.match_found` happens on the last line of `main` function.  
Before that, on lines 204-208 there is a for-loop in which all the created threads (where the writes happen) are joined together.  
Goblint is unable to make sure that indeed *all* threads get joined together.  
Furthermore, the `workers_len` that is used for the for-loop might come from `opts.workers` which gets its value as an input from the user.  

```
[Warning][Race] Memory location stats.total_bytes@src/util.h:54:17-54:22 (race with conf. 110):
  write with [mhp:{tid=search_file_worker; created=All Threads}, lock:{stats_mtx}] (src/search.c:184:9-184:37)
  read with [mhp:{tid=main; created=All Threads}, thread:main] (src/main.c:216:9-217:111)
[Warning][Race] Memory location stats.total_files@src/util.h:54:17-54:22 (race with conf. 110):
  write with [mhp:{tid=search_file_worker; created=All Threads}, lock:{stats_mtx}] (src/search.c:185:9-185:28)
  read with [mhp:{tid=main; created=All Threads}, thread:main] (src/main.c:216:9-217:111)
[Warning][Race] Memory location stats.total_matches@src/util.h:54:17-54:22 (race with conf. 110):
  write with [mhp:{tid=search_file_worker; created=All Threads}, lock:{stats_mtx}] (src/search.c:186:9-186:43)
  read with [mhp:{tid=main; created=All Threads}, thread:main] (src/main.c:216:9-217:111)
[Warning][Race] Memory location stats.total_file_matches@src/util.h:54:17-54:22 (race with conf. 110):
  write with [mhp:{tid=search_file_worker; created=All Threads}, lock:{stats_mtx}] (src/search.c:188:13-188:39)
  read with [mhp:{tid=main; created=All Threads}, thread:main] (src/main.c:216:9-217:111)
```

### Explanation

Data races identified incorrectly (false positives).  
Same cause as for the previous one: all reads from the struct `stats` happen on line 217 in `main`.  
But before that, on lines 204-208 there is a for-loop in which all the created threads (where the writes happen) are joined together.  
Goblint is unable to make sure that indeed *all* threads get joined together.

----------------------


