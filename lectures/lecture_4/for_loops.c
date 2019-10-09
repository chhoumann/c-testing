/*
For loops look like so:

for (initExpression; continueExpression; updateExpression)
    command

A for loop could look like this:

var i;
for (i = 1; i<10; i++)
    printf("i = %d\n", i);

It's also possible to do:
#include <stdio.h>

int main(void) {
    long i = 0;

    for (; ;++i)
        printf("%ld: Hi there...\n",i);
}
*/

/*
* The comma-operator simply means that it's possible to have this:
for (i = 0, j = 2; i < j; i++, j++)
*/