What
====

A toy project at bootstrapping OS kernel.

Most of the lowest level code (which is almost everything now) is copied
from Dux/metodo ( http://duckinator.net/dux/metodo ). Their code is
at http://github.com/RockerMONO/dux .

Dux/metodo code should serve as a basement for future development.


Instructions
============

You can build i386 version on 64bit Linux. And currently you need to do so,
because k411 currently has no 64bit support.

* git clone git://github.com/temoto/k411.git
* cd k411
* make
* qemu -kernel kernel-i386.bin

Should see some debugging information on blue background.


Known bugs
==========

* Kernel panic on qemu -kernel with #GP

