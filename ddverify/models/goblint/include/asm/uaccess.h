#ifndef __i386_UACCESS_H
#define __i386_UACCESS_H

/*
 * User space memory access functions
 */
#include <linux/config.h>
#include <linux/errno.h>
#include <linux/string.h>
#include <asm/page.h>

#define VERIFY_READ 0
#define VERIFY_WRITE 1

/**
 * access_ok: - Checks if a user space pointer is valid
 * @type: Type of access: %VERIFY_READ or %VERIFY_WRITE.  Note that
 *        %VERIFY_WRITE is a superset of %VERIFY_READ - if it is safe
 *        to write to a block, it is always safe to read from it.
 * @addr: User space pointer to start of block to check
 * @size: Size of block to check
 *
 * Context: User context only.  This function may sleep.
 *
 * Checks if a pointer to a block of memory in user space is valid.
 *
 * Returns true (nonzero) if the memory block may be valid, false (zero)
 * if it is definitely invalid.
 *
 * Note that, depending on architecture, this function probably just
 * checks that the pointer is in the user space range - after calling
 * this function, memory access functions may still return -EFAULT.
 */
// #define access_ok(type,addr,size) (likely(__range_ok(addr,size) == 0))
int access_ok(int type, const void *addr, unsigned long size);


// DDV-TODO: get_user and put_user are defined as macros!!! if bug030 is fixed, this should be done here.

// DDV: Body is defined in arch/i386/lib/usercopy.c
int __get_user(int size, void *ptr);
// DDV: Body is defined in arch/i386/lib/usercopy.c
int get_user(int size, void *ptr);

// DDV: Body is defined in arch/i386/lib/usercopy.c
int __put_user(int size, void *ptr);
// DDV: Body is defined in arch/i386/lib/usercopy.c
int put_user(int size, void *ptr);

// DDV: Body is defined in arch/i386/lib/usercopy.c
unsigned long copy_to_user(void __user *to, const void *from, unsigned long n);
// DDV: Body is defined in arch/i386/lib/usercopy.c
unsigned long copy_from_user(void *to, void __user *from, unsigned long n);

#endif /* __i386_UACCESS_H */
