#include<stdio.h>
#include<stdlib.h>
struct node
    {
      int data;
      struct node *next;
    }*top=NULL,*newnode,*ptr;
void stack();
void queue();
void main()
    {
      int ch;
      struct node *top=NULL;
      do
        {
          printf("\tMENU\n");
          printf("1.STACK\n2.QUEUE\n3.EXIT\n");
          printf("ENTER YOUR OPTION:\n");
          scanf("%d",&ch);
          switch(ch)
            {
              case 1 :stack();break;
              case 2 :queue();break;
              case 3 :break;
              default:printf("INVALID OPTION\n");
                      break;
            }
         }while(ch!=3);
    }
void stack()
    {
      struct node *top=NULL;
      
