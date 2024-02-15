//factorial of a given number

//using function 


#include<stdio.h>

void factorial(int N) {
	unsigned long long fact = 1;
	for(int i=1;i<=N;i++) {
		 fact =fact*i;
	}
	printf("%lld\n",fact);
}


int main() {
	int n;
	scanf("%d",&n);
	factorial(n);
}
