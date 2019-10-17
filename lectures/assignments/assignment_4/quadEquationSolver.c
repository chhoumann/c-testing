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

    printf("Enter coefficients a, b, and c =>  ");
    scanf("%lf %lf %lf", &a, &b, &c);
    solveQuadraticEquation(a, b, c);  

}

double discriminantFinder(double a, double b, double c){
    double discriminant;

    discriminant = b * b - 4 * a * c;

    return discriminant;
}

double firstRoot(double a, double b, double c){
    double root1, discriminant;
    discriminant = discriminantFinder(a, b, c);

    if (discriminant == 0){
        return root1 = -b/(2*a);
    } else {
        return root1 = (-b + sqrt(discriminant))/(2*a);
    }

}

double secondRoot(double a, double b, double c){
    double root2, discriminant;
    discriminant = discriminantFinder(a, b, c);

    root2 = (-b - sqrt(discriminant))/(2*a);
    return root2;
}

double solveQuadraticEquation(double a, double b, double c){
    double root1, root2, discriminant;
    root2        =  secondRoot(a, b, c);
    discriminant =  discriminantFinder(a, b, c);

    if (discriminant < 0)
        printf("No roots.\n");
    else if (discriminant == 0){
        printf("One root: %.2f.\n", firstRoot(a, b, c));
    } else if (discriminant > 0){
        printf("Two roots: %.2f and %.2f.\n", firstRoot(a, b, c), secondRoot(a, b, c));
    }
}