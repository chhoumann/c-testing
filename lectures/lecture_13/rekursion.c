#include <stdio.h>
#include <stdlib.h>

/* Find pointer to ssi in array between fp and tp. Return NULL if not found */
int* find_in_array_2(int si, int *fp, int *tp) {
    if (fp > tp)
        return NULL;
    else if (*fp == si)
        return fp;
    else
        return find_in_array_2(si, fp+1, tp);
}

int main(void) {
    int tab[] = {4, 8, -9, 2, 9, 11, 19};
    int done = 0, i;
    int *result;

    while (!done) {
        printf("Search for: "); scanf(" %d", &i);

        result = find_in_array_2(i, &tab[0], &tab[0] + 6);
        if (result) printf("Found\n"); else printf("NOT found\n");
        done = i == 0;
    }

    return 0;
}