#include<stdio.h>
int main() {
	unsigned int num=0x12345678;
	unsigned int a,b,c,d;
	a=((num & 0x0000000f)<<28)|((num & 0x000000f0)<<20);
	b=((num & 0x00000f00)<<12)|((num & 0x0000f000)<<4);
	c=((num & 0x000f0000)>>4)|((num & 0x00f00000)>>12);
	d=((num & 0x0f000000)>>20)|((num & 0xf0000000)>>28);
	printf("0x%x",a|b|c|d);
	}
