OUTPUT_FORMAT(elf32-i386)
ENTRY (loader)

KERNEL_VMA = 0x100000;

SECTIONS{
	. = KERNEL_VMA;
	start = .;

	.debug_info : {
		debug_info_start = .;
		*(.debug_info)
		debug_info_end = .;
	}

	.text :{
		*(.mboot)
		*(.text)
	}

	.rodata ALIGN (0x1000) : {
		*(.rodata)
	}

	.data ALIGN (0x1000) : {
		*(.data)
	}

	.bss : {
		sbss = .;
		*(COMMON)
		*(.bss)
		ebss = .;
	}

	end = .;
}
