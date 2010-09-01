What
====

A toy project at bootstrapping OS kernel.


Instructions
============

* git clone git://github.com/temoto/k411.git
* cd k411
* ./build-x86-32
* qemu -kernel kernel-x86-32.bin

Should see "Hello world!" at first line.

Will not print message on qemu 0.12.3 (and probably higher).

