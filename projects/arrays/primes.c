/* Finds primes up till 100 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int primes[50] = {2, 3};
    int p, i;
    int primeIndex = 2;

    bool isPrime;

    for (p = 5; p <= 100; p = p + 2){
        isPrime = true;

        for (i = 1; isPrime && p / primes[i] >= primes[i]; ++i)
            if (p % primes[i] == 0)
                isPrime = false;
            
        if (isPrime == true){
            primes[primeIndex] = p;
            ++primeIndex;
        }
    }


    /* Prints primes */
    for (i = 0; i < primeIndex; i++)
        printf("%d ", primes[i]);

    return 0;
        
}