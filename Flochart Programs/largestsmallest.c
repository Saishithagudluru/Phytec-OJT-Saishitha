#include<stdio.h>
int main()
{
	int a,b,c,d;
	printf("enter values: ");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a>b&&a>c&&a>d)
	{
		printf("%d is largest\n",a);
	}
	else if(b>c&&b>d)
	{
		printf("%d is largest\n",b);
	}
	else if(c>d)
	{
		printf("%d is largest\n",c);
	}
	else
	{
		printf("%d is largest\n",d);
	}
	if(a<b&&a<c&&a<d)
        {
                printf("%d is smallest\n",a);
        }
        else if(b<c&&b<d)
        {
                printf("%d is smallest\n",b);
        }
        else if(c<d)
        {
                printf("%d is smallest\n",c);
        }
        else
        {
                printf("%d is smallest\n",d);
        }
}
