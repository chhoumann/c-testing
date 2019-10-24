#include <stdio.h>

int f (int p, int* q);
int g (int* r, int* s);


int main (void){
    int a = 1, b = 7;
    f(a+1, &b);
    return 0;
}

int f (int p, int* q){
    int c = p - *q;
    g(&c,q);
}

int g(int* r, int* s){
    int d = r;
}