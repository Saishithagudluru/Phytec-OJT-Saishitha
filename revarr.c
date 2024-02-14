#include<stdio.h>
int main() {
	int size,largest;
	printf("Enter size of array:\n");
	scanf("%d",&size);
	int arr[size];
	printf("Enter array elements:\n");
	for(int i=0;i<size;i++) {
		scanf("%d",&arr[i]);
	}
	int *ptr=arr;
	largest=*arr;
	for(int i=0;i<size;i++) {
		if(*(ptr+i) > largest) {
			largest = (*(ptr+i));
		}
	}
	printf("Largest element in array is %d\n",largest);
}
