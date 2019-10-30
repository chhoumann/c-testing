#include <stdio.h>

int is_even(int i){
    return i%2 == 0;
}

int main(void){
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (is_even(n))
        printf("%d is even\n", n);
    else
        printf("%d is uneven\n", n);

    return 0;
}

