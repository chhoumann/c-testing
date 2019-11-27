#include <stdio.h>


/* Precondition: n >= 0 */
long fib(int n) {
    long small, large, temp, i;

    for (small = 0, large = 1, i = 0;
         i < n;
         i++){
             temp = small;
             small = large;
             large = large + temp;
         }
    return small;
}

int main(void) {
    int i;

    for (i = 0; i < 100; i++)
        printf("Fib(%i) = %li\n", i, fib(i));
    return 0;
}