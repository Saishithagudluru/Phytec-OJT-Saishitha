/*#include<stdio.h>
void printstring(char str);
int main() {
	int size,i;
	printf("Enter size of string:\n");
	scanf("%d",&size);
	char str[size];
	printf("Enter a  string:\n");
	for(i=0;i<size;i++) {
		scanf("%c",&str[i]);
	}
	void (*ptr)(char);
	ptr = printstring;
       	int result=ptr(str);
}
void printstring(char str) {
	for(int i=0;str[i]!='\0';i++) {
		printf("%c",str[i]);
	}
}*/
#include <stdio.h>

// Function prototype
void printString(char *str);

int main() {
    char inputString[100];

    // Input the string
    printf("Enter a string:\n");
    fgets(inputString, sizeof(inputString), stdin);

    // Define a function pointer
    void (*ptr)(char *);

    // Assign the address of the printString function to the function pointer
    ptr = printString;

    // Call the function using the function pointer
    ptr(inputString);

    return 0;
}

// Function definition
void printString(char *str) {
    // Iterate through the string until the null terminator is encountered
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

