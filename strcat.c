#include<stdio.h>
#include<string.h>
void string_demo() {
	char A[20] = "Suma";
	char B[20] = "Anjali";
	printf("Before concatination String A is:%s\n",A);
	printf("Before concatination String B is:%s\n",B);
	strcat(A,B);
	printf("After concatination String A is:%s\n",A);
	printf("After concatination String B is:%s\n",B);
}
int main() {
	string_demo();
}

