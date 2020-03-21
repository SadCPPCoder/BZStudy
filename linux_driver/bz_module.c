#include <linux/module.h> // header for module_init/module_exit/MODULE_LICENSE
#include <linux/kernel.h> // header for printk

// __init to add code to init segment
static int __init bz_module_init(void)
{
    printk("%s is called to init Bob's module!\n", __func__);
    return 0;
}

// __exit to add code to exit segment
static void __exit bz_module_exit(void)
{
    printk("%s is called to uninstall Bob's module!\n");
}

module_init(bz_module_init);
module_exit(bz_module_exit);
MODULE_LICENSE("GPL");
