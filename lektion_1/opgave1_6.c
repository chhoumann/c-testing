#include <stdio.h>

int main(void)
{
    float first_number, xxx, sidsteTal; // 3 float variables defined.

    printf("Give me three: "); // Printing a cue for the user to interact with the machine.

    scanf("%f%f%f", &first_number, &xxx, &sidsteTal); // Taking the user's inputs.
    printf("The result: %f\n", (first_number + xxx + sidsteTal) / 3.0); // Printing the sum of the three variables, divided by three.
    scanf("%f%f%f", &first_number, &xxx, &sidsteTal); // I didn't know how to pause the program (in order for me to look at the output), so I simply added this function to do so.
    return 0;
}