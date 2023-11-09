#include <ddverify/ddverify.h>
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/capability.h>
#include <linux/blkdev.h>

void schedule()
{
    assert_context_process();
}

long schedule_timeout(long timeout)
{
    assert_context_process();

    return nondet_long();
}
