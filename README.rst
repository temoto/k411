What
====

A toy project at bootstrapping OS kernel.


Instructions
============

You can build x86-32 version on 64bit Linux. And currently you need to do so,
because x86-64 version doesn't boot.

* git clone git://github.com/temoto/k411.git
* cd k411
* scripts/build/native-x86-32
* qemu -kernel kernel-x86-32.bin

Should see "Hello world!" at first line.


Known bugs
==========

* x86-64 is not booting. It doesn't reach kmain().

* Will not print message on qemu 0.12.3 (and probably higher).
  Because qemu stops updating screen at some point.
  Run in gdb to see it.

