#ifndef LINUX_PCI_H
#define LINUX_PCI_H

#include <linux/types.h>
#include <linux/config.h>
#include <linux/ioport.h>
#include <linux/list.h>
#include <linux/errno.h>
#include <linux/device.h>
#include <linux/mod_devicetable.h>
#include <linux/scatterlist.h>

/* Include the pci register defines */
#include <linux/pci_regs.h>

/* Include the ID list */
#include <linux/pci_ids.h>

/*
 * The PCI interface treats multi-function devices as independent
 * devices.  The slot/function address of each device is encoded
 * in a single byte as follows:
 *
 *	7:3 = slot
 *	2:0 = function
 */
#define PCI_DEVFN(slot,func)	((((slot) & 0x1f) << 3) | ((func) & 0x07))
#define PCI_SLOT(devfn)		(((devfn) >> 3) & 0x1f)
#define PCI_FUNC(devfn)		((devfn) & 0x07)

/* This defines the direction arg to the DMA mapping routines. */
#define PCI_DMA_BIDIRECTIONAL	0
#define PCI_DMA_TODEVICE	1
#define PCI_DMA_FROMDEVICE	2
#define PCI_DMA_NONE		3

#define DEVICE_COUNT_COMPATIBLE	4
#define DEVICE_COUNT_RESOURCE	12

typedef int __bitwise pci_power_t;


struct pci_dev {
    struct pci_bus	*bus;           /* bus this device is on */

    unsigned int	devfn;		/* encoded device & function index */
    unsigned short	vendor;
    unsigned short	device;


    u64		        dma_mask;

    struct device	dev;	
    
    unsigned int	irq;
    struct resource     resource[DEVICE_COUNT_RESOURCE];   /* I/O and memory regions + expansion ROMs */
};


#define for_each_pci_dev(d) while ((d = pci_get_device(PCI_ANY_ID, PCI_ANY_ID, d)) != NULL)

struct pci_bus {
    unsigned char	number;		/* bus number */
};


struct pci_driver {
    char *name;
    const struct pci_device_id *id_table;	/* must be non-NULL for probe to be called */
    int  (*probe)  (struct pci_dev *dev, const struct pci_device_id *id);	/* New device inserted */
    void (*remove) (struct pci_dev *dev);	/* Device removed (NULL if not a hot-plug capable driver) */
    int  (*suspend) (struct pci_dev *dev, pm_message_t state);	/* Device suspended */
    int  (*resume) (struct pci_dev *dev);	                /* Device woken up */
    int  (*enable_wake) (struct pci_dev *dev, pci_power_t state, int enable);   /* Enable wake event */
    void (*shutdown) (struct pci_dev *dev);
};

#define PCI_DEVICE(vend,dev) \
	.vendor = (vend), .device = (dev), \
	.subvendor = PCI_ANY_ID, .subdevice = PCI_ANY_ID


// DDV: Does not need a body! Return an arbitrary integer.
int pci_dev_present(const struct pci_device_id *ids);

// DDV: Body for this function is defined in linux/pci.c
struct pci_dev *pci_get_class (unsigned int class, struct pci_dev *from);
 

/* Similar to the helpers above, these manipulate per-pci_dev
 * driver-specific data.  They are really just a wrapper around
 * the generic device structure functions of these calls.
 */
static inline void *pci_get_drvdata (struct pci_dev *pdev)
{
    return dev_get_drvdata(&pdev->dev);
}

static inline void pci_set_drvdata (struct pci_dev *pdev, void *data)
{
    dev_set_drvdata(&pdev->dev, data);
}

int pci_bus_read_config_byte (struct pci_bus *bus, unsigned int devfn, int where, u8 *val);
int pci_bus_read_config_word (struct pci_bus *bus, unsigned int devfn, int where, u16 *val);
int pci_bus_read_config_dword (struct pci_bus *bus, unsigned int devfn, int where, u32 *val);
int pci_bus_write_config_byte (struct pci_bus *bus, unsigned int devfn, int where, u8 val);
int pci_bus_write_config_word (struct pci_bus *bus, unsigned int devfn, int where, u16 val);
int pci_bus_write_config_dword (struct pci_bus *bus, unsigned int devfn, int where, u32 val);

static inline int pci_read_config_byte(struct pci_dev *dev, int where, u8 *val)
{
	return pci_bus_read_config_byte (dev->bus, dev->devfn, where, val);
}
static inline int pci_read_config_word(struct pci_dev *dev, int where, u16 *val)
{
	return pci_bus_read_config_word (dev->bus, dev->devfn, where, val);
}
static inline int pci_read_config_dword(struct pci_dev *dev, int where, u32 *val)
{
	return pci_bus_read_config_dword (dev->bus, dev->devfn, where, val);
}
static inline int pci_write_config_byte(struct pci_dev *dev, int where, u8 val)
{
	return pci_bus_write_config_byte (dev->bus, dev->devfn, where, val);
}
static inline int pci_write_config_word(struct pci_dev *dev, int where, u16 val)
{
	return pci_bus_write_config_word (dev->bus, dev->devfn, where, val);
}
static inline int pci_write_config_dword(struct pci_dev *dev, int where, u32 val)
{
	return pci_bus_write_config_dword (dev->bus, dev->devfn, where, val);
}

int pci_set_dma_mask(struct pci_dev *dev, u64 mask);
void pci_set_master(struct pci_dev *dev);


// DDV: Body for this function is defined in linux/pci.c
int pci_register_driver(struct pci_driver *);
// DDV: Body for this function is defined in linux/pci.c
void pci_unregister_driver(struct pci_driver *);
// DDV: Body for this function is defined in linux/pci.c
int pci_enable_device(struct pci_dev *dev);
// DDV: No body for this function
void pci_disable_device(struct pci_dev *dev);


#define HAVE_PCI_REQ_REGIONS	2
// DDV: Body for this function is defined in linux/pci.c
int pci_request_regions(struct pci_dev *, const char *);
// DDV: Body for this function is defined in linux/pci.c
void pci_release_regions(struct pci_dev *);
// DDV: Body for this function is defined in linux/pci.c
int pci_request_region(struct pci_dev *, int, const char *);
// DDV: Body for this function is defined in linux/pci.c
void pci_release_region(struct pci_dev *, int);


#include <asm/pci.h>

/* these helpers provide future and backwards compatibility
 * for accessing popular PCI BAR info */
#define pci_resource_start(dev,bar)   ((dev)->resource[(bar)].start)
#define pci_resource_end(dev,bar)     ((dev)->resource[(bar)].end)
#define pci_resource_flags(dev,bar)   ((dev)->resource[(bar)].flags)
#define pci_resource_len(dev,bar) \
	((pci_resource_start((dev),(bar)) == 0 &&	\
	  pci_resource_end((dev),(bar)) ==		\
	  pci_resource_start((dev),(bar))) ? 0 :	\
	  						\
	 (pci_resource_end((dev),(bar)) -		\
	  pci_resource_start((dev),(bar)) + 1))

#endif /* LINUX_PCI_H */
