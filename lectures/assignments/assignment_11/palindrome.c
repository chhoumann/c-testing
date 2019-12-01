/*
*   Author: Christian Bager Bach Houmann
*   Due date: 02/12/2019
*   Purpose: Checking if a word/string is a palindrome.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLENGTH 100

int is_palindrome_iter(char *str);
int is_palindrome_rec(char *str1, char *str2, int i);
int testing(char *str);

int main(void) {
    char str[MAXLENGTH], str_temp[MAXLENGTH];
    printf("Please enter a string to check: "); scanf("%s", str);
    
    /* Iterative function */
    printf("Iterative | %s is %sa palindrome.\n", str, is_palindrome_iter(str) ? "" : "not ");

    /* Recursive function */
    strncpy(str_temp, str, MAXLENGTH);
    strrev(str_temp);
    printf("Recursive | %s is %sa palindrome.\n", str, is_palindrome_rec(str, str_temp, 0) ? "" : "not ");
    
    return 0;    
}

int is_palindrome_iter(char *str) {
    char temp_string[MAXLENGTH];
    int i, k;

    strncpy(temp_string, str, MAXLENGTH);
    strrev(temp_string);

    for (i = 0, k = 0; i < strlen(str); i++){
        if (tolower(str[i]) == tolower(temp_string[k]))
            return 1;
        else
            return 0;
    } 
    
    return 0;
}

int is_palindrome_rec(char *str1, char *str2, int i) {
    if (tolower(str1[i]) != tolower(str2[i]))
        return 0;
    else if (tolower(str1[i]) == tolower(str2[i])) {
        is_palindrome_rec(str1, str2, i += 1);
    }

    return 1;
}
