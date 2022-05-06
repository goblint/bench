# Build compilation database

1. cd chrony-4.2
2. ./configure
3. bear -- make
4. cd .. (for the following)

# Interactive chrony story

1. Start server: `rlwrap goblint -v --conf chrony-4.2.json --enable server.enabled --enable server.reparse`
2. First analysis: `{"jsonrpc":"2.0","id":0,"method":"analyze","params":{}}`
3. In 282s shows 2 races after `pthread_join`. Goblint cannot infer the one-to-one correspondance between threads and dynamically allocated structs
4. Add `__goblint_assume_join` annotation: `patch -p0 < patch1.patch`
5. Second analysis: `{"jsonrpc":"2.0","id":0,"method":"analyze","params":{}}`
6. In 26s shows 0 races. Program verified correct!
7. Try removing global `privops_lock`: `patch -p0 < patch2.patch`
8. Third analysis: `{"jsonrpc":"2.0","id":0,"method":"analyze","params":{}}`
9. In 14s shows 9 races in dynamically allocated struct fields. Goblint cannot infer the one-to-one correspondance between threads and dynamically allocated structs
10. Add symbolic `*.mutex`: `patch -p0 < patch3.patch`
11. Fourth analysis: `{"jsonrpc":"2.0","id":0,"method":"analyze","params":{}}`
12. In 16s shows 0 races. Program verified correct!
