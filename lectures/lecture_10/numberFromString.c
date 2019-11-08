#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int main(void){

	/* strings to numbers */
	int    i = atoi("1234");
	double d = atof("123.456");
	long   l = atol("12345678");

	printf("i = %i, d = %f, l = %li.\n", i, d, l);

	return 0;
}