# k411 Makefile
#

# General
# ^^^^^^^

DEBUG   := 1

CC := gcc
AS := nasm
LD := ld

CFLAGS  := $(CFLAGS) -std=c99 -Wall -Wextra -Werror \
	-ffreestanding -nostdlib -nostartfiles -nodefaultlibs \
	-I$(shell pwd)/include

ifeq ("$(DEBUG)", "1")
  CFLAGS  += -g -DDEBUG
  ASFLAGS += -g
endif

MAKEFLAGS += --no-print-directory


# Architecture
# ^^^^^^^^^^^^

ARCH := $(shell uname -m | sed -e s/i.86/i386/)
ifeq ($(ARCH),x86_64)
  ARCH := i386
endif

ifeq ("$(ARCH)", "i386")
  CFLAGS  += -m32
  ASFLAGS += -f elf32
  LDFLAGS += -melf_i386
else
  $(error Unsupported ARCH: $(ARCH))
endif

version := $(shell git rev-parse --short HEAD)

CFLAGS += -DARCH=$(ARCH) -DARCH_$(ARCH) \
	-DK411_BUILD_STR="\"$(version) $(ARCH) debug\""

export CC AS LD CFLAGS ASFLAGS LDFLAGS ARCH DEBUG


# Targets
# ^^^^^^^

.PHONY: clean kernel test

# default target
kernel:
	@$(MAKE) -C kernel ../kernel-$(ARCH).bin

clean:
	@$(MAKE) -C kernel $@

test:
	@echo "No tests yet, sorry."
	@exit 1
