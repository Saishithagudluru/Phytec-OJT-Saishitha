#include<stdio.h>
int main() {
	int A[]={3,7,4,9,12,6,1,11,2,10};
	int H[11]={0};
	for(int i=0;i<10;i++) {
		H[A[i]]++;
	}
	for(int i=1;i<10;i++) {
		if(H[i]==0) {
			printf("The missed elementd are:%d\n",i);
		}
	}
}

