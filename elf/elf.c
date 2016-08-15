/* Module source file 'elf.c'. */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

static int whatever;
static int answer = 42;

static char __initdata elf_howdymsg[] = "Good day, eh?";
static char __exitdata elf_exitmsg[] = "Taking off, eh?";

void
useless(void)
{
    printk(KERN_INFO "I am totally useless.\n");
}

static int __init elf_hi(void)
{
    printk(KERN_INFO "module elf being loaded.\n");
    printk(KERN_INFO "%s\n", elf_howdymsg);
    printk(KERN_INFO "The answer is %d.\n", answer);
    return 0;
}

static void __exit elf_bye(void)
{
    printk(KERN_INFO "module elf being unloaded.\n");
    printk(KERN_INFO "%s\n", elf_exitmsg);
    printk(KERN_INFO "The answer is now %d.\n", answer);
}

module_init(elf_hi);
module_exit(elf_bye);

MODULE_AUTHOR("Robert P. J. Day");
MODULE_LICENSE("GPL");
