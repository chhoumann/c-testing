/*
* Programming exercise 2 page 275.
* Purpose:  Write a program that displays a cm-to-inch conversion table with 10-cm intervals.
*           The smallest and largest numbers in the table are input values.
*           One centimeter = 0.3937 inch.
*/
#include <stdio.h>
#define INCHCALC 0.3937

int main (void) {
    double  i, j, k, small, large, tableVal;
    int     count;

    printf("Please enter two inch values => ");
    scanf("%lf %lf", &j, &k);

    small = j <= k ? j : k;
    large = k <= j ? j : k;    

    for(i=small, count = 0; i < large; i += 10, count++){
        tableVal = (small + (count * 10)) * INCHCALC;
        printf("%.1lf cm is %.1lf inches\n", i, tableVal);
    }

    printf("%.1lf cm is %.1lf inches", large, large * INCHCALC);
    
    return 0;
}