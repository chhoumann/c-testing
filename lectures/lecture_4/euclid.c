#include <stdio.h>
int gcd(int large, int small) {
    int remainder;
    while (small > 0)
    {
        remainder = large % small;
        large = small;
        small = remainder;
        printf("%d ", small);
    }
    return large;
}


int main(void) {
    int i, j, small, large, remainder;

    printf("Enter two non-negative integers: ");
    scanf("%d %d", &i, &j);

    small = i <= j ? i : j;
    large = i <= j ? j : i;

    printf("\nGCD of %d and %d is %d\n\n", 
            i, j, gcd(large, small));

    return 0;    
}