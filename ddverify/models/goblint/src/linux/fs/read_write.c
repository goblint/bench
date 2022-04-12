#include <linux/file.h>

#define ESPIPE 29

loff_t no_llseek(struct file *file, loff_t offset, int origin)
{
    return -ESPIPE;
}

