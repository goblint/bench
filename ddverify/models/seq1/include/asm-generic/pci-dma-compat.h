/* include this file if the platform implements the dma_ DMA Mapping API
 * and wants to provide the pci_ DMA Mapping API in terms of it */

#ifndef _ASM_GENERIC_PCI_DMA_COMPAT_H
#define _ASM_GENERIC_PCI_DMA_COMPAT_H

void * pci_alloc_consistent(struct pci_dev *hwdev, size_t size,
			    dma_addr_t *dma_handle);

void pci_free_consistent(struct pci_dev *hwdev, size_t size,
			 void *vaddr, dma_addr_t dma_handle);

dma_addr_t pci_map_single(struct pci_dev *hwdev, void *ptr, size_t size, int direction);
void pci_unmap_single(struct pci_dev *hwdev, dma_addr_t dma_addr, size_t size, int direction);

dma_addr_t pci_map_page(struct pci_dev *hwdev, struct page *page,
			unsigned long offset, size_t size, int direction);
void pci_unmap_page(struct pci_dev *hwdev, dma_addr_t dma_address,
		    size_t size, int direction);
#endif
