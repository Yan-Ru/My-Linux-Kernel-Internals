#include<linux/module.h>
#include<linux/of_device.h>
#include<linux/device.h>

/*Module's init entry point */
static int __init helloworld_init(void)
{
   pr_info(KERN_INFO "Hello world\n");
   return 0;
}

static const struct of_device_id dev_dt_match[] = {
	{ .name = DRIVER_NAME,.compatible = "harrison_device"},
	{ /* sentinel */ }
};

/*Module's cleanup entry point */
static void __exit helloworld_cleanup(void)
{
  pr_info(KERN_INFO "Goodbye world\n");
}

module_init(helloworld_init);
module_exit(helloworld_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Harrison");
MODULE_DESCRIPTION("A simple hello world kernel module");