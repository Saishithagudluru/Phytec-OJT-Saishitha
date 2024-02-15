#include<stdio.h>
int main() {
	int n;
	int *p;
	int i,k=0,sum=0;
	printf("Enter size of array:\n");
	scanf("%d",&n);
	int a[n];
	p = a;
	printf("Enter array elements:\n");
	for(i=0;i<n;i++) {
		scanf("%d",p);
		p++;
	} 
	p = a;
	while(k<n) {
		sum = sum + *p;
		p++;
		k++;
		
	}
	printf("Sum of array elements using pointers is:%d\n",sum);
}
