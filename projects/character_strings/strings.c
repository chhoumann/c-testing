#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define CONSTANTSTRING "My name is Christian"

int main(void) {
    char str1[] = "Lorem";
    char str2[] = "Ipsum";
    unsigned int count = 0;
    const char constantString[25] = "Another constant string. These are useful for error messages.";

    while (str1[count] != '\0')
        ++count;

    printf("The length of the string \"%s\" is %d characters.\n", str1, count);

    count = 0;
    while (str2[count] != '\0')
        ++count;
    
    printf("The length of the string \"%s\" is %d characters.\n", str2, count);
    printf("\n%s", CONSTANTSTRING);

    /* Or just use strlen */

    return 0;
}