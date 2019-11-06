#include <stdio.h>
#define N 4
#define M 3

int array_sum(int matrix[2][3], int rows, int columns);

int main(void) {
    int sum;
    int a[N][M] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

    sum = array_sum(a, N, M);
    printf("The sum is: %d\n", sum);

    return 0;
}

int array_sum(int matrix[][M], int rows, int columns){
    int i, j, sum = 0;;
    
    for (i = 0; i < rows; i++)
        for (j = 0; j < columns; j++)
            sum += matrix[i][j];
    
    return sum;
}