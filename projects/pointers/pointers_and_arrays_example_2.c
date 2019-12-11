#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    long multiple[] = {15L, 25L, 35L, 45L};
    long *p = multiple;
    int i;

    /* See that even though the long occupies 4 bytes we can still just add 1 to go to the next value in the array. */
    for (i = 0; i < sizeof(multiple) / sizeof(multiple[0]); ++i)
        printf("Address p+%d(&multiple[%d]): %llu       *(p+%d)  value: %d\n",
                           i,          i, (unsigned long long)(p+i), i, *(p+i));

    printf("\n  Type long occupies %d bytes\n", (int)sizeof(long));
    
    return 0;
}