/*
Uses malloc to allocate space for 100 doubles.
Takes the allocated space and writes 100 random doubles into an array. Prints it.
Uses qsort to sort the numbers and prints them again.
*/

#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b);

int main(void){
    
    srand((int)__DATE__);
    double *dbl;
    int i;

    /* Memory allocation */
    dbl = (double *) malloc(800);
    for (i = 0; i <= 100; i++){
        dbl[i] = rand();
        printf("%.0lf\n", dbl[i]);
    }

    printf("\n\nDONE ALLOCATING\n\n");

    /* Sorting */
    qsort(dbl, 101, sizeof(double), cmpfunc);
    printf("\n\nDONE SORTING\n\n");

    /* Printing again to show that it's sorted */
    for (i = 0; i <= 100; i++)
        printf("%.0lf\n", dbl[i]);

    printf("\n\nDONE PRINTING\n\n");

    free(dbl);

    return 0;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(double*)a - *(double*)b );
}