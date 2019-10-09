/*
* goto. (usually) don't use this.
* break is used to break out of (the innermost) switch, while, do, or for loop.
* continue is used to end the command in a while, do, or for loop. Or, in other words, jump to the next loop cycle.
* return is used to interrupt, and return a result from a function.

The following is an example of the usage of these.
*/
#include <stdio.h>

int main (void) {
    int i = 0;

    while (i < 10)
    {
        ++i;
        if (i == 8) break;
        if (i % 2 == 0) continue;
        printf("i = %d\n", i);
    }
    printf("Done\n");
}