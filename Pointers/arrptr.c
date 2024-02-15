#include<stdio.h>
int main() {
	int arr[10],i;
	int *ptr;
	ptr = arr;
	printf("Enter array elements:\n" );
	for(i=0;i<10;i++) {
		scanf("%d",ptr);
		ptr++;
	} // OR 
		
     /*	for(i=0;i<10;i++) {
		scanf("%d",&arr[i]);
	} */
	//int *ptr;
	//ptr=arr;
	ptr=arr;
	for(i=0;i<10;i++) {
		printf("%d\n",*ptr);
		ptr++;
	}
}
