#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} date;


int main(void) {
    date myDates[10] = {[2] = {1, 2, 2000}};

    myDates[0].day = 14;    myDates[0].month = 8;    myDates[0].year = 1998;
    myDates[1].day =  8;    myDates[1].month = 9;    myDates[1].year = 1999;


    return 0;
}