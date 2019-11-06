#include<stdio.h>
#define TABLE_SIZE 6
#define SIZE 6

int noArrays(void){
    
    /* Declarations: */
    double table0, table1, table2, table3, table4, table5;

    /* Initializations: */
    table0 = 2 * 0.0;
    table1 = 2 * 1.0;
    table2 = 2 * 2.0;
    table3 = 2 * 3.0;
    table4 = 2 * 4.0;
    table5 = 2 * 5.0;

    /* Access - printing: */
    printf("%f, %f, %f, %f, %f, %f\n",
            table0, table1, table2, table3, table4, table5);

    return 0;
}

int arraysUsed(void){
    /* Declarations: */
    double table[TABLE_SIZE];
    int i;

    /* Initializations: */
    for(i = 0; i < TABLE_SIZE; i++)
        table[i] = (double)(2 * i);
    
    /* Access - printing: */
    for(i = 0; i < TABLE_SIZE; i++)
        printf("%f\n", table[i]);
    
    printf("\n");

    return 0;
}

int manipulatingArrays(void){
    double a[SIZE] = {1.0, 3.0, 0.0, -3.5, 0.0, 8.5};
    double *pa = &a[0];
    printf("%f is now ", a[3]);
    pa + 3; /* This points at the address holding the value -3.5. Usage: */
    *(pa + 3) = 7.0; /* Now the -3.5 is = 7.0 */
    printf("%f", a[3]);
}

int usingSizeofFunc(void){
    /* Declarations: */
    double table[TABLE_SIZE];
    int i;

    /* Initializations: */
    for(i = 0; i < TABLE_SIZE; i++)
        table[i] = (double)(2 * i);
    
    printf("Number of elements of table: %d\n", sizeof(table)/sizeof(double));
    /* Number of bytes in table divided by number of bytes in a double to get the amount of elements in a given table. */
}

int main(void){
    
    usingSizeofFunc();
    
    return 0;
}