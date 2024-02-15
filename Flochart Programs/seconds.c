#include<stdio.h>
int main()
{
	int hr,x,sec,min,seconds;
	printf("enter seconds : ");
	scanf("%d",&sec);
	hr=sec/3600;
	min=(sec%3600)/60;
	x=(sec%3600)%60;
	if(x>59)
	{
		seconds=(min%60)/60;
	}
	else
		seconds=(sec%3600)%60;
	printf("%d:%d:%d",hr,min,seconds);
}
	
