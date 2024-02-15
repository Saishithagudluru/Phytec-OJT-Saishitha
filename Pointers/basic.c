//Program to print values and address of variable 


#include<stdio.h>
int main() {
	int a = 5;
	int *p;
	p = &a;
	printf("%d\n",a);     // To print value of a
	printf("%p\n",p);     // To print value of p
	printf("%d\n",*p);    // To print value of a
	printf("%p\n",p);     // To print address of a in p
	printf("%p\n",&a);    // To print address of a
	printf("%p\n",&p);    // To print address of p
}
