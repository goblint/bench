#!/bin/bash

# block
./goblint/ddverify.py case_studies/block/cciss/cciss.c case_studies/block/cciss/cciss_scsi.c
./goblint/ddverify.py case_studies/block/cpqarray/cpqarray.c -DCONFIG_PROC_FS
./goblint/ddverify.py case_studies/block/floppy/floppy.c
./goblint/ddverify.py case_studies/block/nbd/nbd.c
./goblint/ddverify.py case_studies/block/umem/umem.c

# cdrom
./goblint/ddverify.py case_studies/cdrom/aztcd/aztcd.c
./goblint/ddverify.py case_studies/cdrom/cdu31a/cdu31a.c
./goblint/ddverify.py case_studies/cdrom/cm206/cm206.c

# char
./goblint/ddverify.py case_studies/char/applicom/applicom.c
./goblint/ddverify.py case_studies/char/cs5535_gpio/cs5535_gpio.c
./goblint/ddverify.py case_studies/char/ds1286/ds1286.c
# no driver type
# ./goblint/ddverify.py case_studies/char/dtlk/dtlk.c
./goblint/ddverify.py case_studies/char/efirtc/efirtc.c
./goblint/ddverify.py case_studies/char/generic_nvram/generic_nvram.c
./goblint/ddverify.py case_studies/char/genrtc/genrtc.c
./goblint/ddverify.py case_studies/char/nwbutton/nwbutton.c
./goblint/ddverify.py case_studies/char/toshiba/toshiba.c

# char/watchdog
./goblint/ddverify.py case_studies/char/watchdog/i8xx_tco/i8xx_tco.c
./goblint/ddverify.py case_studies/char/watchdog/ib700wdt/ib700wdt.c
./goblint/ddverify.py case_studies/char/watchdog/machzwd/machzwd.c
./goblint/ddverify.py case_studies/char/watchdog/mixcomwd/mixcomwd.c
./goblint/ddverify.py case_studies/char/watchdog/pcwd/pcwd.c
./goblint/ddverify.py case_studies/char/watchdog/pcwd_pci/pcwd_pci.c
./goblint/ddverify.py case_studies/char/watchdog/sbc60xxwdt/sbc60xxwdt.c
./goblint/ddverify.py case_studies/char/watchdog/sc520_wdt/sc520_wdt.c
./goblint/ddverify.py case_studies/char/watchdog/sc1200wdt/sc1200wdt.c
./goblint/ddverify.py case_studies/char/watchdog/smsc37b787_wdt/smsc37b787_wdt.c
./goblint/ddverify.py case_studies/char/watchdog/w83877f_wdt/w83877f_wdt.c
./goblint/ddverify.py case_studies/char/watchdog/w83977f_wdt/w83977f_wdt.c
./goblint/ddverify.py case_studies/char/watchdog/wdt/wdt.c
./goblint/ddverify.py case_studies/char/watchdog/wdt_pci/wdt_pci.c
./goblint/ddverify.py case_studies/char/watchdog/wdt977/wdt977.c
