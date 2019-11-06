/*
Exercise:
Write a C program segment to display the index of the smallest and the largest numbers in an array x of 20 integers.
Assume array x already has values assigned to each element.
 */

#include <stdio.h>

int main(void){
    int x[] = {44,88,1,18,73,36,52,43,12,3,43,17,98,48,77,56,79,62,47,55};
    int i, smallest = x[0], largest = x[0];

    for (i = 0; i < (sizeof(x) / sizeof(int)); i++){
        if (x[i] > largest)
            largest = x[i];
        if (x[i] < smallest)
            smallest = x[i];
    }
    printf("Smallest: %d | Largest: %d\n", smallest, largest);
    return 0;
}