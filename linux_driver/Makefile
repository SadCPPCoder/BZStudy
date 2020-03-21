obj-m:=bz_module.o
#KDIR:= /lib/modules/4.15.0-91-generic
KDIR:=/lib/modules/$(shell uname -r)/build
all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	rm -rf *.ko *.o *.mod.o *.mod.c *.symvers *.order 
