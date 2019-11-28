#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char str1[] = "This is a string";
    char ch = 's';
    char *pGot_char = NULL;
    pGot_char = strchr(str1, ch);


    printf("The first '%c' in \"%s\" %s", ch, str1, 
            (pGot_char != NULL) ? "has been found in the string.\n" : "has not been found in the string.\n");

    /* It's possible to search for a string in a string using strstr() in almost the same way as above. */
}