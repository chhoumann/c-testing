/*
* Calculates ones TDEE.
* Uses Mifflin - St Jeor Formula. 
*/
#include<stdio.h>

int main (void) {
    /* Variable declaration */
    double weight, height, age, gender, bmr, tdee;
    int activity;

    /* Taking input */
    printf("Are you a male (1) or a female (0)? => ");                  scanf("%lf", &gender);
    printf("Please enter your age => ");                                scanf("%lf", &age);
    printf("Please enter your weight in kg => ");                       scanf("%lf", &weight);
    printf("Please enter your height in cm => ");                       scanf("%lf", &height);
    printf("Please enter your daily activity rated from 1 - 10 => ");   scanf("%d", &activity);
    
    /* Calculating BMR with Mifflin - St Jeor Formula */
    if (gender == 1)
    {
        bmr = 10 * weight + 6.25 * height - 5 * age + 5;
    } else if (gender == 0)
    {
        bmr = 10 * weight + 6.25 * height - 5 * age - 161;
    }

    /* Calculating TDEE based on activity input. */
    switch (activity)
    {
        case 1:     tdee = bmr * (1.2);                 break;
        case 2:     tdee = bmr * (1.2 + 0.077 * 2);     break;
        case 3:     tdee = bmr * (1.2 + 0.077 * 3);     break;
        case 4:     tdee = bmr * (1.2 + 0.077 * 4);     break;
        case 5:     tdee = bmr * (1.2 + 0.077 * 5);     break;
        case 6:     tdee = bmr * (1.2 + 0.077 * 6);     break;
        case 7:     tdee = bmr * (1.2 + 0.077 * 7);     break;
        case 8:     tdee = bmr * (1.2 + 0.077 * 8);     break;
        case 9:     tdee = bmr * (1.2 + 0.077 * 9);     break;
        case 10:    tdee = bmr * (1.2 + 0.077 * 10);    break;
    
        default:    return -1;     break;
    }

    /* Output */
    printf("********************\nYour Basic Metabolic Rate is: %.0lf calories.\n********************", bmr);
    printf("\nYour Total Daily Energy Expenditure is: %.0lf calories.\n********************", tdee);



    return 0;
}