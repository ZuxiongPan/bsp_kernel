include $(CONFIG_DIR)/pzx_user_config

CC := $(CROSS_COMPILER_PREFIX)gcc
CFLAGS := -I$(BSPINC_DIR)
LDFLAGS :=

export CC CFLAGS LDFLAGS

dirs-y += appctl/
dirs-y += pserver/
dirs-$(CONFIG_UEVENT_TEST) += uevent_test/

.PHONY: all install clean

all:
	for dir in $(dirs-y); do \
	make -C $$dir; \
	done
	
install:
	for dir in $(dirs-y); do \
	make -C $$dir install; \
	done

clean:
	for dir in $(dirs-y); do \
	make -C $$dir clean; \
	done
