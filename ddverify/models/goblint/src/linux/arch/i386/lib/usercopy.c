#include <asm/uaccess.h>
#include <ddverify/ddverify.h>
#include <ddverify/satabs.h>

inline int __get_user(int size, void *ptr)
{
 __CPROVER_HIDE:
    assert_context_process();

    return nondet_int();
}

inline int get_user(int size, void *ptr)
{
 __CPROVER_HIDE:
    assert_context_process();

    return nondet_int();
}

inline int __put_user(int size, void *ptr)
{
 __CPROVER_HIDE:
    assert_context_process();

    return nondet_int();
}

inline int put_user(int size, void *ptr)
{
 __CPROVER_HIDE:
    assert_context_process();

    return nondet_int();
}

inline unsigned long copy_to_user(void __user *to, const void *from, unsigned long n)
{
 __CPROVER_HIDE:
    assert_context_process();

    return nondet_ulong();
}

inline unsigned long copy_from_user(void *to, void __user *from, unsigned long n)
{
 __CPROVER_HIDE:
    assert_context_process();

   return nondet_ulong();
}
