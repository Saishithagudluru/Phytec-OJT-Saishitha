
#include <stdio.h>

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");

    // Input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Assuming the array has at least one element
    int *ptr = arr;      //Here *ptr is a pointer that is assigned to address of 1st element in an array
    int largest = *ptr;  // Here we are giving the value of 1st element in an array

    // Find the largest element using pointers
    for (int i = 1; i < n; i++) {
        if (*(ptr + i) > largest) {
            largest = *(ptr + i);
        }
    }

    printf("The largest element in the array is: %d\n", largest);

    return 0;
}

