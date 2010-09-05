# k411 kernel Makefile

arch_dir := arch/$(ARCH)
kernel_bin := ../kernel-$(ARCH).bin

objs := main.o $(arch_dir)/loader.o


# Targets
# ^^^^^^^

.PHONY: clean

default: $(kernel_bin)

clean:
	@rm -f ${objs} $(kernel_bin)

$(kernel_bin): ${objs}
	$(LD) $(LDFLAGS) -T $(arch_dir)/linker.ld -o $@ $^
