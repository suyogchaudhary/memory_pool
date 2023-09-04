obj-m := mempool.o
obj-m += demo.o
obj-m += malloc.o

COMPILE=/lib/modules/`uname -r`/build

host:
	make -C ${COMPILE}  M=`pwd` modules
clean:
	make -C ${COMPILE}  M=`pwd` clean 
install:
	make -C ${COMPILE} M=`pwd` modules_install
	depmod -a
