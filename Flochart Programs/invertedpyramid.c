#include<stdio.h>
int main()
{
	int i,j,k,rows;
	printf("enter no.of rows: ");
	scanf("%d",&rows);
	for(i=rows;i>0;i--)
	{
		for(j=0;j<rows-i;j++)
		{
			printf(" ");
		}
		for(k=0;k<2*i-1;k++)
		{
			printf("*");
		}
		printf("\n");
	}
}
