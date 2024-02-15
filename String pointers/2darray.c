#include<stdio.h>
int main() {
	char *s[4] = {"Saishitha", "Kavya","Pavithra","Hema"};

	for(int i=0;i<4;i++) {
		int j=0;
		while(*(s[i] + j) != '\0') {
			printf("%c",*(s[i]+j));
			j++;
		}
		printf("\n");
	}
}

