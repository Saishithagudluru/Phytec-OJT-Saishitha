#include<stdio.h>
int *build_array();
int main() {
	int *a;
	a=build_array();
	for(int k=0;k<5;k++) {
		printf("%d\n",a[k]);
	}
}
int *build_array() {
	int static Tab[5]={1,33,89,56,99};
       return(Tab);
}       
