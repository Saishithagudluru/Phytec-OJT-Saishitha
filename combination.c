#include<stdio.h>
int c(int n,int r) {
	if(r==0 || n==r) 
		return 1;
	else
		return (c(n-1,r-1)+c(n-1,r));
}
int main() {
	int n,r,result;
	printf("Enter n and r values:");
	scanf("%d%d",&n,&r);
	result=c(n,r);
	printf("Combination of %d and %d is:%d",n,r,result);
	printf("\n");
}

