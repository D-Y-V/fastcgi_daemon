Fastcgi Daemon - Yandex's opensource framework for highload FastCGI applications on C++ design.

!!! Current fork required -std=c++17 && cmake.
$ into source tree...

mkdir build
cd build
 cmake -DCMAKE_INSTALL_PREFIX=`pwd`/binout .. && make all install

 for test non-root install, ajust LD_LIBRARY_PATH to lib directory.


[Документация](https://github.com/lmovsesjan/Fastcgi-Daemon/wiki/Документация)

[Documentation](https://github.com/lmovsesjan/Fastcgi-Daemon/blob/master/doc/en/Introduction.md)
