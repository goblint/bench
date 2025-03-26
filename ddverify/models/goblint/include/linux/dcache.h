#ifndef __LINUX_DCACHE_H
#define __LINUX_DCACHE_H

struct dentry {
    struct inode *d_inode;		/* Where the name belongs to - NULL is
					 * negative */
};

#endif	/* __LINUX_DCACHE_H */
