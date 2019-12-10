#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Type name void means absence of any type.
    A pointer of type void* can contain the address of a data item of any type. */

    /* The void pointer must, however, first be explicitly cast to another pointer type before it is dereferenced. */
    int i = 10;
    float f = 2.34;
    char ch = 'k';

    void *vptr;

    vptr = &i;
    printf("Value of i = %d\n", *(int *)vptr);

    vptr = &f;
    printf("Value of f = %.2f\n", *(float *)vptr);

    vptr = &ch;
    printf("Value of ch = %c\n", *(char *)vptr);

    return 0;
}