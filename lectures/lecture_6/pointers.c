#include <stdio.h>

int main (void) {
    int a = 7, x = 8;
    double b = 7.89, y = 1.2;

    /* Således laves pointere. */
    int *pa = &a;
    double *pb = &b;
    
    /* For at tilgå værdien som pointeren peges på: */
    printf("%d\n", *pa); /* Her er pa en int pointer pga. stjernen */
    printf("%f\n", *pb);

    /* Måden hvorpå man assigner med pointers */
    *pa = x;
    *pb = y;


    printf("pa points at %d\n", *pa); /* Her er stjernen en de-referencing operator */
}