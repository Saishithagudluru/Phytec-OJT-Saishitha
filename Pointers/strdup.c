#include<stdio.h>
#include<string.h>
int main() {
	char string[100];
	int i,count,j;
	printf("Enter a string:\n");
	scanf("%[^\n]*c",string);
	int a=strlen(string);
	for(i=0;i<a;i++){
		count=1;
		for(j=i+1;j<a;j++) {
			if(string[i]==string[j] && string[i]!=' ') {
				count++;
			}
		}
	if(count>1 && string[i]!='\0') {
                        printf("%c",string[i]);

	}
}
}
