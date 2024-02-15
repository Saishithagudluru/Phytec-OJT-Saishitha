 // Simple logic to swap
 // temp := x
 // x := y
 // y := temp
 

/*##Simple Example Program for Swap Numbers Using Pointers In C*/
/*##Simple swap Programs,pointers Example C Programming*/
/*##Pass By Referense Function Example Program In C Programming*/

#include <stdio.h>
 
// Declare Swap Function Using Pointer 
void swap_numbers(int *value1,int *value2)
{
    int temp;
    temp   	  = *value1;
    *value1   = *value2;
    *value2   =  temp;
}
 
int main()
{
	// Declare Variables
    int number1,number2;
     
    // Read User Input
    printf("Enter value of Swap Number # 1: ");
    scanf("%d",&number1);
    printf("Enter value of Swap Number # 2: ");
    scanf("%d",&number2);
     
    //Print Values before Swapping
    printf("Before Swapping :  Number # 1=%d,  Number # 2=%d\n",number1,number2);
     
    //Call Swap Function By Passing Reference
    swap_numbers(&number1,&number2);
     
    //Print Values after Swapping
    printf("After  Swapping :  Number # 1=%d,  Number # 2=%d\n",number1,number2);    
     
    return 0;
}
