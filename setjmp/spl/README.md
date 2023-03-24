# Stanford Portable Library (SPL) clobbering example

This is a slice of the `exception.{h,c}` from the CS50's fork of Eric Roberts' Stanford Portable Library.
* Original repository: https://github.com/cs50/spl
* Issue: https://github.com/cs50/spl/issues/24

I made changes to the original library to make it somewhat less prone to clobbering,
so that the warnings should only be about the client program.
The original version of `exception.h` is preserved in `exception.bak`.

This is the behavior on my machine:
1. running `gcc *.c && ./a.out` outputs "value of x is 6"
2. runnign `gcc -O2 -Wclobbered *.c && ./a.out` outputs "value of x is 10"; does not warn about clobbering.
3. running goblint `goblint --conf goblint.conf` should warn about clobbering.

When commenting out the assignment on line 27, goblint is satisfied.
