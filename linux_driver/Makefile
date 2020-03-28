# When run make command in current directory, the KERNELRELEASE varible has not benn defined,
# so will run the code in else, go to kernel source directory to build kernel modules, and
# after finished, the build process will return back to current directory, and run make file
# again.
# And this time, the KERNELRELEASE varible has been defined, so it will run the code in ifneq,
# the kbuild sentences to declare the modules' dependencies.
ifneq ($(KERNELRELEASE),)
obj-m:=bz_module.o bz_add.o
else
KDIR:=/lib/modules/$(shell uname -r)/build
all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	rm -rf *.ko *.o *.mod.o *.mod.c *.symvers *.order 
endif
