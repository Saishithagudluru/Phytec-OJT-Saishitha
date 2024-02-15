#include <stdio.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimalNumber) {
    char hexadecimalNumber[20];
    int i = 0;

    // Convert decimal to hexadecimal
    while (decimalNumber != 0) {
        int remainder = decimalNumber % 16;
        if (remainder < 10) {
            hexadecimalNumber[i] = remainder + '0';
        } else {
            hexadecimalNumber[i] = remainder + 'A' - 10;
        }
        i++;
        decimalNumber /= 16;
    }

    // Print the hexadecimal equivalent in reverse order
    printf("Hexadecimal equivalent: 0x");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimalNumber[j]);
    }
    printf("\n");
}

int main() {
    int decimalNumber;

    // Input decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Convert and print the hexadecimal equivalent
    decimalToHexadecimal(decimalNumber);

    return 0;
}

