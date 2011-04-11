What
====

A toy project at bootstrapping OS kernel.

Most of the lowest level code (which is almost everything now) is copied
from Dux/metodo ( http://duckinator.net/dux/metodo ). Their code is
at http://github.com/duckinator/dux .

Dux/metodo code should serve as a basement for future development.

Task switching code is copied from little kernel ( http://git.tkgeisel.com/?p=lk.git;a=summary )
by Travis Geiselbrecht.


Instructions
============

You can build i386 version on 64bit Linux. And currently you need to do so,
because k411 currently has no 64bit support.

* git clone git://github.com/temoto/k411.git
* cd k411
* ./scripts/build/boot-i386
* qemu -cdrom boot-i386.iso

Should see some debugging information and interleaving AAA...BBB... If you don't like that,
remove two calls 'kspawn_fun' in kernel/main.c.


TODO
====

Priorities given in parens.

* (5) Implement process sleep.
* (4) Find a way to load ELF binary from GRUB modules and spawn it as separate process.
* (3) Learn to switch to user mode (ring3). Run ELF binary in user mode.
* (2) Write tests.
* (1) Write init service. 'Upstart' could be a good design guide.
* (1) New arch: amd64.


Known bugs
==========

* Fixed. Kernel panic on `qemu -kernel` with #GP.
