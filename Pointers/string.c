
// Program to print given string using pointers

#include<stdio.h>
int main() {
	char str[20], *p;
	gets(str);
	p=str;
	while(*p!='\0'){
		printf("%c",*p);
		p++;
	}
	printf("\n");
}
