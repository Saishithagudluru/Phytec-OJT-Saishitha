#include<stdio.h>
void arradd() {
	int i,n;
	printf("Enter the size of array:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the %d array elements:",n);
	for(i=0;i<n;i++)
       	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++)
       	{
		printf("Address of array elemets are arr[%d]=%p\n",i,&arr[i]);
	}
}
int main() {
	arradd();
}
