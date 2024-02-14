#include<stdio.h>
int arr_add(int *a,int num_elements);
int main() {
	int A[]={100,34,89,76,56};
	int sum=arr_add(A,5);
	printf("Sumation of array elements is:%d\n",sum);
}
int arr_add(int *p,int num_elements) {
	int sum=0;
	int k;
	for(k=0;k<5;k++) {
		sum += p[k];
	}
		return sum;
}
	
