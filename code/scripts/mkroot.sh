#!/bin/bash

echo "----- make rootfs -----"

cp $COMPILER_DIR/arm-linux-gnueabihf/libc/lib/ld-linux-armhf.so.3 $ROOT_DIR/lib/ -f
cp $COMPILER_DIR/arm-linux-gnueabihf/libc/lib/libc.so.6 $ROOT_DIR/lib/ -f
find $KERNEL_DIR/drivers -name "*.ko" -exec cp -f {} $ROOT_DIR/modules/ \;
find $CUSKERNEL_DIR/drivers -name "*.ko" -exec cp -f {} $ROOT_DIR/modules/ \;

# filesystem blocksize 4096Bytes, block numbers 0x2000
mkfs.ext4 -F -b 4096 -d $ROOT_DIR $TARGET_DIR/sdcard 0x2000

echo "----- rootfs create ok -----"