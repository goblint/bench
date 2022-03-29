#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/if_arp.h>

struct net_device *alloc_netdev_mqs(int sizeof_priv, const char *name,
                                    unsigned char name_assign_type,
                                    void (*setup)(struct net_device *),
                                    unsigned int txqs, unsigned int rxqs) {
  struct net_device *dev;
  size_t alloc_size;
  struct net_device *p;

  alloc_size = sizeof(struct net_device);
  p = kzalloc(alloc_size, GFP_KERNEL | __GFP_NOWARN | __GFP_REPEAT);
  if (!p)
    return NULL;
  
  dev = p;

  setup(dev);
  return dev;
}

void ether_setup(struct net_device *dev)
{
  dev->header_ops		= &eth_header_ops;
  dev->type		= ARPHRD_ETHER;
  dev->hard_header_len 	= ETH_HLEN;
  dev->mtu		= ETH_DATA_LEN;
  dev->addr_len		= ETH_ALEN;
  dev->tx_queue_len	= 1000;	/* Ethernet wants good queues */
  dev->flags		= IFF_BROADCAST|IFF_MULTICAST;
  dev->priv_flags		|= IFF_TX_SKB_SHARING;

  memset(dev->broadcast, 0xFF, ETH_ALEN);
}

struct net_device *alloc_etherdev_mqs(int sizeof_priv, unsigned int txqs,
                                      unsigned int rxqs)
{
  return alloc_netdev_mqs(sizeof_priv, "eth%d", NET_NAME_UNKNOWN,
        ether_setup, txqs, rxqs);
}