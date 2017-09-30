#include<stdio.h>
#include<stdlib.h>
struct node
   {
     int data;
     struct node *next;
   }*ptr,*newnode;
struct node *queue();
struct node *qpush(struct node *front,struct node *rear);
struct node *qpop(struct node *front,struct node *rear);
void qdisplay(struct node *front,struct node *rear);
struct node *queue()
   {
     struct node *b=NULL;
     struct node *c=NULL;
     int ch;
     do
      {
        printf("\tQUEUE\n");
        printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        printf("ENTER YOUR OPTION :\n");
        scanf("%d",&ch);
        switch(ch)
           {
             case 1 :if(c==NULL)
                      {
                        c=qpush(b,c);
                        b=c;
                      }
                     else
                       c=qpush(b,c);
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
struct node *qpush(struct node *front,struct node *rear)
   {
     int x;
     newnode=(struct node *)malloc(sizeof(struct node));
     printf("ENTER ELEMENT TO BE INSERTED:\n");
     scanf("%d",&x);
     printf("#1");
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
        printf("1.QUEUE\n2.EXIT\n");
        printf("ENTER YOUR CHOICE:\n");
        scanf("%d",&ch);
        switch(ch)
           {
             case 1 :queue();break;
             case 2 :break;
             default:printf("INVALID OPTION\n");
                     break;
           }
      }while(ch!=2);
   }
                                   
