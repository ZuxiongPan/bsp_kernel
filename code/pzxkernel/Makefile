PWD := $(shell pwd)

obj-y += export_funcs.o
obj-y += pzx_netlink.o

obj-y += drivers/

clean:
	make ARCH=$(ARCHITECTURE) CROSS_COMPILE=$(CROSS_COMPILER_PREFIX) -C $(KERNEL_DIR) M=$(PWD) clean