#include <ddverify/satabs.h>
#include <ddverify/ddverify.h>
#include <ddverify/workqueue.h>

int schedule_work(struct work_struct *work)
{
    int i;

#ifdef DDV_ASSERT_WORK_QUEUE
 __CPROVER_HIDE:
    __CPROVER_assert(work->init, "Work queue is initalized");
#endif

    for (i = 0; i < MAX_WORKQUEUE_ELEMENTS_SUPPORT; i++) {
	if (shared_workqueue[i] == work) {
	    return 0;
	}
	
	if (shared_workqueue[i] == NULL) {
	    shared_workqueue[i] = work;
	    
	    return 1;
	}
    }
    

    return -1;
}

void call_shared_workqueue_functions()
{
    unsigned short i = nondet_ushort();
    __CPROVER_assume(i < MAX_WORKQUEUE_ELEMENTS_SUPPORT);
    
    if (shared_workqueue[i] != NULL) {
	(*shared_workqueue[i]->func)(shared_workqueue[i]->data);
	shared_workqueue[i] = NULL;
    }
}
