#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void) {
    
    double m, n;

    printf("Enter the length of the two sides: ");
    scanf("%lf %lf", &m, &n);

    double side1 = m*m-n*n;
    double side2 = 2*m*n;
    double hypotenuse = m*m+n*n;

    printf("Side 1: %lf. Side 2: %lf. Hypotenunse: %lf", side1, side2, hypotenuse);
    
    return 0;
}