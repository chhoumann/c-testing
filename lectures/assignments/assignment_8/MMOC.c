/*
*   Author: Christian Bager Bach Houmann
*   Due date: 18/11/2019
*   Purpose: Solving "Problem Solving and Program Design in C" programming exercise 1 page 490.
*            Prints MMOC product code.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PRODUCTCODELEN   10
#define WAREHOUSELEN      3
#define PRODUCTLEN        4
#define QUALIFIERLEN      3

int readProductCode(char * productCode);

int main(void){
    /* Input */
    char productCode[PRODUCTCODELEN] = "ATL1203S14";

    readProductCode(productCode);
    
    return 0;
}

int readProductCode(char input[]){
    /* Declarations */
    char whCode[WAREHOUSELEN], pCode[PRODUCTLEN], qualCode[QUALIFIERLEN];

    /* Warehouse Code handling */
    strncpy(whCode, input, WAREHOUSELEN);
    whCode[WAREHOUSELEN] = '\0';
    printf(" Warehouse: %s\n", whCode);

    /* Product Code handling */
    strncpy(pCode, input + WAREHOUSELEN, PRODUCTLEN);
    pCode[PRODUCTLEN] = '\0';
    printf("   Product: %s\n", pCode);

    /* Qualifier Code handling */
    strncpy(qualCode, input + (WAREHOUSELEN + PRODUCTLEN), QUALIFIERLEN);
    qualCode[QUALIFIERLEN] = '\0';
    printf("Qualifiers: %s\n", qualCode);

    return 0;
}