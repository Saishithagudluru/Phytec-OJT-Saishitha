#include<stdio.h>
void arrpointer1() {
	int arr[2][3]={2,2,3,4,5,6};
	int *p;
	for(int i=0;i<2;i++) {
		for(int j=0;j<3;j++) {
			printf("%d",*(*(arr+i)+j));
			printf("\t");	
		}
		printf("\n");
	}
}
int main() {
	arrpointer1();
}
