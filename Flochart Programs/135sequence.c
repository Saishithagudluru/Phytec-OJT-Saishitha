#include<stdio.h>
int main()
{
	int space,rows,i,j;
	printf("enter row value: ");
	scanf("%d",&rows);
	for(i=1;i<=rows;i++)
	{
		for(space=1;space<=rows-i;space ++)
		{
			printf(" ");
		}
		for(j=1;j<=i*2-1;j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
