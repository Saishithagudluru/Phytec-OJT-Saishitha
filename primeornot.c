#include <stdio.h>

int main() {
    int limit;

    // Input the limit
    printf("Enter a number: ");
    scanf("%d", &limit);

    printf("Prime numbers up to %d: ", limit);

    // Loop through numbers from 2 to the limit
    for (int i = 2; i <= limit; i++) {
        int isPrime = 1;  // Assume i is prime

        // Check if i is divisible by any number from 2 to sqrt(i)
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = 0;  // i is not prime
                break;
            }
        }

        // If isPrime is 1, i is a prime number
        if (isPrime) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}

