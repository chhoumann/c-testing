#include <string.h>
#include <stdio.h>
#define LEN 25

int main(void){
	char str[] = "The Aalborg University first year of studies";
	char target[LEN];

	strncpy(target, str+4, 18);
	target[18] = '\0'; /* We have to add this ourselves. */

	printf("The substring is %s\nLength: %i\n",
					target, strlen(target));

	return 0;
}