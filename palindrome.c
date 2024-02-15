// Check the given number is palindrome or not


#include<stdio.h>
int main() {
	int n,rem,sum=0;
	printf("Enter a number:\n");
	scanf("%d",&n);
	int temp = n;
	while(n>0) {
		rem=n%10;
		sum = (sum*10)+rem;
		n = n/10;
	}
	if(temp==sum)
		printf("It is a palindrome number");
	else
		printf("Not a palindrome number");
}

