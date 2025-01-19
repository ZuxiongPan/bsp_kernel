PWD := $(shell pwd)

obj-y += pr_kernobj.o
obj-y += export_funcs.o

clean:
	make ARCH=$(ARCHITECTURE) CROSS_COMPILE=$(CROSS_COMPILER_PREFIX) -C $(KERNEL_DIR) M=$(PWD) clean