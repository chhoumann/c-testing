/*
*   Author: Christian Bager Bach Houmann
*   Due date: 20/09/2019
*   Purpose: Taking an input given in seconds and converting to hours, minutes, and seconds.
*/
#include <stdio.h>
#define SECONDS_PER_MNIUTE 60
#define SECOND_PER_HOUR 3600

int main(void)
{

    int seconds, minutes, hours;

    /* Input */
    printf("Input a number of seconds => ");
    scanf(" %d", &seconds);

    /* Calculations */
    hours = seconds / SECOND_PER_HOUR;
    minutes = seconds / SECONDS_PER_MNIUTE;
    seconds = seconds % SECONDS_PER_MNIUTE;

    /* Output */
    /* fix */

    return 0;
}
