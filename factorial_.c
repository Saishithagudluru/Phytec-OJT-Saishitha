//Factorial of given numner using recursion

#include<stdio.h>

int factorial(int n);
void  main() 
{
	int n;
	scanf("%d",&n);
	int res= factorial(n);
	printf("%d\n",res);
}
int factorial(int n)
{
        if (n == 0)
                return 1;
        return n*( factorial(n-1));
}


