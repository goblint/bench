#include <linux/blkdev.h>
#include <linux/fs.h>
#include <ddverify/genhd.h>
#include <ddverify/satabs.h>

int register_blkdev(unsigned int major, const char *name)
{
  int result = nondet_int();
  
  /*if ((major > 0) && (result > 0)) {
    return major;
    }*/
  
  return result;
}

int unregister_blkdev(unsigned int major, const char *name)
{
  return 0;
}

struct gendisk *alloc_disk(int minors)
{
  struct gendisk * gd;

  if (number_fixed_genhd_used < MAX_GENHD_SUPPORT) {
    gd = &fixed_gendisk[number_fixed_genhd_used];
    gd->minors = minors;

    number_fixed_genhd_used++;

    return gd;
  } else {
    return NULL;
  }
}

void add_disk(struct gendisk *disk)
{
  if (number_genhd_registered < MAX_GENHD_SUPPORT) {
    genhd_registered[number_genhd_registered].gd = disk;
    genhd_registered[number_genhd_registered].inode.i_bdev = (struct block_device*)malloc(sizeof(struct block_device));
    genhd_registered[number_genhd_registered].inode.i_bdev->bd_disk = disk;

    number_genhd_registered++;
  }
}

void del_gendisk(struct gendisk *gp)
{
  int i;

  for (i = 0; i < number_genhd_registered; i++) {
    if (genhd_registered[i].gd == gp) {
      genhd_registered[i].gd = NULL;
    }
  }
}
