#include<stdio.h>
#include<ctype.h> // to use system defined function islower & toupper
#include <string.h>

void convertCase(char *str) {
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        } else if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
}

int main() {
    char inputString[100];

    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Removing the newline character from the input
    inputString[strcspn(inputString, "\n")] = '\0';

    convertCase(inputString);

    printf("Converted string: %s\n", inputString);

    return 0;
}

