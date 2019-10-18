#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Exercise 1. p. 143 */
double exa(double u, double v, double w);
double exb(double x, double y);
double exc(double x, double y);
double exd(double x, double y, double w, double z);

void main(void){
    /* Not calling any of them on purpose. */
}

double exa(double u, double v, double w){
    double result = (sqrt(u + v) * pow(w, 2));
}

double exb(double x, double y){
    double result = (log(pow(x, y)));
}

double exc(double x, double y){
    double result = (sqrt(pow((x-y),3)));
}

double exd(double x, double y, double w, double z){
    double result = abs((x*y)-(w/z));
}
