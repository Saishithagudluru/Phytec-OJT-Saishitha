#include<stdio.h>

int main ()
{
  int p[5] = { 8, 9, 10, 11, 12 }, i;
  int *ptr = p;
  *(ptr+3) = 16;

  for (i = 0; i < 5; i++)
    printf ("&p[%d] = %p \t p[%d] = %d\n", i, ptr + i, i, *(ptr + i));

  return 0;
}
//4th element is modified from 11 to 16
