#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int numer_to_test, remainder;

    printf("Enter your number to be tested: ");
    scanf("%d", &numer_to_test);

    remainder = numer_to_test % 2;

    if (remainder == 0)
        printf("The number is even.\n");
    else
        printf("The number is odd.\n");
    
    return 0;
}