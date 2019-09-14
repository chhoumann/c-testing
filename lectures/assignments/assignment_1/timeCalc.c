/*
*   Author: Christian Bager Bach Houmann
*   Due date: 13/09/2019
*   Purpose: Taking an input given in seconds and converting to weeks, days, hours, minutes, and seconds.
*/

#include<stdio.h>

int main(void) {

    /* Declaring the variables */
    int seconds, minutes, hours, days, weeks;
    
    /* Taking an input */
    printf("Please enter the amount of seconds => ");
    scanf("%d", &seconds);

    /* Calculations */
    minutes = seconds / 60;
    seconds = seconds % 60;

    hours = minutes / 60;
    minutes = minutes % 60;

    days = hours / 24;
    hours = hours % 24;

    weeks = days / 7;
    days = days % 7;

    /* Outputting the calculations */
    printf("%d weeks, %d days, %d hours, %d minutes, %d seconds.", weeks, days, hours, minutes, seconds);

    return 0;
}