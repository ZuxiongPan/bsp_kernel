#!/bin/bash

echo "----- make prepare -----"

CUSKERNEL_LINK="$KERNEL_DIR/cuskernel"
CUSKERNEL_TARGET="$CUSKERNEL_DIR/kernel"

if [ ! -d $ROOT_DIR ]; then
	mkdir -p $ROOT_DIR
fi

if [ ! -L "$CUSKERNEL_LINK" ]; then
    ln -s "$CUSKERNEL_TARGET" "$CUSKERNEL_LINK"
fi

mkdir -p $ROOT_DIR/etc $ROOT_DIR/proc $ROOT_DIR/sys $ROOT_DIR/dev 
mkdir -p $ROOT_DIR/var $ROOT_DIR/modules $ROOT_DIR/lib $ROOT_DIR/mnt

cp $SCRIPTS_DIR/etc/* $ROOT_DIR/etc/ -rf
cp $SCRIPTS_DIR/boot.sh $TARGET_DIR/ -f

echo "----- prepare OK -----"