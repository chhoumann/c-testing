#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char str1[] = "This is a string.";
    char str2[] = "This is another string.";
    char strTemp[100] = "";
    char strCopied[30] = "";


    printf("The length of \"%s\" is %d.\n", str1, strlen(str1));
    printf("String 1 and String 2 are %s", (strncmp(str1, str2, 0) ? "equal.\n" : "not equal.\n"));

    strncat(strTemp, str1, strlen(str1));
    strncat(strTemp, str2, strlen(str2));
    printf("If we combine \"%s\" and \"%s\" we get \"%s\".\n", str1, str2, strTemp);

    strcpy(strCopied, "Like this");
    printf("We can also copy a string to another. %s.", strCopied);

    return 0;
    
}