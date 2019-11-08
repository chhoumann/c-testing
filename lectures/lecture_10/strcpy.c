#include <stdio.h>
#include <string.h>

int main(void){
    char str_aal[] = "Aalborg";
    char str[14];
    int i;

    /* fill str with '-' */
    for(i=0; i < 14; i++)
        str[i] = '-';
    
    strcpy(str + 2, str_aal);

    printf("%s\n",str);

    return 0;
}