/*
* This program can solve quadratic equations.
*/
#include <stdio.h>
#include <math.h>

void solveQuadraticEquation(void); /* Example of top-down programming. Defining the function, but writing it after main. This ensures that the compiler knows that it's there. */

int main (void) {
    solveQuadraticEquation();
}

/* Print the roots in a * x*x + b * x + c = 0. Prompt for coeffcients. */
void solveQuadraticEquation(void){
    double a, b, c, discriminant;

    printf("Enter the coefficients a, b, and c (a != 0): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
        printf("No roots\n");
    else if (discriminant == 0)
        printf("One root: %f\n", -b/(2*a));
    else
        printf("Two roots: %f and %f\n",
        (-b + sqrt(discriminant)) / (2*a),
        (-b - sqrt(discriminant)) / (2*a));

}