#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    /* Doing the following allocate a fixed amount of memory.
    int dataArray[1000]; */

    /* However, using dynamic memory allocation you can allocate only the exact amount that you need. */
    /* You can store memory on the heap or the stack.
        Stack:
            Function arguments and local variables in function are stored here.
            When the execution of a function ends, the space allocated to store arguments and local variables is freed.
        Heap:
            The memory in the heap is different in that it is controlled by you.
            When you allocate memory on the heap, it is up to you to keep track of when the memory that you have allocated is not longer required.
            You must free the space you have allocated to allow it to be reused.
        */

    return 0;
}