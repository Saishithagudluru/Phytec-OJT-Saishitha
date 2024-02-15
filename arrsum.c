#include<stdio.h>
int main()
	{
		int a[10],i,n;
		printf("enter the number of elements\n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		printf("array in the reverse order\n");
		for(i=n-1;i>=0;i--)
		{
			printf("%d\t",a[i]);
	        }
		return 0;
	}
