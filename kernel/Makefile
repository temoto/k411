# k411 kernel Makefile

arch_dir := arch/$(ARCH)
kernel_bin := ../kernel-$(ARCH).bin

objs := \
	$(arch_dir)/boot/loader.o \
	$(arch_dir)/driver/keyboard.o \
	$(arch_dir)/driver/timer.o \
	$(arch_dir)/driver/vga.o \
	$(arch_dir)/hal/exceptions.o \
	$(arch_dir)/hal/gdt.o \
	$(arch_dir)/hal/hal.o \
	$(arch_dir)/hal/idt.o \
	$(arch_dir)/hal/interrupts.o \
	$(arch_dir)/hal/irqs.o \
	$(arch_dir)/hal/isrs.o \
	$(arch_dir)/hal/mm.o \
	$(arch_dir)/hal/ports.o \
	$(arch_dir)/hal/scheduler.o \
	$(arch_dir)/hal/shutdown.o \
	$(arch_dir)/hal/syscall.o \
	$(arch_dir)/stackdump.o \
	api/display.o \
	colpa/debug.o \
	colpa/dprint.o \
	core/print.o \
	core/scheduler.o \
	core/shutdown.o \
	core/stop.o \
	core/task.o \
	main.o \
	panic.o \
	stdlib/mem.o \
	stdlib/string.o \
	tests.o


# Targets
# ^^^^^^^

.PHONY: clean

default: $(kernel_bin)

clean:
	@rm -f ${objs} $(kernel_bin)

$(kernel_bin): ${objs}
	$(LD) $(LDFLAGS) -T $(arch_dir)/boot/linker.ld -o $@ $^


# Dependencies
# ^^^^^^^^^^^^
# TODO: find the tool that automates this
main.o: ../include/k411.h ../include/k411/modules.h ../include/k411/tests.h
