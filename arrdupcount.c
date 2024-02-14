#include<stdio.h>
int main() {
	int A[10],i,last_duplicate,count=0;
	printf("Enter array elements:");
	for(i=0;i<10;i++) {
		scanf("%d",&A[i]);
	}
	for(i=0;i<10;i++) { 
		if(A[i]==A[i+1] && A[i]!=last_duplicate) {
			count++;
			printf("count:%d\n",count);
		}
	}
}


