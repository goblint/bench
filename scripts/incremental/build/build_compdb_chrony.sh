#!/usr/bin/env bash
git clean -fdx
./configure
make -j 1 chronyd | tee build.log
compiledb --parse build.log
# ./configure && bear -- make chronyd
sed -i -E 's/#define NTP_ERA_SPLIT \([0-9]+LL/#define NTP_ERA_SPLIT \(1671796396LL/' config.h
