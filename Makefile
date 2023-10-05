obj-m := my_driver.o
ARCH=arm64
#set KERN_DIR to linux source location 
KERN_DIR = /lib/modules/$(shell uname -r)/build/

all:
	make ARCH=$(ARCH) -C $(KERN_DIR) M=$(PWD) modules
clean:
	make ARCH=$(ARCH) -C $(KERN_DIR) M=$(PWD) clean
clean_dtbo:	
	@rm -rf *.dtbo
help:
	make ARCH=$(ARCH) -C $(KERN_DIR) M=$(PWD) help
