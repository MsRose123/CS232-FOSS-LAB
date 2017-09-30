#include<stdio.h>
int delheap(int heap[10],int n);
void main()
   {
     int heap[10],ar[10],pos,par,item,temp,n,i,k;
     printf("ENTER SIZE OF HEAP :\n");
     scanf("%d",&n);
     printf("ENTER ELEMENTS TO BE INSERTED :\n");
     for(i=1;i<=n;i++)
      {
        scanf("%d",&heap[i]);
        pos=i;
        while(pos>1)
          {
            par=pos/2;
            if(heap[pos]<=heap[par])
              break;
            else
              {
                temp=heap[pos];
                heap[pos]=heap[par];
                heap[par]=temp;
                pos=par;
              }
           }
         }
        printf("HEAP BEFORE SORT :\n");
        for(i=1;i<=n;i++)
           printf("%d\t",heap[i]);
        printf("\n");
        k=n;
        for(i=n;i>=1;i--)
           ar[k--]=delheap(heap,i);
        printf(" HEAP AFTER SORT :\n");
        for(i=1;i<=n;i++)
           printf("%d\t",ar[i]);
        printf("\n");
    }
int delheap(int heap[10],int n)
     {            
            int item,temp,ptr,left,right,last;
            item=heap[1];
            last=heap[n];
            n--;
            ptr=1;
            left=2;
            right=3;
            heap[ptr]=last;
            while(left<=n)
              {
                if((heap[ptr]>=heap[left])&&(heap[ptr]>=heap[right]))
                     return item;
                else if(heap[left]>=heap[right])
                   {
                     temp=heap[ptr];
                     heap[ptr]=heap[left];
                     heap[left]=temp;
                     ptr=left;
                   }
                else
                   {
                     temp=heap[ptr];
                     heap[ptr]=heap[right];
                     heap[right]=temp;
                     ptr=right;
                   }
               left=2*ptr;
               right=left+1;
               }
            return item;
      }
                     
