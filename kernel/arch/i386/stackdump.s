; Copied from dux/metodo @ http://github.com/RockerMONO/dux
BITS 32
extern panic_dump_hex
global stack_dump

stack_dump:
	push ebp
	mov ebp, esp
	call panic_dump_hex
	pop ebp
	ret
