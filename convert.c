#include<stdio.h>
const int max=20;
int stack[20];
int top=-1;
void push()
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
    display();
  }
void pop()
  {
    if(top==-1)
       printf("UNDERFLOW\n");
    else
     {
       top--;
       display();
     }
  }
void peep()
  {
    printf("TOPMOST ELEMENT IS %d :\n",stack[top]);
  }
void display()
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
void main()
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
          case 1 :push();break;
          case 2 :pop();break;
          case 3 :peep();break;
          case 4 :isempty();break;
          case 5 :isfull();break;
          case 6 :display();break;
          case 7 :break;
          default:printf("INVALID OPTION\n");
                  break;
        }
      }while(ch!=7);
  }

