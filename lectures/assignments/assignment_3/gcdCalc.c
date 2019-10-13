/*
*   Author: Christian Bager Bach Houmann
*   Due date: 14/10/2019
*   Purpose: Finding the GCD of two positive integers.
*/
#include <stdio.h>

int gcd(int a, int b)
{
    printf("Please enter two positive integers => ");
    scanf("%d %d", &a, &b);
    while (b > 0)
    {
        int remaining = a % b;
        a = b;
        b = remaining;
    }
    return a;
}

int main(void)
{

    int a, b;

    printf("The GCD is %d.\n", gcd(a, b));

    return 0;
}