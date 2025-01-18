PWD := $(shell pwd)

obj-y += pzxkernel_debug.o

clean:
	make ARCH=$(ARCHITECTURE) CROSS_COMPILE=$(CROSS_COMPILER_PREFIX) -C $(KERNEL_DIR) M=$(PWD) clean