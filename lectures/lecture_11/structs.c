/* Example taken from lecture video. */
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long CPR;

enum weekday {sunday, monday, tuesday, wednesday, thursday, friday, saturday};
typedef enum weekday weekday;

struct date
{
    weekday day_of_week;
    int day;
    int month;
    int year;
};
typedef struct date date;

int date_before(date d1, date d2);



int main(void){

    date today = {tuesday, 19, 11, 2019};
    date tomorrow = {wednesday, 20, 11, 2019};

    if (date_before(today, tomorrow))
        printf("OK\n");
    else printf("Problems\n");
    
}

/* Is date d1 less than date d2 */
int date_before(date d1, date d2){
    return
        (d1.year < d2.year) ||
        (d1.year == d2.year && d1.month < d2.month) ||
        (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day);
}