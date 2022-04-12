#include <linux/vmalloc.h>
#include <linux/types.h>

#include <ddverify/satabs.h>

void * vmalloc(unsigned long size)
{
  return malloc(size);
}
