/*#include <stdio.h>

int main() {
    int num,i,toggle;

    // Input the digital number from the user
    printf("Enter a digital number: ");
    scanf("%d", &num);
    printf("Enter the bit to toggle: ");
    scanf("%d", &toggle);
    int mask=1<<toggle;
    int value=num^mask;
	printf("Digital number after toggle is %d",value);
}*/
#include <stdio.h>

// Function to toggle the n-th bit of a number
int toggleNthBit(int num, int n) {
    // Use XOR (^) with a bit mask to toggle the n-th bit
    return num ^ (1 << (n - 1));
}

int main() {
    int number, position;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Input the position of the bit to toggle
    printf("Enter the position of the bit to toggle (1-based index): ");
    scanf("%d", &position);

    // Toggle the n-th bit
    int result = toggleNthBit(number, position);

    // Display the result
    printf("Original Number: %d\n", number);
    printf("Number after toggling bit %d: %d\n", position, result);

    return 0;
}

