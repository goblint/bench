#!/bin/bash
# https://gitlab.com/sosy-lab/research/data/liv/-/blob/44b411cd07670177cf5ffb522a3970390499cdbe/compact.sh
set -xe
VMNAME="unassume"

VMDKPATH=$(vboxmanage showvminfo $VMNAME  --machinereadable |grep SCSI-0-0 | cut -d "=" -f 2 | tr -d '"')
VDIPATH=$(dirname "$VMDKPATH")/$(basename "$VMDKPATH" .vmdk).vdi
echo "Mounting existing disk image and applying zerofree...."
mkdir -p mnt
qemu-nbd --socket $PWD/socket.sock "$VMDKPATH" --cache=unsafe --discard=unmap &
nbdfuse mnt/nbd1 --command nbdkit -s nbd socket=socket.sock --filter=partition partition=1 &
sleep 3
zerofree -v mnt/nbd1
fusermount -u ./mnt
rmdir mnt
echo "done"
echo "Cloning disk"
vboxmanage clonehd "$VMDKPATH" "$VDIPATH" --format vdi
echo "Compacting new vdi disk"
vboxmanage modifymedium "$VDIPATH" --compact
echo "Attaching new vdi disk instead of the vmdk disk"
vboxmanage storageattach $VMNAME --storagectl "SCSI" --device 0 --port 0 --type hdd --medium "$VDIPATH"
echo "Deleting old vmdk disk"
vboxmanage closemedium "$VMDKPATH" --delete
