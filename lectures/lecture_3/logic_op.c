#include <stdio.h>

int main (void){
    /*  Changing x to be larger than y makes it so that (z=2) doesn't get evaluated, and therefore doesn't change value. */
    int x = 8, y = 7, z = 10;
    int r1;

    r1 = x < y && (z = 2);

    printf("r1 = %d\n", r1);
    printf("z = %d\n", z);
}