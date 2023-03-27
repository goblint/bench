// Example from https://github.com/cs50/spl/issues/24

#include "exception.h"
#include <stdio.h>

exception MyException;

int foo(int z)
{
    return z + 1;
}

void bar(int a, int b)
{
    fprintf(stderr, "Called with %d and %d\n", a, b);
    throw(MyException);
}

int main(int argc, string argv[])
{
    int x = 10;
    int y = 5;
    // Do stuff with x and y
    try
    { // setjmp is called in the expansion of `try`
        fprintf(stderr, "The value of x is %d\n", x);
        x = foo(y); // x is modified
        fprintf(stderr, "The value of x is %d\n", x);
        bar(x, y); // Throws an exception, which calls longjmp
    }
    catch (ANY)
    {
        // x might have been in a register but it's value has (maybe) been clobbered
        fprintf(stderr, "The value of x is %d\n", x);
    }
    endtry return 0;
}
