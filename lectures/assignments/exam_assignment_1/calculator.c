/*
*   Author: Christian Bager Bach Houmann
*   Due date: 25/10/2019
*   Purpose: A simple calculator that keeps track of one double (the accumulator) which the user can manipulate using different operators. 
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void scan_data(char *operator, double *operand);
void do_next_op(char operator, double operand);
double run_calculator(void);
void flushInput(void);


double accumulator = 0.00;

int main(void){
    printf("Final value: %lf", run_calculator());

    return 0;
}

double run_calculator(void){
    char exit_cond = 'g';
    char operator;
    double operand;

    /* Runs until exit condition is met */
    while (exit_cond != 'q'){
        scan_data(&operator, &operand);

        /* Checks if user wants to exit, else prints result so far */
        (operator == 'q') ? (exit_cond = 'q') : printf("Result so far is %lf.\n", accumulator);
    }

    return accumulator;
}

void scan_data(char *operator, double *operand){
    /* Input */
    printf("Enter operator, and an optional operand: ");
    scanf(" %c", *&operator);

    /* If input operator is binary, asks for additional opperand input */
    if (*operator == '+' || *operator == '-' || *operator == '/' || *operator == '^' || *operator == '*'){
        scanf(" %lf", *&operand);
    }
    
    flushInput();
    do_next_op(*operator, *operand);
}

void do_next_op(char operator, double operand){
/* ****** BINARY OPERATORS ****** */ 
    /* Addition */
    if (operator == '+'){
        accumulator = accumulator + operand;
    }
    /* Subtraction */
    if (operator == '-'){
        accumulator = accumulator - operand;
    }

    /* Division */
    if (operator == '/'){
        accumulator = accumulator / operand;
    }

    /* Power */
    if (operator == '^'){
        accumulator = pow(accumulator, operand);
    }

    /* Multiplication */
    if (operator == '*'){
        accumulator = accumulator * operand;
    }

/* ****** UNARY OPERATORS ****** */
    /* Square root */
    if (operator == '#'){
        operand = 0.0;
        /* Cannot take square root of something negative, so only runs if number is 0 or above. */
        if (accumulator > 0){
            accumulator = sqrt(accumulator);    
        }
    }

    /* Change prefix of accumulator */
    if (operator == '%'){
        operand = 0.0;
        accumulator = -1 * accumulator;
    }

    /* Divide by 1 */
    if (operator == '!'){
        operand = 0.0;
        accumulator = 1 / accumulator;
    }
}


/* I did not make this. */
void flushInput(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}