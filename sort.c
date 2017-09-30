#include<stdio.h>
void bubble(int ar[10],int n);
void selection(int ar[10],int n);
void insertion(int ar[10],int n);
int linearserch(int ar[10],int n,int item);
int binaryserch(int ar[10],int n,int item);
int min(int ar[10],int k,int n);
void display(int ar[10],int n);
void main()
   {
     int ar[10],ch,i,n,item,pos;
     printf("ENTER SIZE OF ARRAY :\n");
     scanf("%d",&n);
     printf("ENTER ELEMENTS :\n");
     for(i=0;i<n;i++)
       scanf("%d",&ar[i]);
     do
       {
         printf("\tMENU\n");
         printf("1.BUBBLE SORT\n2.INSERTION SORT\n3.SELECTION SORT\n4.LINEAR SEARCH\n5.BINARY SEARCH\n6.EXIT\nENTER YOUR OPTION :\n");
         scanf("%d",&ch);
         switch(ch)
             {
               case 1 :printf("BUBBLE SORT :\n");
                       bubble(ar,n);
                       display(ar,n);
                       break; 
               case 2 :printf("INSERTION SORT :\n");
                       insertion(ar,n);
                       display(ar,n); 
                       break;
               case 3 :printf("SELECTION SORT :\n");
                       selection(ar,n);
                       display(ar,n); 
                       break;
               case 4 :printf("ENTER ELEMENT TO BE SEARCHED :\n");
                       scanf("%d",&item);
                       pos=linearserch(ar,n,item);
                       if(pos==-1)
                         printf("UNSUCCESFUL SEARCH \n");
                       else
                         {
                           printf("SUCCESFUL SEARCH\n");
                           printf("%d PRESENT AT POSITION %d OF THE ARRAY\n",item,pos);                 
                         } 
                       break;
               case 5 :printf("BINARY SEARCH WORKS ONLY FOR SORTED ARRAY\n");
                       printf("ENTER ELEMENT TO BE SEARCHED :\n");
                       scanf("%d",&item);
                       pos=binaryserch(ar,n,item);
                       if(pos==-1)
                           printf("UNSUCCESFUL SEARCH\n");
                       else
                          {
                            printf("SUCCESFUL SEARCH\n");
                            printf("%d PRESENT AT POSITION %d OF THE ARRAY\n",item,pos);
                          }
                       break;
               case 6 :break;
               default:printf("INVALID OPTION\n");break;
             }
       }while(ch!=6);
   }
void bubble(int ar[10],int n)
   {
     int i,j,temp;
     for(i=0;i<n;i++)
        for(j=0;j<n-1-i;j++)
           if(ar[j+1]<ar[j])
             {
               temp=ar[j];
               ar[j]=ar[j+1];
               ar[j+1]=temp;
             }
   }
void insertion(int ar[10],int n)
   {
      int i,k,temp;
      for(k=1;k<n;k++)
        {
          temp=ar[k];
          i=k-1;
          while(temp<ar[i] && i>=0)
             ar[i+1]=ar[i--];
          ar[i+1]=temp;
        }
   }
void selection(int ar[10],int n)
   {   
      int k,temp,pos;
      for(k=0;k<n;k++)
       {
         pos=min(ar,k,n);
         temp=ar[k];
         ar[k]=ar[pos]; 
         ar[pos]=temp;
       }
   }
int min(int ar[10],int k,int n)
   {
     int i,small,pos;
     small=ar[k];
     pos=k;
     for(i=k+1;i<n;i++)
       if(ar[i]<small)
         {
           small=ar[i];
           pos=i;
         }
     return pos;
   }
int linearserch(int ar[10],int n,int item)
   {
     int i,pos;
     for(i=0;i<n;i++)
         if(ar[i]==item)
           return i;
     return -1;
   }
int binaryserch(int ar[10],int n,int item)
   {
     int beg,mid,end;
     beg=0;
     end=n-1;
     while(beg<=end)
       {
         mid=(beg+end)/2;
         if(ar[mid]==item)
            return mid;
         else if(item>ar[mid])
            beg=mid+1;
         else 
            end=mid-1;
       }
      return -1;
   }
void display(int ar[10],int n)
   {
     int i; 
     printf("SORTED ARRAY :\n");
     for(i=0;i<n;i++)
        printf("%d\t",ar[i]);
     printf("\n");
   }
