                               /* An example using the static storage class */
                        /* Not using static would result in it printing 3 ten times */
/* This is because when a variable is static it keeps its value between activations of the block it is in. */
#include <stdio.h>

int accumulating_f (int input){
    int result;
    static int previous_result = 1;

    if (previous_result == 1)
        result = input;
    else
        result = previous_result * input;
    
    previous_result = result;
    return result;
}

int main(void){
    int x = 3;
    for (int i = 0; i < 10; i++)
        printf("accumulating_f(%d) = %d\n", x, accumulating_f(x));

    return 0;

}