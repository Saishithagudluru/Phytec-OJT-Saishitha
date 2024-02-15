#include<stdio.h>
int main() {
	int n;
	int *p;
	int a[n],i,k=0;
	p = a;
	printf("Enter size of array:\n");
	scanf("%d",&n);
	printf("Enter array elements:\n");
	for(i=0;i<n;i++) {
		scanf("%d",p);
		p++;
		
	}
	p=a;
/*	for(int j=0;j<n;j++) {
		printf("%d",p[j]);
	}*/
	while(k<n)
	{
		printf("Given array using pointers is:%d-%p\n",*p,p);
 	        k++;
             	p++;
	}
}
