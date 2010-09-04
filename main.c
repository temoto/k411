// k411 main.c


void kprintln(const char *s) {
    unsigned short *mvideo = (unsigned short*) 0xb8000;
    const char *ch = s;
    for (int i = 0; *ch; ch++, i++) {
        mvideo[i] = (unsigned char) *ch | 0x0700;
    }
}

void kmain(void *mbd, unsigned int magic) {
    if ( magic != 0x2BADB002 ) {
        /* Something went not according to specs. Print an error */
        /* message and halt, but do *not* rely on the multiboot */
        /* data structure. */
    }

    /* You could either use multiboot.h */
    /* (http://www.gnu.org/software/grub/manual/multiboot/multiboot.html#multiboot_002eh) */
    /* or do your offsets yourself. The following is merely an example. */ 
    char *boot_loader_name = (char*) ((long*)mbd)[16];

    if (boot_loader_name) {
        // Just to use boot_loader_name
    }

    kprintln("Hello world!");

    // TODO: scheduler, VM, etc
}
