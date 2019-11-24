#include <stdio.h>
#include <stdlib.h>

int main(void){
    double  value1, value2;
    char    operator;

    printf("Type in your expression.\n"); scanf("%lf %c %lf", &value1, &operator, &value2);

    switch (operator)
    {
    case '+':
        printf("%.2lf\n", value1 + value2);
        break;
    case '-':
        printf("%.2lf", value1 - value2);
        break;
    case '*':
        printf("%.2lf", value1 * value2);
        break;
    case '/':
        if (value2 == 0)
            printf("Division by zero - not posssible.\n");
        else
            printf("%.2lf", value1 / value2);
        break;
    default:
        break;
    }

}