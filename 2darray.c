#include<stdio.h>
int main() {
	int m,n,i,j;
	printf("Enter the no. of rows:\n");
	scanf("%d",&m);
	printf("Enter the no.of columns:\n");
	scanf("%d",&n);
	int arr[m][n];
	printf("Enter array elements:\n");
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=0;i<m;i++) {
                for(int j=0;j<n;j++) {
                        printf("%d ",arr[i][j]);
                }
		printf("\n");
        }
}

			

