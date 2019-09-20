/*
*   Author: Christian Bager Bach Houmann
*   Due date: 20/09/2019
*   Purpose: Taking an input given in seconds and converting to hours, minutes, and seconds.
*/
#include <stdio.h>
#define SECONDS_PER_MINUTE 60
#define SECONDS_PER_HOUR 3600

int main(void)
{
    int seconds, minutes, hours;

    /* Input */
    printf("Input a number of seconds => ");
    scanf(" %d", &seconds);

    /* Calculations */
    hours   = seconds / SECONDS_PER_HOUR;        seconds = seconds - (hours * SECONDS_PER_HOUR);
    minutes = seconds / SECONDS_PER_MINUTE;      seconds = seconds - (minutes * SECONDS_PER_MINUTE);
    seconds = seconds % SECONDS_PER_MINUTE;

    /* Hours output */
    if (hours > 0){
        printf("%d %s", hours, (hours > 1) ? "hours" : ((hours == 1) ? "hour" : ""));
    }

    /* Minutes output */
    if (minutes > 0){
        if (hours > 0){
            printf(", %d %s", minutes, (minutes > 1) ? "minutes" : ((minutes == 1) ? "minute" : ""));
        } else if (hours == 0) {
            printf("%d %s", minutes, (minutes > 1) ? "minutes" : ((minutes == 1) ? "minute" : ""));
        }
    } 

    /* Seconds output */
    if (seconds > 0) {
        if (hours > 0 || minutes > 0) {
            printf(", %d %s", seconds, (seconds > 1) ? "seconds" : ((seconds == 1) ? "second" : ""));
        } else if (hours == 0 && minutes == 0){
            printf("%d %s", seconds, (seconds > 1) ? "seconds" : ((seconds == 1) ? "second" : ""));
        }
    }

    return 0;
}
