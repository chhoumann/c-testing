#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIE_MAX_EYES 6

int* roll_multiple_dies(int *rolls, int n);

int roll_die(void){
    return (rand() % DIE_MAX_EYES) + 1;
}

int main(void){
    int i, n, run = 1;
    srand(time(NULL));

    printf("Enter amount of die to throw (n > 1) => "); scanf(" %d", &n);
    int rolls[n];
    int* ptr = roll_multiple_dies(rolls, n);
    
    
    for(i = 0; i < n; i++)
        printf("Roll %d: %d\n", i+1, ptr[i]);


    return 0;
}

int* roll_multiple_dies(int *rolls, int n){
    for (int i = 0; i < n; i++)
        rolls[i] = roll_die();
        
    return rolls;
}