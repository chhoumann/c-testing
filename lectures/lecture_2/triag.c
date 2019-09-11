#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    double p1_x, p1_y, p2_x, p2_y, p3_x, p3_y;
    double circumference, side_1_2, side_2_3, side_3_1;


    printf("******************************\n");
    printf("Enter first point: ");
    scanf(" %lf %lf", &p1_x, &p1_y);

    printf("Enter second point: ");
    scanf(" %lf %lf", &p2_x, &p2_y);

    printf("Enter third point: ");
    scanf(" %lf %lf", &p3_x, &p3_y);
    printf("******************************");


    side_1_2 = sqrt((p1_x - p2_x) * (p1_x - p2_x) + (p1_y - p2_y) * (p1_y - p2_y));
    side_2_3 = sqrt((p2_x - p3_x) * (p2_x - p3_x) + (p2_y - p3_y) * (p2_y - p3_y));
    side_3_1 = sqrt((p3_x - p1_x) * (p3_x - p1_x) + (p3_y - p1_y) * (p3_y - p1_y));
    circumference = side_1_2 + side_2_3 + side_3_1;

    printf("\nThe circumference of the triangle is: %lf\n", circumference);
    printf("******************************\n");



    return EXIT_SUCCESS;
}