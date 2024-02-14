#include<stdio.h>

void oneD_diagonal(int n,int oneD_arr[25],int twoD_arr[25][25]);
void twoD_1d(int n,int oneD_arr[25],int twoD_arr[25][25]);

int main()
{
	int i,j,n;
	int twoD_arr[25][25],oneD_arr[25];
	
	printf("Enter the size of the 2D matrix (N x N): ");
        scanf("%d",&n);
        
        printf("\nEnter the elements of the %dX%d 2D matrix:\n",n,n);
    	for(i=0;i<n;i++)
        	for(j=0;j<n;j++)
            		scanf("%d",&twoD_arr[i][j]);
            		
        printf("\nEntered 2D matrix:\n");
    	for(i=0;i<n;i++)
    	{
    		for(j=0;j<n;j++)
        		printf("%d  ",twoD_arr[i][j]);
        	printf("\n");
    	}    		
    	
    	twoD_1d(n,oneD_arr,twoD_arr); 
    	
    	oneD_diagonal(n,oneD_arr,twoD_arr);
    	
    	printf("\nDiagonal matrix:\n");
    	for(i=0;i<n;i++)
    	{
    		for(j=0;j<n;j++)
        		printf("%d   ",twoD_arr[i][j]);
        	printf("\n");
    	}
    	
    	

	printf("\nDiagonal matrix as 1D array:\n");
    	for(i=0;i<n;i++)
        	printf("%d  ", oneD_arr[i]);
        	
    	printf("\n");
    	
    	return 0;
}

void twoD_1d(int n,int oneD_arr[25],int twoD_arr[25][25])
{
	int i;
	for(i=0;i<n;i++)
        	oneD_arr[i] = twoD_arr[i][i];
}

void oneD_diagonal(int n,int oneD_arr[25],int twoD_arr[25][25])
{
	int i, j;
    	for(i=0;i<n;i++) 
    	{
        	for(j=0;j<n;j++)
        	{
            		if (i==j)
                		twoD_arr[i][j] = oneD_arr[i];
                	else
                		twoD_arr[i][j] = 0;
                }		
        
    	}
}
