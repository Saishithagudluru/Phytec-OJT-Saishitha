#include <stdio.h>


int main(){
    
    //Pointer Variable Declaration for Integer Data Type 
   int* pt;
   int var;
   
   var=1;
   
   printf("Address of var             :%p\n",&var);
   printf("Value   of var             :%d\n\n",var);
   
   //& takes the address of var , Here now pt == &var, so *pt == var
   pt=&var;
   
   printf("Address of Pointer pt     :%p\n",pt);
   printf("Content of Pointer pt     :%d\n\n",*pt);
   
   var=2;
   
   printf("Address of Pointer pt     :%p\n",pt);
   printf("Content of Pointer pt     :%d\n\n",*pt);
   
   //Assign Values using dereference operator
   *pt=3;
   
   printf("Address of var            :%p\n",&var);
   printf("Value   of var            :%d\n\n",var);
   
   return 0;
   
}
