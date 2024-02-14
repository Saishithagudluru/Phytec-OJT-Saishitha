#include<stdio.h>
int main()
{
	int A[4][5];
	printf("Enter elements for 4*5 matrix:\n");
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<5;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<5;j++)
			printf("%d\t",A[i][j]);
		printf("\n");
	}
}
