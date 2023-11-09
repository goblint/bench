#include <ddverify/interrupt.h>
#include <linux/interrupt.h>

int request_irq(unsigned int irq, irq_handler_t handler,
		unsigned long irqflags, const char * devname, void *dev_id)
{
    if (nondet_int()) {
	registered_irq[irq].handler = handler;
	registered_irq[irq].dev_id = dev_id;
	
	return 0;
    } else {
        return -1;
    }
}

void free_irq(unsigned int irq, void *dev_id)
{
    registered_irq[irq].handler = NULL;
    registered_irq[irq].dev_id = NULL;
}
