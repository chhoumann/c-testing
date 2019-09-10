#include <stdio.h>

int main(void)
{

    /* The assignment here was to predict what the prints would say before actually running the program. */

    int i = 3, j = 4, k = 5; /* Defining variables */
    int res1, res2, res3; /* Defining variables */

    i++; /* i = 4*/
    j--; /* j = 3 */
    ++k; /* k = 6 */

    printf("i: %d, j: %d, k: %d\n", i, j, k); /* "i: 4, j: 3, k = 6" */

    res1 = --i; /* res1 = 3 & i = 3 */
    res2 = j++; /* res2 = 3 & j = 4 */
    res3 = --k; /* res3 = 5 & k = 5 */

    printf("res1: %d, res2: %d, res3: %d\n", res1, res2, res3); /* res1: 3, res2: 3, res3: 5*/
    printf("i: %d, j: %d, k: %d\n", i, j, k); /* i: 3, j: 4, k: 5 */

    return 0;
}