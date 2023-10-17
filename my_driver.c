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

/* Module's init entry point */
int __init helloworld_init(void) {
    pr_info("Hello world\n"); // Removed KERN_INFO
    return 0;
}

int _platform_driver_remove(struct platform_device *pdev) { // Corrected the function name
    pr_info("A device is removed\n");
    return 0;
}

int _platform_driver_probe(struct platform_device *pdev) { // Corrected the function name
    pr_info("A device is detected\n");
    return 0;
}

const struct of_device_id dev_dt_match[] = {
    { .compatible = DRIVER_NAME, .data = (void *)MYDEVICE1 },
    { /* sentinel */ }
};

struct platform_device_id _platform_device_id[] = {
    { .name = "my_device1", .driver_data = MYDEVICE1 },
    { .name = "my_device2", .driver_data = MYDEVICE2 },
    { .name = "my_device3", .driver_data = MYDEVICE3 },
    { .name = "my_device4", .driver_data = MYDEVICE4 },
    {}
};

struct platform_driver _platform_driver = {
    .probe  = _platform_driver_probe,  // Corrected the function name
    .remove = _platform_driver_remove,  // Corrected the function name
	.id_table = _platform_device_id,
    .driver = {
        .name = DRIVER_NAME,
        .of_match_table = dev_dt_match
    }
};

/* Module's cleanup entry point */
void __exit helloworld_cleanup(void) {
    pr_info("Goodbye world\n"); // Removed KERN_INFO
}

module_init(helloworld_init);
module_exit(helloworld_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Harrison");
MODULE_DESCRIPTION("A simple hello world kernel module");
MODULE_ALIAS("platform:harrison_device");  // Add this line to specify an alias for the device
