#include<stdio.h>

int main (void){


    int firstVal = 40;
    int secondVal = 32;


    int divide = firstVal / secondVal;
    int modulo = firstVal % secondVal;

    printf("I could divide %d with %d a total of %d times with %d remaining.\n", firstVal, secondVal, divide, modulo);

    return 0;
}