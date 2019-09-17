/*
*   Preparation for lecture.
*   Rewrote the code in the lecture video to get a better understanding of it.
*/
#include <stdio.h>

int main(void) {

    /*  Initialization of variable */
    int grade;
    printf("Please enter the danish grade to be translated: ");
    scanf("%d", &grade);

    printf("The corresponding ECTS grade is: ");
    /*  Switch */
    switch (grade)
    {
    case 12:
        printf("A");
        break;
    case 10:
        printf("B");
        break;
    case 7:
        printf("C");
        break;
    case 4:
        printf("D");
        break;
    case 2:
        printf("E");
        break;
    case 0:
        printf("Fx");
        break;
    case -3:
        printf("F");
        break;
    default:
        printf("Please input a correct Danish 7 step grade.");
        break;
    }
    printf("\n");
    return 0;


}