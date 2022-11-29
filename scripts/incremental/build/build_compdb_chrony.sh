#!/usr/bin/env bash
git clean -fdx
./configure
make -j 1 chronyd | tee build.log
compiledb --parse build.log
# ./configure && bear -- make chronyd
