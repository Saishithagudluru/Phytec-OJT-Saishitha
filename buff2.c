#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main() {
	char buff[256];
	int n = read(STDIN_FILENO,buff,255);
	write(STDIN_FILENO,buff,255);
	return 0;
}
