#ifndef __ARCH_I386_ATOMIC__
#define __ARCH_I386_ATOMIC__

#include <ddverify/satabs.h>

typedef int atomic_t;

#define ATOMIC_INIT(i)	{ (i) }

/**
 * atomic_read - read atomic variable
 * @v: pointer of type atomic_t
 * 
 * Atomically reads the value of @v.
 */ 
#define atomic_read(v)	(*v)

/**
 * atomic_set - set atomic variable
 * @v: pointer of type atomic_t
 * @i: required value
 * 
 * Atomically sets the value of @v to @i.
 */
#define atomic_set(v,i)	(*v) = i

/**
 * atomic_add - add integer to atomic variable
 * @i: integer value to add
 * @v: pointer of type atomic_t
 * 
 * Atomically adds @i to @v.
 */
static __inline__ void atomic_add(int i, atomic_t *v)
{
    (*v) = (*v) + i;
}

/**
 * atomic_sub - subtract the atomic variable
 * @i: integer value to subtract
 * @v: pointer of type atomic_t
 * 
 * Atomically subtracts @i from @v.
 */
static __inline__ void atomic_sub(int i, atomic_t *v)
{
    (*v) = (*v) - i;
}

/**
 * atomic_inc - increment atomic variable
 * @v: pointer of type atomic_t
 * 
 * Atomically increments @v by 1.
 */ 
static __inline__ void atomic_inc(atomic_t *v)
{
    (*v)++;
}

/**
 * atomic_dec - decrement atomic variable
 * @v: pointer of type atomic_t
 * 
 * Atomically decrements @v by 1.
 */ 
static __inline__ void atomic_dec(atomic_t *v)
{
    (*v)--;
}

/**
 * atomic_dec_and_test - decrement and test
 * @v: pointer of type atomic_t
 * 
 * Atomically decrements @v by 1 and
 * returns true if the result is 0, or false for all other
 * cases.
 */ 
static __inline__ int atomic_dec_and_test(atomic_t *v)
{
    int ret;

 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
    (*v)--;
    if ((*v) == 0) {
	ret = 1;
    } else {
	ret = 0;
    };
    __CPROVER_atomic_end();
    
    return ret;
}
 
/**
 * atomic_inc_and_test - increment and test 
 * @v: pointer of type atomic_t
 * 
 * Atomically increments @v by 1
 * and returns true if the result is zero, or false for all
 * other cases.
 */ 
static __inline__ int atomic_inc_and_test(atomic_t *v)
{
    int ret;

 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
    (*v)++;
    if ((*v) == 0) {
	ret = 1;
    } else {
	ret = 0;
    };
    __CPROVER_atomic_end();
    
    return ret;
}

/**
 * atomic_add_negative - add and test if negative
 * @v: pointer of type atomic_t
 * @i: integer value to add
 * 
 * Atomically adds @i to @v and returns true
 * if the result is negative, or false when
 * result is greater than or equal to zero.
 */ 
static __inline__ int atomic_add_negative(int i, atomic_t *v)
{
   int ret;

 __CPROVER_HIDE:
    __CPROVER_atomic_begin();
    (*v) = (*v) + i;
    if ((*v) < 0) {
	ret = 1;
    } else {
	ret = 0;
    }
    __CPROVER_atomic_end();
    
    return ret;
}   

/**
 * atomic_add_return - add and return
 * @v: pointer of type atomic_t
 * @i: integer value to add
 *
 * Atomically adds @i to @v and returns @i + @v
 */
static __inline__ int atomic_add_return(int i, atomic_t *v)
{
    return (*v) + i;
}

static __inline__ int atomic_sub_return(int i, atomic_t *v)
{
    return (*v) - i;
}

#define atomic_inc_return(v)  (atomic_add_return(1,v))
#define atomic_dec_return(v)  (atomic_sub_return(1,v))

#endif
