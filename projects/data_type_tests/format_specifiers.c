/* In no way comprehensive */

#include<stdio.h>

int main (void){
    int     intergerVar = 100;
    float   floatingVar = 331.79;
    double  doubleVar =8.44e+11;
    char    charVar = 'W';

    _Bool   boolVar = 0;

    printf("IntergerVar = %i\n", intergerVar);
    printf("floatingVar = %f\n", floatingVar);
    printf("doubleVar = %e\n", doubleVar);
    printf("doubleVar = %g\n", doubleVar);
    printf("doubleVar = %lf\n", doubleVar);
    printf("charVar = %c\n", charVar);

    printf("boolVar = %i\n", boolVar);

    return 0;
}