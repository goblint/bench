#!/bin/bash
# Make sure packages are installed (https://wiki.ubuntu.com/Kernel/BuildYourOwnKernel)
# Prepare Kernel: make defconfig && make prepare
# Then run this script with absolute path to kernel root dir.
rm -rf linux-headers linux-headers-orig
mkdir linux-headers
cd linux-headers
cp -Lr $1/include .
mkdir -p arch/x86
cp -Lr $1/arch/x86/include arch/x86/
cp $1/.config ./config.txt
cd ..
cp -Lr linux-headers linux-headers-orig
#Create Patch: diff -ru linux-headers-orig linux-headers > headers.patch
#Apply patch: patch -p1 -d linux-headers <headers.patch
