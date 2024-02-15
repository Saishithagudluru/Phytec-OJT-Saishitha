#include<stdio.h>
int main()
{
	int result,number,rotation;
	printf("enter number: ");
	scanf("%d",&number);
	printf("enter rotation: ");
	scanf("%d",&rotation);
	result=number>>rotation;
	printf("%d",result);
}
