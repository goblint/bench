#!/bin/sh
../analyzer/goblint --enable kernel --set mainfun[0] macvtap_init --set exitfun[+] macvtap_exit --set pre.kernel-root . macvtap_rc.c
