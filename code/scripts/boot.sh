#!/bin/bash

if [ -z "$1" ]; then
	echo "usage: $0 {1|2|3}"
	echo "option 1 means normal start"
	echo "option 2 means start with usb"
	echo "option 3 means start with bootcmd"
fi

case $1 in
	1)
		qemu-system-arm -M bpim2u -m 512M -nographic -kernel ./zImage -dtb ./sun8i-r40-bananapi-m2-ultra.dtb \
			-drive if=sd,file=./sdcard,format=raw
		;;
	2)
		qemu-system-arm -M bpim2u -m 512M -nographic -kernel ./zImage -dtb ./sun8i-r40-bananapi-m2-ultra.dtb \
			-drive if=sd,file=./sdcard,format=raw -drive if=none,id=stick,format=raw,file=./usb.img -device usb-storage,drive=stick
		;;
	3)
		qemu-system-arm -M bpim2u -m 512M -nographic -kernel ./zImage -dtb ./sun8i-r40-bananapi-m2-ultra.dtb \
			-drive if=sd,file=./sdcard,format=raw -append 'root=/dev/mmcblk0 rw console=ttyS0,115200n8 init=/linuxrc'
		;;
	*)
		echo "invalid option: $1"
		exit 1
		;;
esac
