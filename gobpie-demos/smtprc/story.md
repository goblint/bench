# Build compilation database

1. `cd smtprc-2.0.3`
2. `bear -- make`
3. `cd ..` (for the following story)

# Interactive smtprc story

1. Start server: `rlwrap goblint --conf smtprc.json --enable server.enabled --enable server.reparse`
2. First analysis: `{"jsonrpc":"2.0","id":0,"method":"analyze","params":{}}`
3. In 11s shows 29; we focus on eliminating a real one in `scan_engine.c`.
4. Add missing `pthread_mutex_lock` after waking up from sleep: `patch -p0 < patch1.patch`
5. Second analysis: `{"jsonrpc":"2.0","id":0,"method":"analyze","params":{}}`
6. In 8s shows 29; (that only one racy access remains).
7. To showcase restarting, we hardcode `f.debug` and `f.verbose` to constant false: `patch -p0 < patch2.patch`
8. Third analysis: `{"jsonrpc":"2.0","id":0,"method":"analyze","params":{}}`
9. In 6s seconds, shows 28 races. Thus, race is limited to debug or verbose mode of the program. 
