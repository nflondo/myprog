#By adding an all section, you can just type 'make' otherwise, need to type full make cmd
all: lab.c
	make -C /lib/modules/`uname -r`/build M=$(PWD) modules
clean:
	make -C /lib/modules/`uname -r`/build M=$(PWD) clean
obj-m := lab.o
