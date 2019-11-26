#include <stdio.h>
#include <stdlib.h>

int test_function(int input_parameter);

int main(void) {
    int ill_be_back = 3;
    printf("%d", test_function(ill_be_back));

    return 0;
}

int test_function(int input_parameter) {
    return input_parameter;
}