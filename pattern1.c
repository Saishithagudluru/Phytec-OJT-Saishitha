#include<stdio.h>
int main() {
	int i,j,rows;
	printf("Enter the num of rows: ");
	scanf("%d",&rows);
	for(i=1;i<=rows;i++) {
		for(j=5;j>=i;j--) {
			printf("* ");
		}
		printf("\n");
	}
}
