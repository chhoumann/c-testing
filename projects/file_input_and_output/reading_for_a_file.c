#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE * pfile = NULL;
    char *filename = "./testfile.txt";
    char c = 0;
    char str[60];

    pfile = fopen(filename, "r"); /* Open myfile.txt to read it */
    if (pfile == NULL) /* If unable to open file: EXIT_FAILURE */
        return EXIT_FAILURE;

    /* 
    while((c = fgetc(pfile)) != EOF) Comment: Reads characters until end of file and prints them
        printf("%c", c);
     */

    /* A more efficient way to read a string from a file: */
    if (fgets(str, 60, pfile) != NULL)
        printf("%s", str);

    /*  
        You can also use fscanf to read formatted input - say you'd want to get a value from a string.
        It goes like so: int fscanf(FILE *stream, const char *format, ...)
        Example
            int value;
            char unit;
            char name[30]
            
            fscanf(pfile, "- %d %c %s", &value, &unit, &name);
            
            Contents of file: "- 50 g salt" where the values would be put into the correct variables.
                                        But it would probably be a good idea to use a struct for that. 
        EXAMPLE CAN BE SEEN IN "test.c".
    */

    fclose(pfile); /* standard practice  */
    pfile = NULL;  /*       -||-         */

    /* rewind() to read file again */

    return 0;
}