#include <stdio.h>

int main(void){

	int a[5] = {1,2,3,4,5};
	int *pa = &a[0];
	char *pac = (char*)pa; /* Hvis man tæller denne op, går den 1 bye op, ikke 4 som er i en int. */
	int i, j;

	for(i = 0; i < 5; ++i)
		printf("a[%1d] = %d ", i, *(pa+i));

	printf("\n\n");

	for(j = 0; j < 5 * sizeof(int); ++j){
		printf("a[%2d] = %d ", j, *(pac+j));
		if ((j+1)%4 == 0) printf("\n");
	}

	return 0;
}