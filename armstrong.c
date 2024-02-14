// Given number is armstrong or not
/*153 = (1*1*1)+(5*5*5)+(3*3*3)  
where:  
(1*1*1)=1  
(5*5*5)=125  
(3*3*3)=27  
So:  
1+125+27=153  
*/

#include<stdio.h>

int main() {
	int n,remainder,result=0,original;
	scanf("%d",&n);
	original = n;
	while(original!=0)
       	{
		int rem = original % 10;
		result = result + (rem*rem*rem);
		original= original/ 10;
		//result = result + (rem*rem*rem);
	}
	if(result == n)
	{
		printf("%d is a Armstrong number\n",n);
	}
	else
	{
		printf("%d is not a armstrong number\n",n);
}
}
