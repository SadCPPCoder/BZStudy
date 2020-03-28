#include <linux/module.h> // header for module_init/module_exit/MODULE_LICENSE
#include <linux/kernel.h> // header for printk

// declare external symbol
extern int bz_add(int a, int b);
extern char *bz_add_author;
extern int bz_add_version;

// __init to add code to init segment
static int __init bz_module_init(void)
{
    int sum = 0;

    printk("%s is called to init Bob's module!\n", __func__);

    printk("%s, try to calculate 5+6...\n", __func__);

    sum = bz_add(5, 6);

    printk("%s, sum of 5 and 6 is %d.\n", __func__, sum);

    printk("%s, add function provided by %s, version: %d", bz_add_author, bz_add_version);

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
