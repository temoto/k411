# k411 Makefile
#

objs := main.o

CFLAGS := $(CFLAGS) -g -std=c99 -Wall -Wextra -Werror \
	-nostdlib -nostartfiles -nodefaultlibs
ASFLAGS := $(ASFLAGS) -g --warn


.PHONY: clean test

default: clean all

all: kernel-x86-32.bin

clean:
	@rm -f kernel-*.bin loader-*.o ${objs}

kernel-x86-32.bin: ${objs} arch/x86-32/loader.o
	$(LD) $(LDFLAGS) -T arch/x86-32/linker.ld -o $@ $^

kernel-x86-64.bin: ${objs} arch/x86-64/loader.o
	$(LD) $(LDFLAGS) -T arch/x86-64/linker.ld -o $@ $^
