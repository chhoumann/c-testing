/*
* page 252 programming exercise 6.
* Input two coordinates for a Cartesian plane and the program will tell you which plane you're in.
            |
            |
    QII     |   QI
            |
 ___________|___________
            |
    QIII    |   QIV
            |
            |
*/
#include<stdio.h>

int main (void){
    /* Initializing coordinate variables */
    double x_coord = 0.0, y_coord = 0.0;

    /* Taking input*/
    printf("Please input coordinates: ");
    scanf("%lf %lf", &x_coord, &y_coord);

    /* Locating */
    if ((x_coord > 0.0) && (y_coord > 0.0))
    {
        printf("\nYou are in square QI.\n");
    } else if ((x_coord < 0.0) && (y_coord > 0.0))
    {
        printf("\nYou are in square QII.\n");
    } else if ((x_coord < 0.0) && (y_coord < 0.0))
    {
        printf("\nYou are in square QIII.\n");
    } else if ((x_coord > 0.0) && (y_coord < 0.0))
    {
        printf("\nYou are in square QIV.\n");
    } else if ((x_coord == 0.0) && (y_coord == 0.0))
    {
        printf("\nYou are in the origin.\n");
    } else
    {
        printf("\nPlease enter valid coordinates.\n");
    }
    return 0;
}