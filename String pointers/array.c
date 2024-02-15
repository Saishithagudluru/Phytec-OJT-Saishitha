#include<stdio.h>
int main() {
	char subjects[5][20];
	int i,j;
	printf("Enter the names :\n");
	for(i=0;i<5;i++) {
		scanf("%s",subjects[i]);
	}
	printf("The name of subjects are:\n");
	for(i=0;i<5;i++) {
		j=0;
		while (*(subjects[i]+j) != '\0') {
			printf("%c",*(subjects[i]+j));
			j++;
		}
		printf(",size =%d\n",j);
	}
}
