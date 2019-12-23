#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *filename = "./testfile2.txt";
    FILE *pfile = fopen(filename, "w+");

    /*
    Puts !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcd into testfile2.txt 
    for(int ch = 33; ch <= 100; ch++)
        fputc(ch, pfile);
    */
   
    /* fputs("Hello World\n", pfile); */
    /* To write to the file formatted: */
    fprintf(pfile, "%s,\n%s %s %s %s", "Hello", "My", "name", "is", "Christian.");

    fclose(pfile);
    return 0;
}