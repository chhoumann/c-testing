#include <stdio.h>
#include <string.h>

int main(void){
	char str[] = "The Aalborg University first year of studies", *search_result;

	search_result = strstr(str, "University");

	printf("We located %s\nLength: %i\n", search_result, strlen(search_result));

	return 0;
}