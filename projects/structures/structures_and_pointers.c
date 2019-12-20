#include <stdio.h>
#include <stdlib.h>

struct date {
    int day;
    int month;
    int year;
};

struct intPtrs {
    int *p1;
    int *p2;
};


int main(void) {
    struct date *datePtr;
    struct date todaysDate;

    todaysDate.day = 20; todaysDate.month = 12; todaysDate.year = 2019;

    datePtr = &todaysDate;

    printf("datePtr.day   = %d\n"
           "datePtr.month = %d\n"
           "datePtr.year  = %d\n\n",
           *datePtr, *(datePtr+1), *(datePtr+2));

    /* Or do this */
    printf("datePtr.day   = %d\n"
           "datePtr.month = %d\n"
           "datePtr.year  = %d\n\n",
           (*datePtr).day, (*datePtr).month, (*datePtr).year);

    /* Or even */
    printf("datePtr.day   = %d\n"
           "datePtr.month = %d\n"
           "datePtr.year  = %d\n\n",
           datePtr->day, datePtr->month, datePtr->year);

    struct intPtrs pointers;
    int i1 = 100, i2;

    pointers.p1 = &i1;
    pointers.p2 = &i2;
    *pointers.p2 = -97;

    printf("i1 = %d, *pointers.p1 = %d\n", i1, *pointers.p1);
    printf("i2 = %d, *pointers.p2 = %d\n", i2, *pointers.p2);
}