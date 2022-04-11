#ifndef _SOCK_H
#define _SOCK_H

#include <linux/list.h>
#include <linux/timer.h>
#include <linux/cache.h>
#include <linux/module.h>
//#include <linux/lockdep.h>
#include <linux/netdevice.h>
#include <linux/skbuff.h>	/* struct sk_buff */
//#include <linux/security.h>


#define SHUTDOWN_MASK	3
#define RCV_SHUTDOWN	1
#define SEND_SHUTDOWN	2

#define SOCK_SNDBUF_LOCK	1
#define SOCK_RCVBUF_LOCK	2
#define SOCK_BINDADDR_LOCK	4
#define SOCK_BINDPORT_LOCK	8

struct sock {
    gfp_t			sk_allocation;
};

struct socket *SOCKET_I(struct inode *inode);

#endif	/* _SOCK_H */
