#include <linux/blkdev.h>
#include <linux/fs.h>
#include <ddverify/satabs.h>
#include <ddverify/genhd.h>
#include <ddverify/blkdev.h>

request_queue_t *get_fixed_request_queue()
{
    if (number_request_queue_used < MAX_REQUEST_QUEUE_SUPPORT) {
	return &fixed_request_queue[number_request_queue_used++];
    } else {
	return NULL;
    }
}

request_queue_t *blk_init_queue(request_fn_proc *rfn, spinlock_t *lock)
{
    request_queue_t *queue;

    if (nondet_int()) {
	queue = get_fixed_request_queue();

	queue->queue_lock = lock;
	queue->request_fn = rfn;
	queue->make_request_fn = NULL;
	queue->__ddv_queue_alive = 1;
	
	return queue;
    } else {
	return NULL;
    }
}

request_queue_t *blk_alloc_queue(gfp_t gfp_mask)
{
    request_queue_t *queue;

    if (nondet_int()) {
	queue = get_fixed_request_queue();

	queue->request_fn = NULL;
	queue->make_request_fn = NULL;
	queue->__ddv_queue_alive = 1;
	
	return queue;
    } else {
	return NULL;
    }
}

void blk_queue_make_request(request_queue_t * q, make_request_fn * mfn)
{
  q->make_request_fn = mfn;
}

void end_request(struct request *req, int uptodate)
{
  int genhd_no = req->rq_disk->queue->__ddv_genhd_no;

  genhd_registered[genhd_no].requests_open = 0;
}


void blk_queue_hardsect_size(request_queue_t *q, unsigned short size)
{
  q->hardsect_size = size;
}

void blk_cleanup_queue(request_queue_t *q)
{
  q->__ddv_queue_alive = 0;
}
