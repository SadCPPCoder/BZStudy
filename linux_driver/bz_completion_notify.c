/****************************************
 * author: Zhang, Bob
 * date: 2020-03-29
 * discription: notify completion of bz_add
 ****************************************/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/completion.h>

extern struct completion bz_add_init_done;

static int __init bz_completion_notify_init(void)
{
    printk("%s, notify bz_add_init_done completion.\n", __func__);
    complete(&bz_add_init_done);
    return 0;
}

static void __exit bz_completion_notify_exit(void)
{
}

module_init(bz_completion_notify_init);
module_exit(bz_completion_notify_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("SadCPPCoder@github.com");
