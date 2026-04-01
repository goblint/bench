Welcome to the repository recording AnalyzeThat 2026.

# 2026: rsync v3.4.1

As co-organizers of AnalyzeThat (with @Vesal Vojdani and Helmut Seidl), we chose that the software to analyze for AnalyzeThat'26 is **[rsync v3.4.1](https://github.com/RsyncProject/rsync/releases/tag/v3.4.1)**.
* The preprocessed file `./rsync-v3.4.1.i` must be used. This preprocessing will help everyone:
  * tools don't have to delve into build system issues, and
  * we all have the same, single file as input.
* The goal now is to analyze rsync with your tools, and prove some components of it safe or not. Each team is free to choose the components they inspect, and their modeling of interactions. Please keep notes of your assumptions/targets for the workshop presentation!
* Please be aware that rsync has a specific [security policy](https://github.com/RsyncProject/rsync/blob/master/SECURITY.md#reporting-a-vulnerability). Also, if you need to report issues to developpers, please make sure those are real issues to avoid wasting their time.
* You're warmly invited to attend the workshop on 12 April at ETAPS. Please note the early registration closes on **10 March**. If *your tool is not registered on the [web page](https://analyzethat.gitlab.io/), please contact the organizers!*. Looking forward to seeing you there, and in the meantime, happy analyses!

## Reproducing the preprocessing

For the sake of reproducibility, here is a documentation of the steps done during the preprocessing. These steps have been performed on an Ubuntu 25.10 (glibc 2.42), and using [Mopsa](https://mopsa.gitlab.io/mopsa-analyzer/user-manual/quick-start/installation.html) version 1.2 (Mopsa needs a fix in `share/mopsa/stubs/c/libc/bsd/string.c`, line 28 should be `#include "../mopsa_libc_utils.h`. This will be upstreamed soon; we relied on LLVM v18.1.8 for the parsing).

```
git checkout https://github.com/RsyncProject/rsync.git && cd rsync && git checkout v3.4.1
CC=clang ./configure --disable-md2man --disable-xxhash --disable-zstd --disable-lz4 --disable-iconv --disable-iconv-open --disable-openssl --disable-acl-support --disable-xattr-support
```

Manual edits:
- In `config.h`, comment `#define USE_MD5_ASM 1` and `#define USE_ROLL_SIMD 1`.
- In `zlib/zlib.h` and `zlib/zutil.c`, comment the `#if` defining `struct internal_state      {int dummy;}; /* for buggy compilers */` at lines 1739 and 10.

```
mopsa-build make rsync
mopsa-c mopsa.db -make-target=rsync -c-preprocess-and-exit=rsync-v3.4.1.i
```

Then, 10 manual edits are required: `clang` complains about multiple type mismatch between unions and their members, e.g.:
```
rsync-v3.4.1.i:16122:29: error: passing '__SOCKADDR_ARG' (aka 'union __SOCKADDR_ARG') to parameter of incompatible type 'struct sockaddr *'
 16122 |         if (getpeername(fd, __SAST_tmp_110, ss_len)) {
       |                             ^~~~~~~~~~~~~~
rsync-v3.4.1.i:8483:44: note: passing argument to parameter '__addr' here
 8483 | int getpeername(int __fd, struct sockaddr *__addr, socklen_t *__len);
      |                                            ^
```
The kind of replacement to perform consists in replacing removing the temporary variable `__SOCKADDR_ARG __SAST_tmp_110 = { (struct sockaddr*)ss };`, and replacing its uses by the member value: `getpeername(fd, __SAST_tmp_110, ss_len)` ~> `getpeername(fd, (struct sockaddr*)ss, ss_len)`.

Now this is all done, `clang -c rsync-v3.4.1.i` should compile without errors, and the resulting file should be the same as the one provided in this repository.

### Standard library headers

The following headers from the standard library have been detected to be used in rsync:

- assert.h
- ctype.h
- dirent.h
- errno.h
- fcntl.h
- grp.h
- inttypes.h
- langinfo.h
- locale.h
- math.h
- netdb.h
- pwd.h
- signal.h
- stdio.h
- stdlib.h
- string.h
- strings.h
- time.h
- unistd.h
- utime.h
- wchar.h

### Preprocessing acknowledgments

We thank Simmo Saan for finding and documenting the [build twseaks](https://github.com/goblint/bench/issues/73) and Antoine Miné for helping solve some frontend issues of Mopsa.

# Software to be considered for analysis (20/02/2026)

Please submit software to be considered for analysis by 20 February 2026, by opening a merge request filling the `software_proposal_template.md` (and renamed as the considered software).

All informations are on the [webpage](https://analyzethat.gitlab.io/).
