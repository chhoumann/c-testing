#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char str[80] = "Hello how are you -my name is -Christian";
    const char s[2] = "-";
    char *token;

    /* Get the first token */
    token = strtok(str, s);

    /* Walk through other tokens */
    while (token != NULL){
        printf(" %s\n", token);

        token = strtok(NULL, s);
    }

    return 0;
}