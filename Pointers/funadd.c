/*##Simple Example Program for Passing pointers to functions In C*/
/*##Simple Add Numbers Programs,pointers Example C Programming*/
/*##Pass By Referense Function Example Program In C Programming*/

#include <stdio.h>

// Declare Add Numbers Function Using Pointer 

void add_numbers(int *value1, int *value2, int *result) {
  *result = *value1 + *value2;
}

int main() {
  // Declare Variables
  int number1, number2, result = 0;

  // Read User Input
  printf("Enter value of Number # 1: ");
  scanf("%d", &number1);
  printf("Enter value of Number # 2: ");
  scanf("%d", &number2);

  //Print Values Pass to Reference
  printf("Before Pass to Reference :  Number # 1=%d,  Number # 2=%d, Result # :%d \n", number1, number2, result);

  //Call add_numbers Function By Passing Reference
  add_numbers(&number1, &number2, &result);

  //Print Values Pass to Reference
  printf("After  Pass to Reference :  Number # 1=%d,  Number # 2=%d, Result # :%d\n", number1, number2, result);

  return 0;
}
