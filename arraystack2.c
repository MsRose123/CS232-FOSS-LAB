#include<stdio.h>
const int max=20;
int push(int stack[20],int top)
  {
    if(top>=max-1)
       printf("OVERFLOW\n");
    else
     {
      int item;
      printf("ENTER ELEMENT TO BE INSERTED:\n");
      scanf("%d",&item);
      top++;
      stack[top]=item;
     }
    display(stack,top);
    return top;
  }
int pop(int stack[20],int top)
  {
    if(top==-1)
        printf("UNDERFLOW\n");
    else
     {
       top--;
       display(stack,top);
     }
    return top;
  }
void peep(int stack[20],int top)
  {
    printf("TOPMOST ELEMENT IS:\n");
    printf("%d",stack[top]);
  }
void isempty(int stack[20],int top)
  {
    if(top==-1)
      printf("STACK IS EMPTY\n");
    else
     {
      printf("STACK IS NOT EMPTY\n");
      display(stack,top);
     }
  }
void isfull(int stack[20],int top)
  {
    if(top>=max-1)
      printf("STACK IS FULL\n");
    else
      printf("STACK IS NOT FULL\n");
        display(stack,top);
  }
void display(int stack[20],int top)
  {
    if(top==-1)
      printf("STACK IS EMPTY\n");
    else
     {
      int i;
      printf("STACK IS:\n");
      for(i=0;i<=top;i++)
        printf("%d\t",stack[i]);
      printf("\n");
     }
  }
int operation(int stack[20],int top)
  {
    int ch; 
    do
     {
      printf("\tMENU\n");
      printf("1.PUSH\n2.POP\n3.PEEP\n4.ISEMPTY\n5.ISFULL\n6.DISPLAY\n7.EXIT\n");
      printf("ENTER YOUR OPTION:\n");
      scanf("%d",&ch);
      switch(ch)
        {
          case 1 :push(stack,top);break;
          case 2 :pop(stack,top);break;
          case 3 :peep(stack,top);break;
          case 4 :isempty(stack,top);break;
          case 5 :isfull(stack,top);break;
          case 6 :display(stack,top);break;
          case 7 :break;
          default:printf("INVALID OPTION\n");
                          break;
        }
      }while(ch!=7);
     return top;
  }     
void main()
  {
    int ch,stack1[20],stack2[20],top1=-1,top2=-1;
    do
     {
      printf("CHOOSE STACK:\n");
      printf("1.STACK 1\n2.STACK 2\n3.EXIT\n");
      printf("ENTER YOUR OPTION:\n");
      scanf("%d",&ch);
      switch(ch)
         {
           case 1 :operation(stack1,top1);break;
           case 2 :operation(stack2,top2);break;
           case 3 :break;
           default:printf("INVALID OPTION\n");
                   break;
         }
      }while(ch!=3);
  }
