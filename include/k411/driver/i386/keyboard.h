#ifndef HAL_KEYBOARD_H
// Copied from dux/metodo @ http://github.com/duckinator/dux
#define HAL_KEYBOARD_H

#define SCROLL_LED 1
#define NUM_LED 2
#define CAPSLOCK_LED 4

typedef struct HalKeyInfo {
	int ctrl_l, ctrl_r;
	int alt_l, alt_r;
	int shift_l, shift_r;
	int action;
	int scancode;
	char key;
	char unused[3]; // Fix alignment
} HalKeyInfo;

extern void HalKeyboardHandler(struct regs *r);
extern int HalKeyboardCapslock();
extern int HalKeyboardNumlock();
extern char HalKeyboardHasInput();
extern HalKeyInfo *HalKeyboardRead();
extern HalKeyInfo *HalKeyboardReadLetter();
extern HalKeyInfo *HalKeyboardResolveScancode(HalKeyInfo *keyinfo);
extern HalKeyInfo *HalKeyboardResolveScancode_shift(HalKeyInfo *keyinfo);
extern void HalKeyboardInit();

extern void HalKeyboardTest();

// The following are a list of the 'make' codes.
// We find break codes from these
#define SHIFT_LEFT    0x2A
#define SHIFT_RIGHT   0x36
#define CAPSLOCK      0xBA
#define ALT           0x38
#define CONTROL       0x1D

#endif /* end of include guard: HAL_KEYBOARD_H */
