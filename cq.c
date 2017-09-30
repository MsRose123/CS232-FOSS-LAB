#include<stdio.h>
#define max 5
int que[max];
int f=-1,r=-1;
void enque()
   {
     int item;
     if(isfull())
       printf("OVERFLOW\n");
     else
       {
         printf("ENTER ELEMENT TO BE INSERTED :\n");
         scanf("%d",&item);
         if(f==-1)
           f=0;
         r=(r+1)%max;
         que[r]=item;
       }
   }
void deque()
   {
     if(isempty())
       printf("UNDERFLOW\n");
     else
       {
         printf("DELETED ELEMENT :%d\n",que[f]);
         if(f==-1)
            f=r=-1;
         else
            f=(f+1)%max;
       }
   }
int isfull()
   {
     if((f==r+1)||(f==0 && r==max-1))
         return 1;
      return 0;
   }
int isempty()
   {
     if(f==-1)
        return 1;
     return 0;
   }
void display()
   {
     int i;
     if(isempty())
       printf("QUEUE IS EMPTY\n");
     else
       {
         printf("QUEUE IS :\n");
         for(i=f;i!=r;i=(i+1)%max)
             printf("%d\n",que[i]);
         printf("%d\n",que[i]);
       }
   }
void main()
   {
     int ch,x;
     do
      {
        printf("\tMENU\n");
        printf("1.ENQUEUE\n2.DEQUEUE\n3.ISFULL\n4.ISEMPTY\n5.DISPLAY\n6.EXIT\n");
        printf("ENTER YOUR OPTION :\n");
        scanf("%d",&ch);
        switch(ch)
           {
             case 1 :enque();break;
             case 2 :deque();break;
             case 3 :x=isfull();
                     if(x==1)
                       printf("QUEUE IS FULL\n");
                     else
                       printf("QUEUE IS NOT FUL\n");      
                     break;
            case 4 :x=isempty();
                    if(x==1)
                       printf("QUEUE ISEMPTY \n");
                    else
                       printf("QUEUE IS NOT EMPTY\n");
                    break;
            case 5 :display();break;
            case 6 :break;
            default:printf("INVALID OPTION\n");break;
         }
      }while(ch!=6);
   }
   
