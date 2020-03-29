 /*********************************************************
 * author: Zhang, Bob
 * date: 2020-03-28
 * description: This module to provide add operation to int
 *********************************************************/
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h> // for ssleep
#include <linux/completion.h> // for completion
#include <linux/jiffies.h>

static char* bz_add_author = "Zhang, Bob";
static int bz_add_version = 110;
//static struct completion bz_add_init_done;
DECLARE_COMPLETION(bz_add_init_done);

static int __init bz_add_init( void )
{
    init_completion(&bz_add_init_done);
    printk("%s, sucessfully!\n", __func__);

    return 0;
}

static void __exit bz_add_exit( void )
{
    printk("%s, sucessfully!\n", __func__);
}

static int bz_add(int a, int b)
{
    int ret;
    printk("%s, 5000ms convert to jiffies, result is %lu.\n", __func__, msecs_to_jiffies(5000));
    printk("%s, jiffies convert to milliseconds, result is %d.\n", __func__, jiffies_to_msecs(msecs_to_jiffies(5000)));
    ret = wait_for_completion_interruptible_timeout(&bz_add_init_done, msecs_to_jiffies(5000));
    if(!ret)
    {
        printk("%s, timeout for waiting the initialization!\n", __func__);
        return -1;
    }
    else
    {
        printk("%s, return: %d!\n", __func__, ret);
    }
    
    printk("%s, inupt a:%d, b:%d, the sum is %d.\n", __func__, a, b, a+b);
    return a+b;
}

EXPORT_SYMBOL(bz_add);
EXPORT_SYMBOL(bz_add_author);
EXPORT_SYMBOL(bz_add_version);
EXPORT_SYMBOL(bz_add_init_done);

module_init(bz_add_init);
module_exit(bz_add_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Zhang, Bob<SadCPPCoder@github.com>");
