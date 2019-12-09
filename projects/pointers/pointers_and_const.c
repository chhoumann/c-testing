#include <stdio.h>
#include <stdio.h>

int main(void) {
    /* With pointers, we have to consider two things when using the const modifier.
        Whether the pointer will be changed
        Whether the value that the pointer points to will be changed. */
    
    /* You can use the const keyword when you declare a pointer to indicate that the value pointed to must not be changed. */

    long value = 9999L;
    const long *pvalue = &value; /* defines a pointer to be a constant. */
    /* Now the compiler will check for any statements that attempt to modify the value pointed to by pvalue and flag such statements as an error. */

    /* *pvalue = 8888L;  Will give error. */
    value = 7777L; /* We can, however, do this. */

    long number = 8888L;
    pvalue = &number; /* It's also OK to change the address in pvalue - just not the value. */

    int count = 43;
    int *const pcount = &count; /* Defines a constant pointer - the pointer itself cannot change its value. */

    int item = 34;
    /* pcount = &item; - Error. BUT WE CAN STILL CHANGE THE VALUE OF PCOUNT: *pcount = 345; is OK.*/

    /*
    const int * ..... // value cannot be changed
    int * const ..... // pointer address cannot be changed
    */

   const int *const pitem = &item; /* Cannot change address stored in pitem and cannot use pitem to modify what it points to.
                                        However - can still change value of 'item'. */

    return 0;
}