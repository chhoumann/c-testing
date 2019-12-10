#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* If you have an array of 100 integers */
    int values[100];

    /* You can define a pointer valled valuesPtr which can be used to access the integers contained in this array */
    int *valuesPtr;

    /* To set valuesPtr to point to the first element in the values array, you write */
    valuesPtr = values; /* The C compiler treats the appearance of an array name without a subscript as a pointer to the array. */

    /* An equivalent way of doing the above ("valuesPtr = values;") is to: */
    valuesPtr = &values[0];

    /* The two expressions "ar[i]" and "*(ar+i)" are equivalent in meaning */
    /* Using an expression like "ar++" only works if ar is a pointer variable. */



    return 0;
}