#include <linux/gfp.h>
#include <ddverify/ddverify.h>
#include <ddverify/satabs.h>

inline unsigned long __get_free_pages(gfp_t gfp_mask, unsigned int order)
{
 __CPROVER_HIDE:
    if (gfp_mask & __GFP_WAIT) {
	assert_context_process();
    }
}

inline unsigned long __get_free_page(gfp_t gfp_mask)
{
 __CPROVER_HIDE:
    if (gfp_mask & __GFP_WAIT) {
	assert_context_process();
    }
}

inline unsigned long get_zeroed_page(gfp_t gfp_mask)
{
 __CPROVER_HIDE:
    if (gfp_mask & __GFP_WAIT) {
	assert_context_process();
    }
}

inline static struct page *alloc_pages_node(
  int nid, gfp_t gfp_mask, unsigned int order)
{
 __CPROVER_HIDE:
    if (gfp_mask & __GFP_WAIT) {
	assert_context_process();
    }
}

inline struct page * alloc_pages(gfp_t gfp_mask, unsigned int order)
{
 __CPROVER_HIDE:
    if (gfp_mask & __GFP_WAIT) {
	assert_context_process();
    }
}

inline struct page * alloc_page(gfp_t gfp_mask)
{
 __CPROVER_HIDE:
    if (gfp_mask & __GFP_WAIT) {
	assert_context_process();
    }
}
