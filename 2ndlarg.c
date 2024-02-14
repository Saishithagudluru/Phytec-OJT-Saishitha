#include <stdio.h>

int main() {
    int size;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size < 2) {
        printf("Array size should be at least 2 for finding the second highest element.\n");
        return 1; // Exit with an error code
    }

    int arr[size];

    // Input the array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the second highest element
    int highest = arr[0];
    int secondHighest = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > highest) {
            secondHighest = highest;
            highest = arr[i];
        } else if (arr[i] > secondHighest && arr[i] != highest) {
            secondHighest = arr[i];
        }
    }

    // Output the result
    printf("The second highest element is: %d\n", secondHighest);

    return 0;
}

