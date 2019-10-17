/*
*   Author: Christian Bager Bach Houmann
*   Due date: 14/10/2019
*   Purpose: Solving a given quadratic equation. 
*/
#include <stdio.h>
#include <math.h>

double discriminantFinder();
double firstRoot();
double secondRoot();
double solveQuadraticEquation();

int main() {
    double a, b, c;

    /* Repeatedly asks user for an input, until input is 0 0 0.
       Also makes sure that a != 0. */
    do{
        printf("Enter coefficients a, b, and c =>  ");
        scanf("%lf %lf %lf", &a, &b, &c);

        
        if (a == 0 && (b != 0 && c != 0))
            printf("Unable to solve equation - a must be > 0.");
        else if (a != 0)
            solveQuadraticEquation(a, b, c); 

        flushInput();
    } while (a != 0 || b != 0 || c != 0);

}

double solveQuadraticEquation(double a, double b, double c){
    double root1, root2, discriminant;
    root2        =  secondRoot(a, b, c);
    discriminant =  discriminantFinder(a, b, c);

    /* Checks how many roots there are and then prints the roots - if any.
       Only calls functions if necessary. */
    if (discriminant < 0)
        printf("No roots.\n");
    else if (discriminant == 0){
        printf("One root: %.2f.\n", firstRoot(a, b, c));
    } else if (discriminant > 0){
        printf("Two roots: %.2f and %.2f.\n", firstRoot(a, b, c), secondRoot(a, b, c));
    }
}

double discriminantFinder(double a, double b, double c){
    return (b * b - 4 * a * c);
}

double firstRoot(double a, double b, double c){
    double root1, discriminant;
    discriminant = discriminantFinder(a, b, c);

    /* Solves for and returns root1. */
    if (discriminant == 0){
        return root1 = -b/(2*a);
    } else {
        return root1 = (-b + sqrt(discriminant))/(2*a);
    }

}

double secondRoot(double a, double b, double c){
    double root2, discriminant;
    discriminant = discriminantFinder(a, b, c);

    /* Solves for and returns root2. */
    root2 = (-b - sqrt(discriminant))/(2*a);
    return root2;
}

void flushInput(void) {
    int c;
    while ((c = getchar()) != "\n" && c != EOF);
}