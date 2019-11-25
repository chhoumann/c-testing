#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float sample_data[500] = {[2] = 500.5, [1] = 300.0, [0] = 100.0}; /* This is called designated initializers. Not usable in ANSI. */

    float multidimensional[3][4] = {
        { 10, 20, 30, 40 },
        { 15, 25, 35, 45 },
        { 47, 48, 49, 50 }
    }; /* View this as a table. This is called a multidimensional array. If I negnected to initialize some values, they'd be set to 0 automatically. */

    return 0;
}