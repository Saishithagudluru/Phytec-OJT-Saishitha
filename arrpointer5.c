#include<stdio.h>
void main() {
	char mesg[50]="Happy Women's day";
	int pos,len;
	printf("Mesh string=%s\n",mesg);
	len=mystrlen(mesg);
	printf("length of the string=%d\n",len);
}
int mystrlen(char *pch) {
	int l=0;
	for(int i=0;*(pch+l)!='\0';i++) {
		l++;
		return length;
	}
	void mystrcpy(char *dst,char *svc)
	{
		int i;
		for(i=0;*(src+i)!='\0';i++)
		{
			*(dsti)=*(src+i);
		}
		*(dst+i)='\0';
	}
