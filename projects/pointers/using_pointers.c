#include <stdio.h>
#include <stdlib.h>

int main(void) {
    long num1 = 0L;
    long num2 = 0L;
    long *pnum = NULL;

    pnum = &num1;   /* Get address of num1 */
    *pnum = 2L;     /* Set num1 to 2 */
    ++num2;         /* Increment num2 */
    num2 += *pnum;  /* Add num1 to num2 */

    pnum = &num2;   /* Get address of num2 */
    ++*pnum;        /* Increment num2 indirectly */

    printf("num1 = %ld\nnum2 = %ld\n*pnum = %ld\n*pnum + num2 = %ld\n", num1, num2, *pnum, *pnum+num2);

    /* ----- Pointers and scanf ----- */
    int value = 0;
    int *pvalue = &value; /* Set pointer to refer to value */

    printf("Enter an integer: ");
    scanf( "%d", pvalue); /* Read into value with pointer - no need for &value. */

    printf("You entered %d.\n", value); /* Output the value entered. */

    /* !!! ----- DO NOT DEREFERENCE AN UNINITIALIZED POINTER ----- !!! */
    /* Before using a pointer, it should be assigned a memory location that has already been allocated.
    #---- Either assign the address of an existing variable to the pointer.
    #---- Or you can use the malloc() function to allocate memory first. */
    /* ----- TESTING FOR NULL ----- */
    /* It's a good idea to do: */
    if (!pvalue)
        /* do something - if this is true you can dereference the pointer. If it is NOT == NULL. */

    return 0;
}