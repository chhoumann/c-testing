#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char str1[] = "This is a string.";
    char str2[] = "This is another string.";
    
    for(int i = 0; ((str1[i] = (char)toupper(str1[i])) != '\0'); ++i);
    printf("%s", str1);

    /* It's possible to use atof() to convert a string to a float;
                            atoi() to convert a string to an int;
                            atol() to convert a string to a long;
                            atoll() to convert a string to a long long;
        Or use strtod() as string to double.
        strtof() as string to float.
        strtold() as string to long double.
    */ 

    return 0;
    
}