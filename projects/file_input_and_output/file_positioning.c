#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    /* For many applications, you need to be able to access data in a file other than sequential order. */
    /* ftell() returns a long.
        and 
       fgetpos() returns an integer */

    FILE *fp;
    int len;

    /* ----- using ftell() ----- */

    fp = fopen("./test.txt", "r");
    if(fp == NULL)
        printf("Error.\n");
    
    fseek(fp, 0, SEEK_END);

    len = ftell(fp);
    fclose(fp);

    printf("Total size of test.txt = %d bytes.\n", len);

    /* ----- using fgetpos() ----- */
    fpos_t position;

    fp = fopen("test.txt", "w+");
    fgetpos(fp, &position);
    fputs("Hello, World", fp);

    fclose(fp);

    /* ----- Setting a position in a file - using ftell() -----
    int fseek(FILE *pfile, long offset, int origin)
        The first parameter is a pointer to the file you are repositioning
        The second and third parameters define where you want to go in the file
            Second parameter is an offset from a reference point specified by the third parameter
            Reference point can be one of the following:
                SEEK_SET defines the beginning of the file.
                SEEK_CUR defines the current position in the file.
                SEEK_END defines the end of the file. 

    THE THIRD ARGUMENT FOR TEXT MODE FILES MUST BE SEEK_SET!!!
    Example of usage:
    */

   fp = fopen("test.txt", "w+");
   fputs("This is Christian", fp);

   fseek(fp, 7, SEEK_SET);
   fputs("Hello how are you", fp);
   /* So final file contents become: This isHello how are you */
   fclose(fp);

   /* There is also fsetpos() */
   fp = fopen("test.txt", "w+");
   fgetpos(fp, &position);
   fputs("Hello, World!", fp);

   fsetpos(fp, &position);
   fputs("This is going to override previous content", fp);
   fclose(fp);
   /* So final file contenst become: This is going to override previous content */

    return 0;
}