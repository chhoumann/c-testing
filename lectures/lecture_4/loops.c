/*
* There are three iterative control structures.
*   while loops
*   do-while loops
*   for loops
* 
* In relation to the for loop, we have the commma-operator.
* Generally, breaking out of loops: break, continue, and return.
* Nested loops.
*/

/*
This is a while loop:

while(logicalExpression)
    command

While the logical expression is true, perform the command. When false; exit.
*/

/*
This is a do-while loop:

do
    command
while (logicalExpression)

*/

/* 
* The following example has been given in a lecture video:

#include <stdio.h>

int main (void) {
    char answer;

    do {
        printf("Answer yes or no (y/n): ");
        scanf(" %c", &answer);
    } while(answer != 'y' && answer != 'n');

    printf("The answer is %s\n\n",
            answer == 'y' ? "yes" : "no");
}


* So this is a really simple program that asks for an input. It'll ask until you provide an answer. When an answer is given, it prints it.
*/

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
* break is used to break out of (the innermost) switch, while, do, or for loop.
* continue is used to end the command in a while, do, or for loop.
* return is used to interrupt, and return a result from a function.
*/