#include<stdio.h>
int main()
{
	int count,i=1;
	printf("enter range: ");
	scanf("%d",&count);
	while(i<=count)
	{
		printf("%d %d ",i*1,i*2);
		i=i+2;
	}
}
