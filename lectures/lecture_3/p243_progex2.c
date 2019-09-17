/*
* page 243 programming exercise 2.
* same as p242_progex1.c, but just using an if statement instead.
*/
#include <stdio.h>

int main (void){

    int watts, lumens;

    if (watts == 15){
        lumens = 125;
    } else if (watts == 25) {
        lumens = 215;
    } else if (watts == 40)
    {
        lumens = 500;
    } else if (watts == 60)
    {
        lumens = 880;
    } else if (watts == 75)
    {
        lumens = 1000;
    } else if (watts == 100)
    {
        lumens = 1675;
    } else {
        lumens = -1;
    }

    return 0;
}