#include"addnum.h"
#include<stdio.h>
void main()
{
  int a,b,sum;
  printf("ENTER 2 NUMBERS :\n");
  scanf("%d",&a);
  scanf("%d",&b);
  sum=add(a,b);
  printf("SUM IS :%d\n",sum);
}
