#include <stdio.h>
#include <stdlib.h>

struct time {
    int hours;
    int minutes;
    int seconds;
};

struct date {
    int day;
    int month;
    int year;
};

struct date_and_time {
    struct date sdate;
    struct time stime;
};

int main(void) {
    struct date_and_time newMoment;
    newMoment.sdate.day = 20;
    newMoment.sdate.month = 12;
    newMoment.sdate.year = 2019;
    newMoment.stime.hours = 9;
    newMoment.stime.minutes = 4;
    newMoment.stime.seconds = 33;

}