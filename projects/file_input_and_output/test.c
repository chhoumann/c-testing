#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE * pfile = NULL;
    char *filename = "./testfile.txt";
    char unit;
    char name[60];
    int value;

    pfile = fopen(filename, "r"); /* Open myfile.txt to read it */
    if (pfile == NULL) /* If unable to open file: EXIT_FAILURE */
        return EXIT_FAILURE;


    fscanf(pfile, "- %d %c %s", &value, &unit, &name);

    printf("You have %d %c of %s.\n", value, unit, name);

    fclose(pfile); /* standard practice  */
    pfile = NULL;  /*       -||-         */

    /* rewind() to read file again */

    return 0;
}