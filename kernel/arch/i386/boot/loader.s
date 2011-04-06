; k411 i386 loader
; loader.s takes over over control from the Multiboot
; bootloader, and jumps into the kernel proper.

; Something from dux/metodo @ http://github.com/duckinator/dux
; In particular: _stacktop, extern stop (what is that?).

BITS 32
global loader  ; making entry point visible to linker
global _stacktop
extern kmain

; setting up the Multiboot header - see GRUB docs for details
MODULEALIGN  equ 1<<0             ; align loaded modules on page boundaries
MEMINFO      equ 1<<1             ; provide memory map
FLAGS        equ MODULEALIGN | MEMINFO  ; this is the Multiboot 'flag' field
MAGIC        equ 0x1BADB002       ; 'magic number' lets bootloader find the header
CHECKSUM     equ -(MAGIC + FLAGS) ; checksum required

section .text
align 4
MultiBootHeader:
	dd MAGIC
	dd FLAGS
	dd CHECKSUM

; reserve initial kernel stack space
STACKSIZE equ 0x4000     ; that is, 16k.

extern stop
loader:
	mov   esp, _stacktop ; set up the stack
	push  eax            ; Multiboot magic number
	push  ebx            ; Multiboot data structure

	call  kmain          ; call kernel proper

	cli
	hlt                  ; Stop the CPU.

hang:                    ; safety loop
	nop
	jmp   hang

section .bss
align 32
	resb STACKSIZE       ; reserve 16k stack on a quadword boundary
_stacktop:
