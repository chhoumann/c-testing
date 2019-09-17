/*
* Page 242, programming exercise 1.
*/
#include<stdio.h>

int main (void){
    int lumens, watts;

    switch (watts)
    {
    case 15:    lumens = 125;   break;
    case 25:    lumens = 215;   break;
    case 40:    lumens = 500;   break;
    case 60:    lumens = 880;   break;
    case 75:    lumens = 1000;  break;
    case 100:   lumens = 1675;  break;
    
    default:    lumens = -1;    break;
    }
    
}