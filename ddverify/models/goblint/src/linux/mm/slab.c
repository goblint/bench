#include <linux/slab.h>
#include <linux/types.h>
#include <ddverify/ddverify.h>
#include <ddverify/satabs.h>

void * kmalloc(size_t size, gfp_t flags)
{
    if (flags & __GFP_WAIT) {
	assert_context_process();
    }

    return malloc(size);
}

void * kzalloc(size_t size, gfp_t flags)
{
    if (flags & __GFP_WAIT) {
	assert_context_process();
    }

    return malloc(size);
}
