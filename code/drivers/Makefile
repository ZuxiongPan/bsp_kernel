dirs-y += virt/

.PHONY: all clean

all:
	for dir in $(dirs-y); do \
	make -C $$dir; \
	done
	
clean:
	for dir in $(dirs-y); do \
	make -C $$dir clean; \
	done