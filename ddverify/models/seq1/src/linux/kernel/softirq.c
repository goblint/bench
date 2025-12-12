#include <linux/interrupt.h>
#include <ddverify/tasklet.h>

inline void tasklet_schedule(struct tasklet_struct *t)
{
    int i;
    int next_free = -1;

#ifdef DDV_ASSERT_TASKLET
    __CPROVER_assert(t->init, "Tasklet is initialized!");
#endif

    for (i = 0; i < MAX_TASKLET_SUPPORT; i++) {
	if (tasklet_registered[i].tasklet == NULL) {
	    next_free = i;
	}
	if ((tasklet_registered[i].tasklet == t) &&
	    (tasklet_registered[i].is_running == 0)) {
	    return;
	}
    }
    
    if (next_free == -1) {
//    __CPROVER_assert(0, "Number of supported tasklets is sufficient");
    }
    
    tasklet_registered[next_free].tasklet = t;
    tasklet_registered[next_free].is_running = 0;
}

inline void tasklet_init(
  struct tasklet_struct *t,
  void (*func)(unsigned long), unsigned long data)
{
    t->count = 0;
    t->init = 0;
    t->func = func;
    t->data = data;
}
