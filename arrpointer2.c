#include<stdio.h>
void arrpointer2(char *str);
void main() {
	char s[]="Saishitha";
	arrpointer2(s);
}
void arrpointer2(char *str) {
	while(*str) {
		printf("%c",*str++);
	}
	printf("\n");
}
