#include<stdio.h>
int main() {
	int num1=22;
	int num2=23;
	int num3=24;
	int num4=25;
	int num5=26;
	int i;
	int *ptr[5]={&num5,&num4,&num3,&num2,&num1};
	printf("size of pointer is:%lu\n",sizeof(*ptr));
	for(i=0;i<5;i++) {
	printf("%d\n",*ptr[i]);
	}
}	
