/*
*   Assignment 3.1 from lecture 3.
*   Purpose: Decide whether a given point is within, outside, or on the circumference of a given circle.
*/

#include<stdio.h>
#include<math.h>

#define DELTA 0.05

int main (void){

    /* Variables declaration of radius, vectorLength, x coordinate, and y coordinate. */
    double r, x, y, vectorLength;

    /* Taking input */
    printf("Please enter the radius of the circle => ");        scanf(" %lf", &r);
    printf("Please enter the desired x and y coordinates => "); scanf(" %lf %lf", &x, &y);

    /* Calculation */
    vectorLength = sqrt((pow(x, 2) + pow(y, 2)));

    /* Deciding whether point is within circle or not */
    if (vectorLength > r)
    {
        printf("The point is outside the circle");
    } else if ((vectorLength == r) || ((vectorLength + DELTA) > r && (vectorLength - DELTA <r)))
    {
        printf("The vector is on the circumference of the circle");
    } else
    {
        printf("The point is inside the circle");
    }

    /* Prints vector length */
    printf("\nVectorlength: %lf", vectorLength);

    return 0;
}