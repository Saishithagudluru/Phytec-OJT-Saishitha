#include<stdio.h>
int main() {
	int A[10],i;
	int last_duplicate=0;
	printf("Enter the array elements:");
	for(i=0;i<10;i++) {
		scanf("%d",&A[i]);
	}
	for(i=0;i<10;i++) {
		if(A[i]==A[i+1] && A[i]!=last_duplicate) {
			printf("%d",A[i]);
			last_duplicate=A[i];
		}
	}
}

