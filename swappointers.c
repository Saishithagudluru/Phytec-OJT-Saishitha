#include<stdio.h>
void swap (int *a, int *b);
int main() {
  int m = 25;
  int n = 100;
  printf("m is %d, n is %d\n", m, n);
  swap(&m, &n);
  printf("m is %d, n is %d\n", m, n);
}
void swap (int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
