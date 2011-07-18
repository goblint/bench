#!/bin/bash
# Prepare Kernel: make defconfig && make prepare
# Then run this script.
rm -rf linux-headers
mkdir linux-headers
cd linux-headers
cp -Lr $1/include .
mkdir -p arch/x86
cp -Lr $1/arch/x86/include arch/x86/
cp $1/.config ./config.txt
#Create Patch: diff -ru linux-headers-orig linux-headers > headers.patch
#Apply patch: patch -p1 -d linux-headers <headers.patch
