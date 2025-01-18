# Global Variables
SCRIPTS_DIR := $(shell pwd)
CODE_DIR := $(SCRIPTS_DIR)/..
TOP_DIR := $(SCRIPTS_DIR)/../..
CUSKERNEL_DIR := $(CODE_DIR)/pzxkernel
CUSUSER_DIR := $(CODE_DIR)/pzxuser
TOOLS_DIR := $(TOP_DIR)/tools
COMPILER_DIR := $(TOOLS_DIR)/arm-linux-gnueabihf-14.0.0
TARGET_DIR := $(TOP_DIR)/target
ARCHITECTURE := arm

BUSYBOX_DIR := $(TOOLS_DIR)/busybox-1.36.0
KERNEL_DIR := $(TOP_DIR)/linux-6.6
ROOT_DIR := $(TARGET_DIR)/root
CROSS_COMPILER_PREFIX := $(COMPILER_DIR)/bin/arm-linux-gnueabihf-
BSPINC_DIR := $(CODE_DIR)/include
jN := j8

# dd if=/dev/zero of=./test bs=4K count=128
# sudo mkfs.ext2 ./test
# sudo mount -t ext2 ./test /mnt/ -o loop
# sudo cp -rf ./study/* /mnt/
# sudo umount /mnt

# qemu-system-arm -M bpim2u -m 512M -nographic -kernel ./zImage -dtb ./sun8i-r40-bananapi-m2-ultra.dtb -drive if=sd,file=./sdcard,format=raw
# qemu-system-arm -M bpim2u -m 512M -nographic -kernel ./zImage -append 'root=/dev/mmcblk0 rw console=ttyS0,115200n8 init=/linuxrc' -dtb ./sun8i-r40-bananapi-m2-ultra.dtb -drive if=sd,file=./sdcard,format=raw

export CUSKERNEL_DIR COMPILER_DIR ROOT_DIR SCRIPTS_DIR TARGET_DIR
export KERNEL_DIR BSPINC_DIR ARCHITECTURE CROSS_COMPILER_PREFIX

.PHONY: prepare all clean busybox busybox_clean kernel kernel_clean \
	target drivers drivers_clean applications applications_clean cuskernel_clean

all: prepare busybox kernel drivers applications target
busybox: prepare

prepare:
	./prepare.sh

kernel:
	make ARCH=$(ARCHITECTURE) CROSS_COMPILE=$(CROSS_COMPILER_PREFIX) -C $(KERNEL_DIR) sunxi_defconfig
	make ARCH=$(ARCHITECTURE) CROSS_COMPILE=$(CROSS_COMPILER_PREFIX) -C $(KERNEL_DIR) zImage -$(jN)
	make ARCH=$(ARCHITECTURE) CROSS_COMPILE=$(CROSS_COMPILER_PREFIX) -C $(KERNEL_DIR) modules -$(jN)
	make ARCH=$(ARCHITECTURE) CROSS_COMPILE=$(CROSS_COMPILER_PREFIX) -C $(KERNEL_DIR) dtbs -$(jN)
	
kernel_clean:
	make ARCH=$(ARCHITECTURE) CROSS_COMPILE=$(CROSS_COMPILER_PREFIX) -C $(KERNEL_DIR) distclean
	make cuskernel_clean

busybox:
	make ARCH=$(ARCHITECTURE) CROSS_COMPILE=$(CROSS_COMPILER_PREFIX) -C $(BUSYBOX_DIR) defconfig
	sed -i 's/# CONFIG_STATIC is not set/CONFIG_STATIC=y/' $(BUSYBOX_DIR)/.config
	make ARCH=$(ARCHITECTURE) CROSS_COMPILE=$(CROSS_COMPILER_PREFIX) -C $(BUSYBOX_DIR) -$(jN)
	make ARCH=$(ARCHITECTURE) CROSS_COMPILE=$(CROSS_COMPILER_PREFIX) CONFIG_PREFIX=$(ROOT_DIR) \
		-C $(BUSYBOX_DIR) install

busybox_clean:
	make ARCH=$(ARCHITECTURE) CROSS_COMPILE=$(CROSS_COMPILER_PREFIX) -C $(BUSYBOX_DIR) distclean
	
drivers:
	make -C $(CUSKERNEL_DIR)/drivers all
	
drivers_clean:
	make -C $(CUSKERNEL_DIR)/drivers clean

cuskernel_clean:
	make -C $(CUSKERNEL_DIR)/kernel clean

applications:
	make -C $(CUSUSER_DIR)/applications all
	make -C $(CUSUSER_DIR)/applications install
	
applications_clean:
	make -C $(CUSUSER_DIR)/applications clean
	
target:
	./mkroot.sh
	cp $(KERNEL_DIR)/arch/arm/boot/zImage $(TARGET_DIR) -f
	cp $(KERNEL_DIR)/arch/arm/boot/dts/allwinner/sun8i-r40-bananapi-m2-ultra.dtb $(TARGET_DIR) -f
	
clean:
	rm -rf $(TARGET_DIR)/*
	make busybox_clean
	make kernel_clean
	make drivers_clean
	make applications_clean
	rm -f $(KERNEL_DIR)/cuskernel
