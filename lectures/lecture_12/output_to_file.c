#include <stdio.h>
#include <stdlib.h>

/*FILE *fopen(const char *filename, const char *mode);  Etablerer og returnerer en pointer til en FILE struct */
/*int fclose(FILE *stream);  Tømmer buffere og frigiver interne ressourcer og bryder forbindelsen til filen i operativsystemet */

int main(void){

    FILE *output_file_pointer;
    char *str ="123456789abcdefghijklmnopqrstuvx";
    
    output_file_pointer = fopen("first-file", "w");

    if (output_file_pointer != NULL) {       /* File could not be opened */
        while (*str != '\0'){
            fputc(*str, output_file_pointer);
            str++;
        }

        fclose(output_file_pointer);
    } else {
        printf("Could not open output file. Closing.");
        exit(EXIT_FAILURE);
    } 
    
    return 0;
}