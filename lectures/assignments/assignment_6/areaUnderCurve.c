/*
*   Author: Christian Bager Bach Houmann
*   Due date: 30/10/2019
*   Purpose: Finding the area under the curve: g(x) = x^2 * sin(x) & f(x) = sqrt(4 - x^2).
*/
#include <stdio.h>
#include <math.h>

double h(double x);
double g(double x);
double trap(double a, double b, double n, double (*f)(double));

void main(void){
    printf("(1) Area under curve g(x):\n");
    for (int n = 2; n <= 128; n = n * 2)
        printf("| n: %3.d | => T: %lf|\n", n, trap(0, 3.14159, n, &g));

    printf("\n(2) Area under curve h(x):\n");
    for (int n = 2; n <= 128; n = n * 2)
        printf("| n: %3.d | => T: %lf|\n", n, trap(-2, 2, n, &h));
}

double g(double x){
    return (pow(x,2)*sin(x));
}

double h(double x){
    return sqrt(4 - pow(x,2));
}

double trap(double a, double b, double n, double (*fx)(double)){
    double  h   = (b - a) / n,
            sum = 0.0;

    for (double i = 1, x_val = a+h; i <= n-1; i++, x_val += h)
        sum += (*fx)(x_val);

    return h/2 * ((*fx)(a) + (*fx)(b) + 2 * sum);
}