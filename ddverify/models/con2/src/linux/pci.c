#include <linux/mod_devicetable.h>
#include <linux/pci.h>
#include <ddverify/ddverify.h>
#include <ddverify/satabs.h>
#include <ddverify/interrupt.h>
#include <ddverify/pci.h>

int pci_enable_device(struct pci_dev *dev)
{
    int i;

    for (i = 0; i < DEVICE_COUNT_RESOURCE; i++) {
	dev->resource[i].flags = IORESOURCE_IO;
	dev->resource[i].start = nondet_uint();
	dev->resource[i].end   = dev->resource[i].start + nondet_ushort();
    }
}

struct pci_dev *pci_get_class (unsigned int class, struct pci_dev *from)
{
    if (from == NULL) {
	from = (struct pci_dev*)malloc(sizeof(struct pci_dev));
    }
    
    if (nondet_int()) {
	from->vendor = nondet_ushort();
	from->device = nondet_ushort();
	from->irq    = nondet_uint();
	__CPROVER_assume(from->irq < MAX_IRQ_SUPPORT);
	
	return from;
    } else {
	return NULL;
    }
}

int pci_register_driver(struct pci_driver *driver)
{
    if (nondet_int()) {
	registered_pci_driver.pci_driver       = driver;
	registered_pci_driver.no_pci_device_id = sizeof(driver->id_table) / sizeof(struct pci_device_id);
	registered_pci_driver.dev_initialized  = 0;
	
	return 0;
    } else {
	return -1;
    }
}

void pci_unregister_driver(struct pci_driver *driver)
{
    registered_pci_driver.pci_driver       = NULL;
    registered_pci_driver.no_pci_device_id = 0;
}

void pci_release_region(struct pci_dev *pdev, int bar)
{
    if (pci_resource_len(pdev, bar) == 0)
	return;
    if (pci_resource_flags(pdev, bar) & IORESOURCE_IO)
	release_region(pci_resource_start(pdev, bar),
		       pci_resource_len(pdev, bar));
    else if (pci_resource_flags(pdev, bar) & IORESOURCE_MEM)
	release_mem_region(pci_resource_start(pdev, bar),
			   pci_resource_len(pdev, bar));
}

int pci_request_region(struct pci_dev *pdev, int bar, const char *res_name)
{
    if (pci_resource_len(pdev, bar) == 0)
	return 0;
    
    if (pci_resource_flags(pdev, bar) & IORESOURCE_IO) {
	if (!request_region(pci_resource_start(pdev, bar),
			    pci_resource_len(pdev, bar), res_name))
	    return -EBUSY;
    }
    else if (pci_resource_flags(pdev, bar) & IORESOURCE_MEM) {
	if (!request_mem_region(pci_resource_start(pdev, bar),
				pci_resource_len(pdev, bar), res_name))
	    return -EBUSY;
    }
	
    return 0;
}


void pci_release_regions(struct pci_dev *pdev)
{
    int i;
    
    for (i = 0; i < 6; i++)
	pci_release_region(pdev, i);
}


int pci_request_regions(struct pci_dev *pdev, const char *res_name)
{
    int i;
    
    for (i = 0; i < 6; i++)
	if(pci_request_region(pdev, i, res_name))
	    goto err_out;
    return 0;
    
 err_out:
    while(--i >= 0)
	pci_release_region(pdev, i);
    
    return -EBUSY;
}
