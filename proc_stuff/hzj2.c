#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/jiffies.h>

static int
hz_show(struct seq_file *m, void *v)
{
    seq_printf(m, "hz: %d\n", HZ);

    return 0;
}

static int
jiffies_show(struct seq_file *m, void *v)
{
    seq_printf(m, "jiffies: %llu\n", \
              (unsigned long long) get_jiffies_64());

    return 0;
}

static int
hz_open(struct inode *inode, struct file *file)
{
    return single_open(file, hz_show, NULL);
}


static int
jiffies_open(struct inode *inode, struct file *file)
{
    return single_open(file, jiffies_show, NULL); 
}

static const struct file_operations hz_fops = {
    .owner      = THIS_MODULE,
    .open       = hz_open,
    .read       = seq_read,
    .llseek     = seq_lseek,
    .release    = single_release,
};

static const struct file_operations jiffies_fops = {
    .owner      = THIS_MODULE,
    .open       = jiffies_open,
    .read       = seq_read,
    .llseek     = seq_lseek,
    .release    = single_release,
};

static int __init
hz_init(void)
{
    printk(KERN_INFO "Loading hz module, HZ = %d.\n", HZ);
    proc_create("hz", 0, NULL, &hz_fops);
    proc_create("jiffies", 0, NULL, &jiffies_fops);
    return 0;
}

static void __exit
hz_exit(void)
{
    remove_proc_entry("hz", NULL);
    remove_proc_entry("jiffies", NULL);
    printk(KERN_INFO "Unloading hz module.\n");
}

module_init(hz_init);
module_exit(hz_exit);

MODULE_LICENSE("GPL");
