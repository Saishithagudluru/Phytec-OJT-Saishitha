#include<stdio.h>
void arrele() 
{
	int i,n;
	int arr[i];
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter the %d array elements:",n);
	for(i=0;i<n;i++)
       	{
	scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
	printf("The array elements are: arr[%d]=%d\n",i,arr[i]);
	}
}
int main() 
{
	arrele();
}
