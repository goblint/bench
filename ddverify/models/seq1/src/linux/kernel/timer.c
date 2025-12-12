#include <linux/timer.h>
#include <ddverify/timer.h>

inline void init_timer(struct timer_list * timer)
{
    if (number_timer_registered < MAX_TIMER_SUPPORT) {
	timer->__ddv_active = 0;
	timer->__ddv_init = 1;
	timer_registered[number_timer_registered].timer = timer;
	
	number_timer_registered++;
    }
}

inline void add_timer(struct timer_list *timer)
{
#ifdef DDV_ASSERT_TIMER
 __CPROVER_HIDE:
    __CPROVER_assert(timer->__ddv_init, "Timer is initialized");
#endif
    timer->__ddv_active = 1;
}

inline void add_timer_on(struct timer_list *timer, int cpu)
{
    // We do not care about the cpu number!   
    add_timer(timer);
}

inline int del_timer(struct timer_list * timer)
{
    timer->__ddv_active = 0;
}

inline int mod_timer(struct timer_list *timer, unsigned long expires)
{
#ifdef DDV_ASSERT_TIMER
 __CPROVER_HIDE:
    __CPROVER_assert(timer->__ddv_init, "Timer is initialized");
#endif
    timer->expires = expires;
    timer->__ddv_active = 1;
}
