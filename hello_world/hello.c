/* Module source file 'crash1.c'. */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

static int hi(void)
{
     printk(KERN_INFO "Here come dat boi.\n");
     return 0;
}

static void bye(void)
{
     printk(KERN_INFO "Oh shit whattup!\n");
}

module_init(hi);
module_exit(bye);

MODULE_AUTHOR("Robert P. J. Day, http://crashcourse.ca");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("Doing a whole lot of nothing.");
