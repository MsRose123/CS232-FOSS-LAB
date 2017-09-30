/*menu driven c program to implement linked stack and linked queue*/
#include<stdio.h>
#include<stdlib.h>
struct node
   {
     int data;
     struct node *next;
   }*ptr,*newnode;
struct node *stack();
struct node *queue();
struct node *spush(struct node *top);
struct node *spop(struct node *top);
void sdisplay(struct node *top);
struct node *qpush(struct node *front,struct node *rear,int x);
struct node *qpop(struct node *front,struct node *rear);
void qdisplay(struct node *front,struct node *rear);
struct node *stack()
   {
     struct node *a=NULL;
     int ch;
     do
      {
        printf("\tSTACK\n");
        printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        printf("ENTER YOUR OPTION :\n");
        scanf("%d",&ch);
        switch(ch)
           {
             case 1 :a=spush(a);
                     break;
             case 2 :a=spop(a);
                     break;
            case 3 :sdisplay(a);
                    break;
            case 4 :break;
            default:printf("INVALID OPTION\n");
                    break;
          }
      }while(ch!=4);
   }
struct node *queue()
   {
     struct node *b=NULL;
     struct node *c=NULL;
     int ch,item;
     do
      {
        printf("\tQUEUE\n");
        printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        printf("ENTER YOUR OPTION :\n");
        scanf("%d",&ch);
        switch(ch)
           {
             case 1 :printf("ENTER ELEMENT TO BE INSERTED :\n");
                     scanf("%d",&item); 
                     if(c==NULL)
                      {
                        c=qpush(b,c,item);
                        b=c;
                      }
                     else
                       c=qpush(b,c,item);
                     break;
             case 2 :b=qpop(b,c);
                     break;
            case 3 :qdisplay(b,c);
                    break;
            case 4 :break;
            default:printf("INVALID OPTION\n");
                    break;
          }
      }while(ch!=4);
   }
struct node *spush(struct node *top)
   {
     int item;
     printf("ENTER ELEMENT TO BE INSERTED:\n");
     scanf("%d",&item);
     newnode=(struct node *)malloc(sizeof(struct node));
     newnode->data=item;
     newnode->next=NULL;
     if(top==NULL)
        top=newnode;
     else
       {
        newnode->next=top;
        top=newnode;
       }
     sdisplay(top);
     return top;
   }
struct node *spop(struct node *top)
   {
     if(top==NULL)
       printf("UNDERFLOW\n");
     else
      {
        ptr=top;
        top=top->next;
        free(ptr);
        sdisplay(top);
      }
     return top;
   }
void sdisplay(struct node *top)
   {
      if(top==NULL)
        printf("STACK IS EMPTY\n");
      else
        {
          printf("STACK IS:\n");
          ptr=top;
          while(ptr!=NULL)
            {
              if(ptr->next==NULL)
                 printf("%d",ptr->data);
              else
                 printf("%d->",ptr->data);
              ptr=ptr->next;
            }
         }
      printf("\n");
    }
struct node *qpush(struct node *front,struct node *rear,int x)
   { 
     printf("#1") ;
     newnode=(struct node *)malloc(sizeof(struct node));
     newnode->data=x;
     newnode->next=NULL;
     printf("#2");
     if(front==NULL && rear==NULL)
          front=rear=newnode;
     else
       {
         rear->next=newnode;
         rear=newnode;
       }
     qdisplay(front,rear);
     return rear;
   }
struct node *qpop(struct node *front,struct node *rear)
   {
     if(front==NULL)
        printf("UNDERFLOW\n");
     else
      { 
        ptr=front;
        front=front->next;
        free(ptr);
        qdisplay(front,rear);
      }
     return front;
   }
void qdisplay(struct node *front,struct node *rear)
   { 
     if(rear==NULL)
        printf("QUEUE IS EMPTY\n");
     else
       {
         ptr=front;
         while(front!=NULL)
          {
            if(front->next==NULL)
              printf("%d",ptr->data);
            else
              printf("%d->",ptr->data);
            ptr=ptr->next;
          }
      }
    printf("\n");
  }
void main()
   {
     int ch;
     do
      {
        printf("\tMENU\n");
        printf("1.STACK\n2.QUEUE\n3.EXIT\n");
        printf("ENTER YOUR CHOICE:\n");
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
