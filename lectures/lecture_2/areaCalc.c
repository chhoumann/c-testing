#include<stdio.h> /* Both #include and #define are preprocesser directives. */
#define PI 3.14159

int main(void){

    /* Initializes the variables. */
    double radius = 5.0;
    /* Uses the previously initialized radius and the constant PI to calculate the area of a circle with a radius of 5. */
    double area = radius * radius * PI;

    /* Prints the calculated area. */
    printf("%f\n", area);

    return 0;
}