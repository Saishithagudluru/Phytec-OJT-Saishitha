#include<stdio.h>
int add(int,int);
int main() {
	int a,b,result;
	printf("Enter two values:\n");
	scanf("%d%d",&a,&b);
	int (*p)(int,int);
	p = add;
	result = p(a,b); //Instand we can use (*p)(a,b)
	printf("The sum of two numbers is:%d\n",result);
}
int add(int a,int b) {
	int c = a+b;
	return c;
}
