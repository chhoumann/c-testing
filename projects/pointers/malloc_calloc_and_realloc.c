#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  /*
    MALLOC - the simplest standard library function that allocated memory at runtime.
        Need to include the stdlib.h header file to use it.
        You specify the number of bytes that you want allocated as the argument.
        Returns the address of the first byte of memory that is allocated.
        Because you get an address returned, a pointer is the only place to put it.

    int *pNumber = (int*)malloc(100); | Malloc returns an address, so you have to typecast to the given datatype.
        On my computer, the int type requires 4 bytes. This is not the case on every computer.
        Therefore I'd think that it could hold 25 integers, however this might not be the case on another computer.
        So instead:
        int *pNumber = (int*)malloc(sizeof(int) * 25);
            Doing that will ensure that you can hold exactly 25 integer on any system.

    If memory allocation fails, malloc returns a pointer with the value NULL.
        int *pNumber = (int*)malloc(25*sizeof(int));
        if(!pNumber)
            EXIT_FAILURE or something
    
    Always free the memory when you are done with it.
        free(pNumber);
        pNumber = NULL; A good idea to do after freeing.
  */


 /*
    CALLOC - Offers a couple of advantages over malloc.
        Allocated memory as a number of elements of a given size.
        Initializes the memory that is allocated so that all bytes are zero.
    
    Requires two argument values.
        Number of data items for which space is required.
        Size of each data item.
    
    calloc is declared in the stdlib.h header.

    int *pNumber = (int*)calloc(75, sizeof(int)); Created 75 ints and INITIALIZES THEM to zero.
  */

 /*
    REALLOC - Lets you reuse or extend memory that you previously allocated using malloc or calloc.

    Expects two argument values.
        A pointer containing an address that was previously returned by a call to malloc or calloc.
        The size in bytes of the new memory that you want allocated.

    Allocates the amount of memory you specify by the second argument.
        Transfers the contents of the previously allocated memory referenced
            by the pointer that you supply as the first argument to the newly allocated memory.
        Returns a void* pointer to the new memory or NULL if the operation fails.
        It ADDS to the memory amount. It PRESERVES the original contents of the original memory area.

 */

    /* ----- EXAMPLE ----- */
    char *str = NULL;

    /* Initial memory allocation */
    str = (char *)malloc(strlen("BagerBach") * sizeof(char));
    strcpy(str, "BagerBach");
    printf("String = %s, Address %p\n", str, str);

    /* Reallocating memory */
    str = (char *)realloc(str, sizeof(".com") * sizeof(char));
    strcat(str, ".com");
    printf("String = %s, Address = %p\n", str, str);

    free(str);
    str = NULL;

    return 0;

    /* ----- END OF EXAMPLE ----- */

  /*
    GUIDELINES
        Avoid allocating lots of small amounts of memory
            Allocating memory on the heap carries some overhead with it.
            Allocating many smaller blocks of memory will carry more overhead than allocating fewer larger blocks.
        Only hang on to the memory as long as you need it.
            As soon as you are finished with a block of memory on the heap, release the memory.
        Always ensure that you provide for releasing memory that you have allocated.
            Decide where in your code you will release the memory when you write the code that allocates it.
        Make sure you do not inadvertently overwrite the address of memory you have allocated on the heap before you have released it.
            Will cause a memory leak.
            Be especially careful when allocating memory with a loop.
  */
}