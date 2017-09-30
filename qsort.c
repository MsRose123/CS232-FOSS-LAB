#include<stdio.h>
void rec(int ar[10],int left,int right);
void nonrec(int ar[10],int left,int right);
int partition(int ar[10],int left,int right);
void display(int ar[10],int n);
void main()
   {
     int ar[10],n,ch,i;
     printf("ENTER TOTAL NO OF ELEMENTS :\n");
     scanf("%d",&n);
     printf("ENTER ELEMENTS :\n");
     for(i=0;i<n;i++)
       scanf("%d",&ar[i]);
     do
      {
        printf("\tMENU\n1.RECCURSIVE QUICK SORT\n2.NON RECCURSIVE QUICK SORT\n3.EXIT\nENTER YOUR OPTION :\n");
        scanf("%d",&ch);
        switch(ch)
          {
            case 1 :printf("BEFORE RECURSIVE QUICK SORT :\n");
                    display(ar,n);
                    rec(ar,0,n-1);
                    printf("AFTER RECURSVE QUICK SORT :\n");
                    display(ar,n);
                    break;
            case 2 :printf("BEFORE NON-RECCURSIVE QUICK SOART :\n");
                    display(ar,n);
                    nonrec(ar,0,n-1);
                    printf("AFTER NON-RECCURSIVE QUICK SORT :\n");
                    display(ar,n);
                    break;
            case 3 :break;
            default:printf("INVALID OPTION\n");
                    break;
          }
       }while(ch!=3);
   }
void display(int ar[10],int n)
   {
     int i;
     for(i=0;i<n;i++)
       printf("%d\t",ar[i]);
     printf("\n");
   }
void rec(int ar[10],int left,int right)
   {
     int i,j,temp,pivot;
     if(left<right)
       {
         i=left;
         j=right+1;
         pivot=ar[left];
       }
     else
       return;
     while(i<j)
       {
         do i++; while(ar[i]<pivot);
         do j--; while(ar[j]>pivot);
         if(i<j)
           {
             temp=ar[i];
             ar[i]=ar[j];
             ar[j]=temp;
           }
         else
           {
             temp=ar[left];
             ar[left]=ar[j];
             ar[j]=temp;
           }
        }
      rec(ar,left,j-1);
      rec(ar,j+1,right);
   }
void nonrec(int ar[10],int left,int right)
   {
     int stack[10],top=-1,p;
     stack[++top]=left;
     stack[++top]=right;
     while(top>-1)
        {
          right=stack[top--];
          left=stack[top--];
          p=partition(ar,left,right);
          if(left<p-1)
            {
              stack[++top]=left;
              stack[++top]=p-1;
            }
          if(p+1<right)
            {
              stack[++top]=p+1;
              stack[++top]=right;
            }
         }
    }
int partition(int ar[10],int left,int right)
    {
      int i,j,pivot,temp;
      if(left<right)
         {
           i=left;
           j=right+1; 
           pivot=ar[left];
         }
      else
           return;
      while(i<j)
         {
            do i++; while(ar[i]<pivot);
            do j--; while(ar[j]>pivot);
            if(i<j)
                 {
                   temp=ar[i];
                   ar[i]=ar[j];
                   ar[j]=temp;
                 }
               else
                 {
                   temp=ar[left];
                   ar[left]=ar[j];
                   ar[j]=temp;
                   return j;
                 }
         }
   }
