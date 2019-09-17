/*
*   Preparation for lecture.
*   Rewrote the code in the lecture video to get a better understanding of it.
*/

#include <stdio.h>

int main (void){
    int month, numberOfDays, leapYear;

    printf("Enter a month - a number between 1 and 12: ");
    scanf("%d", &month);
    printf("Is it a leap year (1) or not (0): ");
    scanf("%d", &leapYear);

    switch (month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        numberOfDays = 31; break;
    case 4: case 6: case 9: case 11:
        numberOfDays = 30; break;
    case 2:
        if (leapYear)
        {
            numberOfDays = 29;
        } else
        {
            numberOfDays = 28;
        }
        break;
        default: exit(-1); /* Stop the program */
    }

    printf("There are %d days in month %d\n", numberOfDays, month);

    return 0;
}