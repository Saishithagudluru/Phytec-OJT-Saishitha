#include<stdio.h>
int main()
{
 //Ghanendra Yadav
  int i,arr[50],pos,len;

  printf("Enter no. of elements for the array:\n");
  scanf("%d",&len);

  printf("Enter %d elements for the array:\n",len);
  for(i=0;i<len;i++)
            scanf("%d",&arr[i]);

  printf("Enter position of the element to delete:\n");
  scanf("%d",&pos);

  i = pos-1;

  while(i<len - 1)
  {
            arr[i]=arr[i+1];
            i++;
  }
  len--;
  printf("Array after deleting element\n");

  for(i=0;i<len;i++)
            printf(" %d",arr[i]);
return 0;
}
