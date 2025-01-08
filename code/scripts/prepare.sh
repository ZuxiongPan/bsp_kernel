#!/bin/bash

echo "----- make prepare -----"

if [ ! -d $ROOT_DIR ]; then
	mkdir -p $ROOT_DIR
fi

mkdir -p $ROOT_DIR/etc $ROOT_DIR/proc $ROOT_DIR/sys $ROOT_DIR/dev 
mkdir -p $ROOT_DIR/var $ROOT_DIR/kmodule $ROOT_DIR/lib $ROOT_DIR/mnt

cp $SCRIPTS_DIR/etc/* $ROOT_DIR/etc/ -rf

echo "----- prepare OK -----"