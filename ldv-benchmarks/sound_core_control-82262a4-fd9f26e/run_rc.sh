#!/bin/sh
../analyzer/goblint --enable kernel --set mainfun[0] snd_ctl_dev_register --set pre.kernel-root . control_rc.c 
