#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main(void) {
    /* '*' is (also) called the dereference operator */

    int count = 10, x;
    int * int_pointer;

    int_pointer = &count;
    x = *int_pointer;

    printf("count = %i, x = %i\n", count, x);

    int number = 0;
    int * pnumber = NULL;

    number = 10;
    pnumber = &number;
    printf("pnumber's value: %p\n", pnumber);

    printf("number's address: %p\n", &number);
    printf("pnumber's address: %p\n", (void*)&pnumber);

    printf("pnumber's size: %d bytes\n", (int)sizeof(pnumber));

    return 0;
}