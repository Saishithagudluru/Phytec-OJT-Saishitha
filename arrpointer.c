#include<stdio.h>
void arrpointers() {
	int A[]={1,2,3,4,5};
	int *p;
	p=&A[0];
	for(int i=0;i<5;i++) {
		printf("A[%d]=%d\n",i,p(i+1));
	}
}
int main() {
	arrpointers();
}
