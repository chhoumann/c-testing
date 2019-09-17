/*
*   Testing selective control structures.
*   Preparation for lecture 3.
*/

#include<stdio.h>
#include<stdlib.h>

int main(void){

    double x,y;
    int is_x_smaller_than_y;

    printf("Enter two real numbers: ");
    scanf("%lf %lf", &x, &y);

    is_x_smaller_than_y = (x < y);
    
    /* Print result */
    if (is_x_smaller_than_y)
    {
        printf("%f is smaller than %f\n", x, y);
    } else
    {
        printf("%f is greater than or equal to %f\n", x, y);
    }
    
    return 0;
}