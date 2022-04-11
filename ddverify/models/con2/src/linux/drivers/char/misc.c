#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/miscdevice.h>
#include <linux/kernel.h>
#include <linux/major.h>
#include <linux/slab.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
//#include <linux/stat.h>
#include <linux/init.h>
#include <linux/device.h>
//#include <linux/tty.h>
//#include <linux/kmod.h>
#include <linux/cdev.h>

#include <ddverify/miscdevice.h>

int misc_register(struct miscdevice * misc)
{
  int i;
  dev_t dev;
 
  if (fixed_cdev_used < MAX_CDEV_SUPPORT) {
    i = fixed_cdev_used;
    fixed_cdev_used++;

    fixed_cdev[i].owner = THIS_MODULE;
    fixed_cdev[i].ops = misc->fops;
  
    dev = MKDEV(MISC_MAJOR, misc->minor);

    return cdev_add(&fixed_cdev[i], dev, 0);
  } else {
    return -1;
  }
}
