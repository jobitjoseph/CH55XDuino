#!/bin/bash

#prepared for mac

COREVERSION=0.0.9
SDCCVERSION=11630
TOOLSVERSION=2020.12.01
COREFILE=ch55xduino-core-$COREVERSION.tar.bz2

tar -jcv --exclude="*DS_Store" -f packedFiles/$COREFILE -C ../ ch55x

./gen_platform_entry.sh packedFiles/$COREFILE $COREVERSION $SDCCVERSION $TOOLSVERSION > packedFiles/platform_$COREVERSION.txt
