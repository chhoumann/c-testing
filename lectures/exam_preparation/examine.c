/* Used to explain terms in order to prepare for exams. */


/* ----- These are what's called preprocessor directives (præprocesser directive) ----- */
/* Examples of inclusions (library header inclusions) */
#include <stdio.h> 
#include <stdlib.h>
/* Or definitions of constants (i dette tilfælde: symbolske konstanter) */
#define PI 3.14159
#define E 2.71828
/* ----- ----- */

/* A declaration (erklæring) introduces a name and types for the name. */
double log_two(double x); /* This is a global variable. It's a function being declared; also called a prototype. */

int* find_in_array_2(int si, int *fp, int *tp) {
    if (fp > tp)
        return NULL;
    else if (*fp == si)
        return fp;
    else
        return find_in_array_2(si, fp+1, tp);
}

int main(void) {
    /* ----- Here are some local variables ----- */
    /* The first three variables (tab, done and test) are initialised, and *result is only declared. */
    int tab[] = {4, 8, -9, 2, 9, 11, 19};   /* INITIALIZED (tilskrevet startværdi) | Can change value at a later time  */
    int done = 0, i;                        /* INITIALIZED (tilskrevet startværdi) | Can change value at a later time  */
    const int test = 1;                     /* (not in program) CONSTANT - cannot change value after initialization.   */
    int *result;                            /* NOT INITIALIZED | Can change value at a later time                      */
    /* ----- ----- */

    while (!done) {
        printf("Search for: "); scanf(" %d", &i);

        result = find_in_array_2(i, &tab[0], &tab[0] + 6);
        if (result) printf("Found\n"); else printf("NOT found\n");
        done = i == 0; 
    }

    return 0;
}

/* ----- OPERATORS AND EXPRESSIONS ----- */
/* 
res1 = (x + y * 3 >= y % x - 5);
Everything in the parentheses above is an expression (udtryk).
We differentiate between 'operatorer' and 'operander'.
    +, *, >=, %, - are all 'operatorer'.
    x, y, 3, 5 are 'operander'.
What we see in the parentheses is called a clean expression (rent udtryk).
    No variables change value.
But if you take the whole line, then it is an unclean expression (urent udtryk).
    This is because res1 changes value.
        Happens because of the assignment operator (=).

Expressions that give a True or False output (1 or 0) are logic expressions (logiske udtryk).
    Also what's seen in the above expression. Due to the >= (greater than or equal to).






 */