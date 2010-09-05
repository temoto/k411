What
====

A toy project at bootstrapping OS kernel.


Instructions
============

You can build i386 version on 64bit Linux. And currently you need to do so,
because k411 currently has no 64bit support.

* git clone git://github.com/temoto/k411.git
* cd k411
* make
* qemu -kernel kernel-i386.bin

Should see "Hello world!" at first line.


Known bugs
==========

* Will not print message on qemu 0.12.3 (and probably higher).
  Because qemu stops updating screen at some point.
  Run in gdb to see it.

