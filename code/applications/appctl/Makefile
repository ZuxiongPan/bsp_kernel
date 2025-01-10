TARGET := appctl
RELY := appctl.o

.PHONY: all install clean

all: $(RELY)
	$(CC) $(RELY) -o $(TARGET)
	
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)
	
install:
	mv -f $(TARGET) $(ROOT_DIR)/bin/
	
clean:
	rm -f $(RELY)