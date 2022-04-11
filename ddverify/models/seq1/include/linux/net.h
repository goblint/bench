#ifndef _LINUX_NET_H
#define _LINUX_NET_H

struct socket {
    const struct proto_ops	*ops;
    struct sock		        *sk;
};

struct proto_ops {
    int		(*shutdown)  (struct socket *sock, int flags);
};

extern int   	     kernel_sendmsg(struct socket *sock, struct msghdr *msg,
				    struct kvec *vec, size_t num, size_t len);
extern int   	     kernel_recvmsg(struct socket *sock, struct msghdr *msg,
				    struct kvec *vec, size_t num,
				    size_t len, int flags);

#endif	/* _LINUX_NET_H */
