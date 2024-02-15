
// Using a pointer to store string

#include<stdio.h>
int main() {
	char *a = "Saishitha";
	char *b = a;
	while(*b!='\0') {
		printf("%c",*b);
		b++;
	}
	printf("\n");
}
