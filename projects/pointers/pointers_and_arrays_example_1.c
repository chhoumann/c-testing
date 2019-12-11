/* ----- Example of pointer arithmetic. ----- */

#include <stdio.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char multiple[] = "a string";
    char *p = multiple;

  /*
    Loops through the whole string showing two methods of printing the actual character and 
    two methods of showing the memory address of the character in the string.
    This is a great example of pointer arithmetic because it shows that you can just dereference
    the pointer and add the 'i' number for the character that you want to access.
  */
    for (int i = 0; i < strnlen(multiple, sizeof(multiple)); ++i)
        printf("Multiple[%d] = %c *(p+%d) = %c &multiple[%d] = %p p+%d = %p\n",
                i, multiple[i], i, *(p+i), i, &multiple[i], i, p+i);
    
    return 0;
}