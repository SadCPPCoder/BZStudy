 /*********************************************************
 * author: Zhang, Bob
 * date: 2020-03-28
 * description: This module to provide add operation to int
 *********************************************************/
#include <linux/module.h>
#include <linux/kernel.h>

static char* bz_add_author = "Zhang, Bob";
static int bz_add_version = 110;

static int __init bz_add_init( void )
{
    printk("$s, sucessfully!\n", __func__);
    return 0;
}

static void __exit bz_add_exit( void )
{
    printk("$s, sucessfully!\n", __func__);
}

static int bz_add(int a, int b)
{
    printk("%s, inupt a:%d, b:%d, the sum is %d.\n", __func__, a, b, a+b);
    return a+b;
}
EXPORT_SYMBOL(bz_add);
EXPORT_SYMBOL(bz_add_author);
EXPORT_SYMBOL(bz_add_version);

module_init(bz_add_init);
module_exit(bz_add_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Zhang, Bob<SadCPPCoder@github.com>");
