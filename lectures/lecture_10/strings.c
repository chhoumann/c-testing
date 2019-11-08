#include <stdio.h>

int main(void){
	char str_1[] = {'A', 'a', 'l', 'b', 'o', 'r', 'g', '\0'};
	char str_2[] = "Aalborg";

	char *str_3 = "Aalborg";

	char str_4[8];
	str_4[0] = 'A'; str_4[1] = 'a'; str_4[2] = 'l'; str_4[3] = 'b'; str_4[4] = 'o';
	str_4[5] = 'r'; str_4[6] = 'g'; str_4[7] = '\0';

	printf("%s\n%s\n%s\n%s\n", str_1, str_2, str_3, str_4);

	return 0;
}