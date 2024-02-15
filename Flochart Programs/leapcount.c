#include<stdio.h>
int main()
{
	int count=0;
	int a,b;
	printf("enter values: ");
	scanf("%d%d",&a,&b);
	for(int i=a;i<=b;i++)
	{
	if(i%400==0||(i%4==0&i%100!=0))
	{
		count ++;
	}
	}
	printf("%d",count);
}
