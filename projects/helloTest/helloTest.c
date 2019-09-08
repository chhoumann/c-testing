/*
    This is just a generic 'hello world'-kind-of-program.
*/

#include<stdio.h> // Preprocessor directive. Includes the header file stdio.h (standard input/output), which allows for the printf command below.
#include<string.h>

int main()
{
    // Defines str which will hold the name of the user.
    char str[100];

    // Prompts the user for their name.
    printf("What is your name?\nEnter it here: ");
    scanf("%s", str);

    // Prints a given name.
    printf("Hi, my name is %s.\n", str);
    return 0;
}