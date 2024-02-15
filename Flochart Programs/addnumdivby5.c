#include<stdio.h>
int main()
{
	int a,b,i,sum=0;
	printf("enter a ,b values: ");
	scanf("%d%d",&a,&b);
	if(a==b)
	{
		printf("There is no number between %d and %d\n",a,b);
	}
		else if(a>b)
	{
		printf("%d is greater than %d so values are swapped\n",a,b); 
		a=a+b;
		b=a-b;
		a=a-b;
	}
		
	for(i=a;i<=b;i++)
	{
		if(i%5!=0)
		{
			sum = sum +i;
		}
	}
		if(sum)
		{
			printf("sum = %d\n",sum);
		}

}
