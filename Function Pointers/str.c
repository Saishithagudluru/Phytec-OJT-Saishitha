#include<stdio.h>
int printstring(char str[]) {
	char *ptr;
        ptr= str;
	for(int i=0;i<10;i++) {
		printf("%c",ptr[i]);
		//ptr[i+1];
		//ptr++;
	}
}

int main() {
	char str[10];
	printf("Enter a string:\n");
	for(int i=0;i<10;i++) {
		scanf("%c",&str[i]);
	}
	printstring(str);
}
