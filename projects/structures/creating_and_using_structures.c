#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int month;
    int day;
    int year;
} dates;

int main(void) {
    dates my_birthday_date;

    my_birthday_date.day = 14;
    my_birthday_date.month = 8;
    my_birthday_date.year = 1998;

    printf("Sizeof: %d\n", sizeof(dates));
    printf("My birthday is %d/%d/%d.\n", my_birthday_date.day, my_birthday_date.month, my_birthday_date.year);

    return 0;
}