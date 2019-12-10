#include <stdio.h>
#include <stdlib.h>

int array_sum(int array[], const int n) /* Could also do "int* array" instead of "int array[]" */ {
    int sum = 0, *ptr;
    int * const arrayEnd = array + n; /* Address of pointer cannot be changed (because it's const) */
    /* printf("\nArrayEnd: %d\nArray: %d\n", arrayEnd, array);
    The above line prints arrayEnd to be = 6422276 and array to be = 6422236, which is a difference of 40.
    There are 10 ints which all take 4 bytes (sizeof(int)), which is a total of 40. Therefore the following
    for loop will iterate through the addresses in that exact range and add the ints to the sum. Pretty cool! 
    
    arrayEnd points to the end-addresss of the array.*/

    for (ptr = array; ptr < arrayEnd; ++ptr)
        sum += *ptr; /* Dereferencing because we need the value, not the address. */

    /* ----- ALTERNATIVE IF YOU USE "int *array" INSTEAD OF "int array[]" -----
    int sum = 0;
    int * const arrayEnd = array + n;

    for ( ; array < arrayEnd; ++array)
        sum += *array; 
        
    ----- Shorter than the above method. -----
    */
    
    return sum;
}

int main(void) {
    /* The real power of using pointers to arrays comes into play when you want to sequence through the elements of an array. */
    int iar[5] = {1, 2, 3, 4, 5};
    int * piar = iar;

    for (int i = 0; i < 5; i++)
        printf("Value: %d\n", *(piar + i));

    /* ----- Using array_sum example ----- */
    int values[10] = {3, 7, -9, 3, 6, -1, 7, 9, 1, -5};
    printf("The sum is: %d\n", array_sum(values, 10)); /* If you want to be able to change the amount of values in the array but not have to change
                                                        the 10 in the function call all the time you can use "sizeof(values) / sizeof(int)".
                                                        You also don't have to specify that there is 10 values in [x], so you can remove that
                                                        and easily add values in the brackets without hassle. */

    return 0;
}