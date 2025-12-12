#include <linux/blkdev.h>
#include <ddverify/genhd.h>

struct request *elv_next_request(request_queue_t *q)
{
  int genhd_no = q->__ddv_genhd_no;

  if (genhd_registered[genhd_no].requests_open > 0) {
    return &genhd_registered[genhd_no].current_request;
  } else {
    return NULL;
  }
}
