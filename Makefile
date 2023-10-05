obj-m := my_driver.o
ARCH=arm64
DT_FILE=my_device
#set KERN_DIR to linux source location 
KERN_DIR = /lib/modules/$(shell uname -r)/build/

all:
	make ARCH=$(ARCH) -C $(KERN_DIR) M=$(PWD) modules
	dtc -O dtb -o $(DT_FILE).dtbo -@ $(DT_FILE).dts
modules:
	make ARCH=$(ARCH) -C $(KERN_DIR) M=$(PWD) modules
dtbo:
	dtc -O dtb -o $(DT_FILE).dtbo -@ $(DT_FILE).dts
clean:
	make ARCH=$(ARCH) -C $(KERN_DIR) M=$(PWD) clean
clean_dtbo:	
	@rm -rf *.dtbo
help:
	make ARCH=$(ARCH) -C $(KERN_DIR) M=$(PWD) help
