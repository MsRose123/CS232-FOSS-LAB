#include<stdio.h>
void rec(int ar[0],int beg,int end);
void nonrec(int ar[10],int n);
void merge(int ar[10],int beg,int mid,int end);
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
        printf("\tMENU\n1.RECCURSIVE MERGE SORT\n2.NON-RECCURSIVE MERGE SORT\n3.EXIT\nENTER YOUR OPTION :\n");
        scanf("%d",&ch);
        switch(ch)
          {
            case 1 :printf("BEFORE RECURSIVE MERGE SORT :\n");
                    display(ar,n);
                    rec(ar,0,n-1);
                    printf("AFTER RECURSVE MERGE SORT :\n");
                    display(ar,n);
                    break;
            case 2 :printf("BEFORE NON-RECCURSIVE MERGE SOART :\n");
                    display(ar,n);
                    nonrec(ar,n);
                    printf("AFTER NON-RECCURSIVE MERGE SORT :\n");
                    display(ar,n);
                    break;
            case 3 :break;
            default:printf("INVALID OPTION\n");
                    break;
          }
       }while(ch!=3);
   }
void rec(int ar[10],int beg,int end)
   {
     int m;
     if(beg<end)
       {
         m=(end+beg)/2;
         rec(ar,beg,m);
         rec(ar,m+1,end);
         merge(ar,beg,m,end);
       }
   }
void merge(int ar[10],int beg,int mid,int end)
   {
     int temp[10],i,j,k,index=0;
     i=beg;
     j=mid+1;
     while(i<=mid && j<=end)
           if(ar[i]<ar[j])
             temp[index++]=ar[i++];
           else
             temp[index++]=ar[j++];
     if(i>mid)
       while(j<=end)
           temp[index++]=ar[j++];
     else
       while(i<=mid)
           temp[index++]=ar[i++];
     for(j=beg,k=0;j<=end;k++,j++)
         ar[j]=temp[k];
   }    
void nonrec(int ar[10],int n)
   {
     int temp[10],size,i,j,k,l1,l2,u1,u2;
     for(size=1;size<n;size=size*2)
        {
          l1=0;
          k=0;
          while(l1+size<n)
             {
               l2=l1+size;
               u1=l2-1;
               u2=(l2+size-1<n)?l2+size-1:n-1;
               for(i=l1,j=l2;i<=u1 && j<=u2;k++)
                  if(ar[i]<=ar[j])
                      temp[k]=ar[i++];
                  else
                      temp[k]=ar[j++];
               while(i<=u1)
                   temp[k++]=ar[i++];
               while(j<=u2)
                   temp[k++]=ar[j++];
               l1=u2+1;
             }
          for(i=l1;i<n;i++)
             temp[k++]=ar[i];
          for(i=0;i<n;i++)
             ar[i]=temp[i];
        }
    }
void display(int ar[10],int n)
   {
      int i;
      for(i=0;i<n;i++)
        printf("%d\t",ar[i]);
      printf("\n");
   }
