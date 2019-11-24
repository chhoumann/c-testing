#include <stdio.h>
#include <stdlib.h>
#define BASICPAYRATE 12

int main(void){
    int     c,
            hours_worked = 0,
            overtime     = 0;
    double  grosspay, netpay, temp,
            first300Tax  = 0.85,
            next150Tax   = 0.80,
            taxRest      = 0.75;


    /* Input */
    while (hours_worked <= 0){
        printf("Enter the amount of hours worked this week: "); scanf("%d", &hours_worked);

        if (hours_worked <= 0)
            printf("\nPlease enter an amount of hours worked greater than 0.\n");
    
        /* Flushing input */
        while ((c = getchar()) != '\n' && c != EOF);
    }

    /* Calculating overtime */
    if (hours_worked > 40)
        overtime = hours_worked - 40;
    grosspay = ((hours_worked - overtime) * BASICPAYRATE) + ((overtime * 1.5) * BASICPAYRATE);
    
    printf("\nGross pay: %.2lf", grosspay);

    /* Calculating taxes */
    if (grosspay > 450){
        temp = grosspay - 450;
        grosspay = grosspay - temp;
        netpay = temp * taxRest;
    }
    if (grosspay <= 450 && grosspay > 300){
        temp = grosspay - 300;
        grosspay = grosspay - temp;
        netpay += temp * next150Tax;
    }
    if (grosspay <= 300){
        netpay += grosspay * first300Tax;
    }

    printf("\nNet pay: %.2lf", netpay);

    return 0;    
}