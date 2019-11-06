#include <stdio.h>

int main(void){
    int i, j, k;
    int sum1 = 0, sum2 = 0;
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};

    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++) {
            printf("a[%1d,%1d] = %d\n", i, j, a[i][j]);
            sum1 += a[i][j];
        }
    printf("\n\n");
    
    for (k = 0; k < 2 * 3; k++) {
        printf("Element %1d = %d\n", k, *(&a[0][0] + k));
        sum2 += *(&a[0][0] + k);
    }
    printf("\n\n");
    
    printf("First method  | The sum is: %d\n", sum1);
    printf("Second method | The Sum is: %d\n", sum2);

    return 0;
}