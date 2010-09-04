# k411 Makefile
#

# General
# ^^^^^^^

DEBUG   := 1
CFLAGS  := $(CFLAGS) -std=c99 -Wall -Wextra -Werror \
	-nostdlib -nostartfiles -nodefaultlibs
ASFLAGS := $(ASFLAGS) --warn

ifeq ("$(DEBUG)", "1")
  CFLAGS  += -g
  ASFLAGS += -g
endif


# Architecture
# ^^^^^^^^^^^^

ARCH := $(shell uname -m | sed -e s/i.86/i386/)
ifeq ($(ARCH),x86_64)
  ARCH := i386
endif

ifeq ("$(ARCH)", "i386")
  CFLAGS  += -m32
  LDFLAGS += -melf_i386
  ASFLAGS += --32
else
  $(error Unsupported ARCH: $(ARCH))
endif


objs    := main.o


.PHONY: clean test

default: clean all

all: kernel-$(ARCH).bin

clean:
	@rm -f kernel-*.bin arch/*/loader.o ${objs}

test:
	@echo "No tests ATM, sorry."
	@exit 1

kernel-$(ARCH).bin: ${objs} arch/$(ARCH)/loader.o
	$(LD) $(LDFLAGS) -T arch/$(ARCH)/linker.ld -o $@ $^
