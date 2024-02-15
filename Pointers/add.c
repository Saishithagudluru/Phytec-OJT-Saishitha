/* Simple Program for Add Two Numbers Using Pointer in C*/
/* Print Pointer Address Program,C Pointer Examples */

#include<stdio.h>

int main() {
  int *p1, *p2;
  int num1, num2, sum;

  printf("Pointer Example Program : Add Two Numbers \n");

  printf("\nEnter Two Numbers for Sum : \n");
  scanf("%d %d", &num1, &num2);

  p1 = &num1;
  p2 = &num2;

  sum = *p1 + *p2;

  printf("Sum of Two Numbers : %d\n", sum);
  return 0;
}

