#include<stdio.h>
int prime(int num);

int prime(int num)
{
	int i,j;
	printf("The prime numbers are: ");
        for(i=2;i<num;i++)
	{
		int count=0;
		for(int j=1;j<i;j++)
		{
			if(i%j==0)
				count++;
		}
	
	if(count==1)
		printf("%d, ",i);
	}
}


int main()
{
        int i,num;
        printf("Enter the input range :");
        scanf("%d",&num);
	prime(num);                        
}
