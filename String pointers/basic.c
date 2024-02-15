#include<stdio.h>
int main() {
	//int s;
	//printf("Enter size of string:\n");
	//scanf("%d",&s);
	//char a[s];
	//printf("Enter the string:\n");

	//gets(a);
	char a[]="Saishitha";
	char *p;
	p = a;
	while(*p != '\0') {
		printf("%c",*p);
		p++;
	}
	printf("\n");
}
