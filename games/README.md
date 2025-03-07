Games in C
----



linuxxdoom-1.10
---

<IMG SRC=./linuxxdoom.jpg WIDHT=3000px HEIGHT=300px />

The OG Doom 1.10 sources of the Linux Port; due to its age (and some nasty pointer to int conversions), it needs compiling for 32bit. Also due to age, it needs a C90 compiler with GNU extensions. Sourcecode had a typo that needed fixing. 80k raw lines of code.

```
./goblint -v --set ana.context.gas_value 10 --set sem.unknown_function.spawn false --set exp.architecture 32bit linuxxdoom-1.10.c
```
runs in the ballpark of 30 minutes. At least after manually patching an array when goblint encounters an instance of issue [https://github.com/goblint/analyzer/issues/1702](https://github.com/goblint/analyzer/issues/1702)


Crafty 25.2
---

<IMG SRC=./crafty.jpg WIDHT=3000px HEIGHT=300px />

a portable open source engine supporting the Chess Engine Communication Protocol written by Robert Hyatt in ANSI C starting in the early 90s. 

Crafty participated at several Computer Chess Tournaments, the WMCCC 1996, WMCCC 1997, WMCCC 2000, and WMCCC 2001, the WCCC 2004, WCCC 2005 and WCCC 2006. Crafty won the CCT1 in 2000, CCT5 in 2003 and CCT6 in 2004.

77k raw lines of ANSI C Code.

```
./goblint -v --set ana.context.gas_value 10 crafty-25.2.c
```