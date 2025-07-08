#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>

#include <ddverify/satabs.h>
#include <ddverify/cdev.h>

int alloc_chrdev_region(dev_t *dev, unsigned baseminor, unsigned count, const char *name) 
{
    int major;
    int return_value = nondet_int();
    __CPROVER_assume((return_value == 0) || (return_value == -1));

    if (return_value == 0) {
        major = nondet_uint();
	*dev = MKDEV(major, baseminor);
    }

    return return_value;
}

int register_chrdev_region(dev_t from, unsigned count, const char *name)
{
    int return_value = nondet_int();
    __CPROVER_assume((return_value == 0) || (return_value == -1));

    return return_value;
}

//void unregister_chrdev_region(dev_t, unsigned) {}


int register_chrdev(unsigned int major, const char *name,
		    struct file_operations *fops)
{
    struct cdev *cdev;
    int err;

    major = register_chrdev_region(0, 256, name);

    cdev = cdev_alloc();
    cdev->owner = fops->owner;
    cdev->ops = fops;

    err = cdev_add(cdev, MKDEV(major, 0), 256);

    if (err) {
	kfree(cdev);
	return err;
    }

    return major;
}


int unregister_chrdev(unsigned int major, const char *name)
{
    return 0;
}

struct cdev *cdev_alloc(void)
{
  if (fixed_cdev_used < MAX_CDEV_SUPPORT) {
    return &fixed_cdev[fixed_cdev_used++];
  }
}

void cdev_init(struct cdev *cdev, struct file_operations *fops)
{
    cdev->ops = fops;
}

int cdev_add(struct cdev *p, dev_t dev, unsigned count)
{
    p->dev = dev;
    p->count = count;

    int return_value = nondet_int();
    __CPROVER_assume((return_value == 0) || (return_value == -1));

    if (return_value == 0) {
	if (number_cdev_registered < MAX_CDEV_SUPPORT) {

	    cdev_registered[number_cdev_registered].cdevp = p;
	    cdev_registered[number_cdev_registered].inode.i_rdev = dev;
	    cdev_registered[number_cdev_registered].inode.i_cdev = p;
	    cdev_registered[number_cdev_registered].open = 0;

	    number_cdev_registered++;
	} else {
	    return -1;
	}
    }

    return return_value;    
}

void cdev_del(struct cdev *p)
{
    int i;

    for (i = 0; i < number_cdev_registered; i++) {
	if (cdev_registered[i].cdevp == p) {
	    cdev_registered[i].cdevp = 0;
	    
	    return;
	}
    }
}
