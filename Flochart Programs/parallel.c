#include<stdio.h>
int main()
{
	int slope1,slope2;
	int x1,x2,y1,y2,a1,a2,b1,b2;
	printf("enter values for first line: ");
	scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
	printf("enter values for second line: ");
	scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
	slope1=y2-y1/x2-x1;
	slope2=b2-b1/a2-a1;
	if(slope1==slope2)
	{
		printf("given lines are parallel");
	}
	else
	{
		printf("Not parallel");
	}
}

