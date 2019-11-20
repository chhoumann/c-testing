#include <stdio.h>

int main(void){
    enum Company {GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT};

    enum Company google = GOOGLE;
    enum Company xerox = XEROX;
    enum Company ebay = EBAY;

    printf("The value of xerox is: %d\n", xerox);
    printf("The value of google is %d\n", google);
    printf("The value of ebay is: %d\n", ebay);

    return 0;

}