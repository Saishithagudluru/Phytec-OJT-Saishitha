#include<stdio.h>
#include<string.h>
int main () 
{
	char s1[14],s2[14];
	printf("enter string1: ");
	scanf("%s",s1);
	char temp;
	int i, j;
        int n  = strlen(s1);

   for (i = 0; i <n; i++)
   {
      for (j = 0; j < n; j++)
      {
         if (s1[i] < s1[j])
	 {
            temp  = s1[i];
            s1[i] = s1[j];
            s1[j] = temp;
	 }
      }
   }
   printf("%s",s1);
}


