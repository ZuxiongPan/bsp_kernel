#!/bin/bash

echo "----- make rootfs -----"

cp $COMPILER_DIR/arm-linux-gnueabihf/libc/lib/ld-linux-armhf.so.3 $ROOT_DIR/lib/ -f
cp $COMPILER_DIR/arm-linux-gnueabihf/libc/lib/libc.so.6 $ROOT_DIR/lib/ -f
find $KERNEL_DIR/drivers -name "*.ko" -exec cp -f {} $ROOT_DIR/kmodule/ \;

dd if=/dev/zero of=$TARGET_DIR/sdcard bs=1M count=32
sudo mkfs.ext4 $TARGET_DIR/sdcard
sudo mount -t ext4 $TARGET_DIR/sdcard /mnt/ -o loop
sudo cp -rf $ROOT_DIR/* /mnt/
sudo umount /mnt/

echo "----- rootfs create ok -----"