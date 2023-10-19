#include <linux/module.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/device.h>

#define DRIVER_NAME "harrison_device"

enum pcdev_names {
    MYDEVICE1,
    MYDEVICE2,
    MYDEVICE3,
    MYDEVICE4
};

int my_platform_driver_remove(struct platform_device *pdev) { 
    printk("A device is removed\n");
    return 0;
}

int my_platform_driver_probe(struct platform_device *pdev) {
    printk("A device is detected\n");
    return 0;
}

const struct of_device_id dev_dt_match[] = {
    { .compatible = DRIVER_NAME, .data = (void *)MYDEVICE1 },
    { /* sentinel */ }
};

struct platform_device_id my_platform_device_id[] = {
    { .name = "my_device1", .driver_data = MYDEVICE1 },
    {}
};

struct platform_driver my_platform_driver = {
    .probe  = my_platform_driver_probe,  
    .remove = my_platform_driver_remove,
	.id_table = my_platform_device_id,
    .driver = {
        .name = DRIVER_NAME,
        .of_match_table = dev_dt_match
    }
};

/* Module's init entry point */
int __init helloworld_init(void) {
    printk("Hello world\n");
    platform_driver_register(&my_platform_driver);
    return 0;
}

/* Module's cleanup entry point */
void __exit helloworld_cleanup(void) {
    printk("Goodbye world\n");
    platform_driver_unregister(&my_platform_driver);
}

// module_platform_driver(my_platform_driver);
module_init(helloworld_init);
module_exit(helloworld_cleanup);

MODULE_LICENSE("GPL");
MODULE_VERSION("1.0.0");
MODULE_AUTHOR("Harrison");
MODULE_DESCRIPTION("A simple hello world kernel module");
MODULE_ALIAS("platform:harrison_device");  // Add this line to specify an alias for the device
