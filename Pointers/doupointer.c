#include<stdio.h>
int main() {
	int a,*p,**dp;
	a=20;
	p=&a;
	dp=&p;
	printf("Address of a is: %p\n",&a);
	printf("Value of a is: %d\n",a);
	printf("Address of p is: %p\n",p);
	printf("Value of p is: %d\n",*p);
	printf("Address of dp is: %p\n",dp);
	//printf("Address of dounle pointer is: %p\n",dp);
	printf("Value of double pointer is: %p\n",*dp);
	printf("Double pointer value is: %d\n",**dp);
}
