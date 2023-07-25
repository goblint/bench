#include <stdio.h>

int main() {
    int num = 42;

    // Simple if statement
    if (num > 0) {
        printf("1) The number is positive.\n");
    }

    // If-else statement
    if (num > 0) {
        printf("2) The number is positive.\n");
    } else {
        printf("3) The number is either zero or negative.\n");
    }

    // If-elseif statement
    if (num > 0) {
        printf("4) The number is positive.\n");
    } else if (num < 0) {
        printf("5) The number is negative.\n");
    } else {
        printf("6) The number is zero.\n");
    }

    return 0;
}
