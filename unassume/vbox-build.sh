#!/bin/bash
# https://gitlab.com/sosy-lab/research/data/liv/-/blob/44b411cd07670177cf5ffb522a3970390499cdbe/Makefile
set -xe
VMNAME="unassume"

vagrant destroy -f
rm -f unassume.ova
vagrant up
vagrant halt
sleep 3
vboxmanage sharedfolder remove ${VMNAME} --name vagrant
./vbox-compact.sh
vboxmanage export ${VMNAME} -o unassume.ova
# vagrant destroy -f
