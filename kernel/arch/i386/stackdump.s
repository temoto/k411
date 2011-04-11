; Copied from dux/metodo @ http://github.com/duckinator/dux
BITS 32
extern PanicDumpHex
global StackDump

StackDump:
	push ebp
	mov ebp, esp
	call PanicDumpHex
	pop ebp
	ret
