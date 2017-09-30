#include<stdio.h>
#define max 20
int top1=-1;
int top2=20;
int stack[20];
void push();
void pop();
void peep();
void isfull();
void isempty();
void display();
void main()
   {
     int ch;
     do
      {
        printf("\tMENU\n");
        printf("1.PUSH\n2.POP\n3.PEEP\n4.ISFULL\n5.ISEMPTY\n6.DISPLAY\n7.EXIT\nENTER YOUR OPTION:\n");
        scanf("%d",&ch);
        switch(ch)
           {
             case 1 :push();break;
             case 2 :pop();break;
             case 3 :peep();break;
             case 4 :isfull();break;
             case 5 :isempty();break;
             case 6 :display();break;
             case 7 :break;
             default:printf("INVALID OPTION\n");
                     break;
           }
       }while(ch!=7);
   }
void push()
   {
     int item,ch;
     if(top1==top2-1)
        {
          printf("OVERFLOW\n");
          return;
        }
      printf("ENTER ELEMENT TO BE INSERTED:\n");
      scanf("%d",&item);
      printf("CHOOSE STACK :\n1.STACK 1\n2.STACK 2\n");
      scanf("%d",&ch);
      if(ch==1)
         stack[++top1]=item;
      else
         stack[--top2]=item;
      return;
   }
void pop()
   {
     int ch;
     printf("CHOOSE STACK :\n1.STACK 1\n2.STACK 2\n");
     scanf("%d",&ch);
     if(ch==1)
         if(top1==-1)
            printf("UNDERFLOW\n");
         else
           {
            printf("DELETED :%d\n",stack[top1]);
            top1--;            
           }
      else if(ch==2)
         if(top2==max)
            printf("UNDERFLOW\n");
         else
           {
            printf("DELETED :%d\n",stack[top2]);
            top2++;
           }
      else
         printf("INVALID OPTION\n");
   }
void peep()
    {
     int ch;
     printf("CHOOSE STACK :\n1.STACK 1\n2.STACK 2\n");
     scanf("%d",&ch);
     if(ch==1)
         printf("TOPMOST ELEMENT :%d\n",stack[top1]);
     else if(ch==2)
         printf("TOPMOST ELEMENT :%d\n",stack[top2]);
     else
         printf("INVALID OPTION\n");
   }
void isfull()
   {
     if(top1==top2-1)
        printf("ARRAY STACK IS FULL\n");
     else
        printf("ARRAY STACK IS NOT FULL\n");
   }
void isempty()
   {
     if((top1==-1) && (top2==max))
        printf("ARRAY STACK IS EMPTY\n");
     else
        printf("ARRAY STACK IS NOT EMPTY\n");
   }
void display()
   {
     int i;
     if(top1==-1)
        printf("STACK 1 IS EMPTY\n");
     else
       {
        printf("STACK 1 :\n");
        for(i=0;i<=top1;i++)
           printf("%d\n",stack[i]);
       }
     if(top2==max)
        printf("STACK 2 IS EMPTY\n");
     else
       {
        printf("STACK 2 :\n");
        for(i=max-1;i>=top2;i--)
           printf("%d\n",stack[i]);
       }
   }
