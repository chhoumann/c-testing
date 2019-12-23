#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE * pfile = NULL;
    char *filename = "./testfile.txt";

    pfile = fopen(filename, "w"); /* Open myfile.txt to write it */

    if (pfile == NULL)
        printf("Failed to open %s.\n", filename);

    fputs("Hello World", pfile);

    return fclose(pfile);
}