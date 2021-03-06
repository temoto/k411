// Copied from dux/metodo @ http://github.com/duckinator/dux
#include <colpa/debug.h>


noreturn KernDebug()
{
	HalKeyInfo *keyinfo;
	printf("Initiating kernel debugger...\n>> ");
	while(1) {
		if ( HalKeyboardHasInput() ) {
			keyinfo = HalKeyboardReadLetter();
			if ( keyinfo->action == 0 ) {
				switch ( keyinfo->scancode ) {
				// Enter
				case 0x9c:
					printf("\n>> ");
					break;
				// Otherwise
				default:
					printf("%c", keyinfo->key);
					break;
				}
			}
		}
	}
}
