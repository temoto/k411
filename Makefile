# k411 Makefile
#

# General
# ^^^^^^^

DEBUG   := 1
CFLAGS  := $(CFLAGS) -std=c99 -Wall -Wextra -Werror \
	-nostdlib -nostartfiles -nodefaultlibs
ASFLAGS := $(ASFLAGS) --warn

ifeq ("$(DEBUG)", "1")
  CFLAGS  += -g -DDEBUG
  ASFLAGS += -g
endif

MAKEFLAGS := --no-print-directory


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

export CC AS LD CFLAGS ASFLAGS LDFLAGS ARCH DEBUG


# Targets
# ^^^^^^^

.PHONY: all clean default test

default: clean all

all:
	@$(MAKE) -C kernel ../kernel-$(ARCH).bin

clean:
	@$(MAKE) -C kernel $@

test:
	@echo "No tests yet, sorry."
	@exit 1
