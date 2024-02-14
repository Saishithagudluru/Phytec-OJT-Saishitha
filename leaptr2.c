#include <stdio.h>

int main() {
   int Startyear,Endyear;
   printf("Enter Start year: ");
   scanf("%d",&Startyear);
   printf("Enter End year: ");
   scanf("%d",&Endyear);
   printf("%d Start year to %d End year are: \n",Startyear,Endyear);
   for(int i=Startyear;i<=Endyear;i++) {
   if (((i % 4 == 0) && (i % 100!= 0)) || (i % 400 == 0)) {
      printf("%d is a leap year\n",i);
   }
   else
   	printf("%d is a not a leap year\n",i);
   }
}
