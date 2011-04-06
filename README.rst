What
====

A toy project at bootstrapping OS kernel.

Most of the lowest level code (which is almost everything now) is copied
from Dux/metodo ( http://duckinator.net/dux/metodo ). Their code is
at http://github.com/duckinator/dux .

Dux/metodo code should serve as a basement for future development.


Instructions
============

You can build i386 version on 64bit Linux. And currently you need to do so,
because k411 currently has no 64bit support.

* git clone git://github.com/temoto/k411.git
* cd k411
* ./scripts/build/boot-i386
* qemu -cdrom boot-i386.iso

Should see some debugging information on blue background.


TODO
====

Priorities given in parens.

* (5) Understand how metodo scheduler works, find a way to spawn process with
  statically located code.
* (4) Find a way to load ELF binary from GRUB modules and spawn it as separate process.
* (1) Write init service. 'Upstart' could be a good design guide.


Known bugs
==========

* Kernel panic on `qemu -kernel` with #GP.

