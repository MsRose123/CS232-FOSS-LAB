#include<stdio.h>
#include<stdlib.h>
struct node 
     {
       int data;
       struct node *prev;
       struct node *next;
     }*start=NULL,*newnode,*ptr;
void insert()
   {
      int ch;
      printf("\tINSERTION\n");
      do
        {
          printf("1.INSERTION AT THE BEGINING\n2.INSERTION AT THE END\n3.INSERTION AFTER A SPECIFIC NODE\n4.EXIT\n");
          printf("ENTER YOUR OPTION:\n");
          scanf("%d",&ch);
          switch(ch)
             {
                case 1 :insert1();break;
                case 2 :insert2();break;
                case 3 :insert3();break;
                case 4 :break;
                default:printf("INVALID OPTION\n");
                        break;
             }
          }while(ch!=4);
   }
void delete()
    {
       int ch;
       printf("\tDELETION\n");
       do
         {
           printf("1.DELETION AT THE BEGINING\n2.DELETION AT THE END\n3.DELETION OF A SPECIFID NODE\n4.EXIT\n");
           printf("ENTER YOUR OPTION:\n");
           scanf("%d",&ch);
           switch(ch)
              {
                 case 1 :delete1();break;
                 case 2 :delete2();break;
                 case 3 :delete3();break;
                 case 4 :break;
                 default:printf("INVALID OPTION\n");
                         break;
               }
           }while(ch!=4);
    }
void display()
    {
      int ch;
      printf("\tDISPLAY\n");
      do
        {
          printf("1.FORWARD DISPLAY\n2.BACKWARD DISPLAY\n3.EXIT\n");
          printf("ENTER YOUR OPTION:\n");
          scanf("%d",&ch);
          switch(ch)
             {
                case 1 :fdisplay();break;
                case 2 :bdisplay();break;
                case 3 :break;
                default:printf("INVALID OPTION\n");
                        break;
             }
         }while(ch!=3);
     }
void insert1()
    {
      int num;
      printf("INSERTION AT BEGINING\n");
      printf("ENTER DATA TO BE INSERTED:\n");
      scanf("%d",&num);
      newnode=(struct node *)malloc(sizeof(struct node));
      newnode->data=num;
      newnode->prev=NULL;
      newnode->next=NULL;
      if(start==NULL)
         start=newnode;
      else
       {
        newnode->next=start;
        start->prev=newnode;
        start=newnode;
       }
      fdisplay();
     }
void insert2()
    {
      int num;
      printf("INSERTION AT END\n");
      printf("ENTER DATA TO BE INSERTED:\n");
      scanf("%d",&num);
      newnode=(struct node *)malloc(sizeof(struct node));
      newnode->data=num;
      newnode->prev=NULL;
      newnode->next=NULL;
      if(start==NULL)
         start=newnode;
      else
        {
         ptr=start;
         while(ptr->next!=NULL)
            ptr=ptr->next;
         ptr->next=newnode;
         newnode->prev=ptr;
        }
      fdisplay();
     }
void insert3()
    {
      int num,x;
      printf("INSERTION AFTER A SPECIFIC NODE\n");
      printf("ENTER DATA TO BE INSERTED:\n");
      scanf("%d",&num);
      printf("ENTER DATA OF NODE AFTER WHICH NEW NODE TO BE INSERTED:\n");
      scanf("%d",&x);
      newnode=(struct node *)malloc(sizeof(struct node));
      newnode->data=num;
      newnode->prev=NULL;
      newnode->next=NULL;
      ptr=start;
      while(ptr->data!=x)
         ptr=ptr->next;
      if(ptr==NULL)
        printf("ELEMENT NOT FOUND\n");
      else
      {
        newnode->prev=ptr;
        newnode->next=ptr->next;
        ptr->next->prev=newnode;
        ptr->next=newnode;
      }
      fdisplay();
    }
void delete1()
    {
      printf("DELETION AT BEGINING\n");
      ptr=start;
      start=start->next;
      start->prev=NULL;
      free(ptr);
      fdisplay();
    }
void delete2()
    {
      printf("DELETION AT THE END\n");
      ptr=start;
      while(ptr->next!=NULL)
          ptr=ptr->next;
      ptr->prev->next=NULL;
      free(ptr);
      fdisplay();
    }
void delete3()
    {
      int x;
      printf("DELETION OF A SPECIFIC NODE\n");
      printf("ENTER DATA OF NODE TO BE DELETED:\n");
      scanf("%d",&x);
      ptr=start;
      while(ptr->data!=x)
        ptr=ptr->next;
      if(ptr==NULL)
        printf("ELEMENT NOT FOUND\n");
      else
      {
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
        free(ptr);
      }
      fdisplay();
    }
void fdisplay()
    {
      printf("LINKED LIST IN FORWARD ORDER\n");
      ptr=start;
      while(ptr!=NULL)
         {
          if(ptr->next==NULL)
             printf("%d\n",ptr->data);
          else
             printf("%d->",ptr->data);
          ptr=ptr->next;
         }
    }
void bdisplay()
    {
      printf("LINKED LIST IN BACKWARD ORDER\n");
      ptr=start;
      while(ptr->next!=NULL)
             ptr=ptr->next;
      while(ptr!=NULL)
           {
             if(ptr->prev==NULL)
                printf("%d\n",ptr->data);
             else
                printf("%d->",ptr->data);
             ptr=ptr->prev;
           }
     }
void main()
   {
     int ch;
     do
      {
        printf("\tMENU\n");
        printf("1.INSERTION\n2.DELETION\n3.DISPLAY\n4.EXIT\n");
        printf("ENTER YOUR OPTION:\n");
        scanf("%d",&ch);
        switch(ch)
          {
            case 1 :insert();break;
            case 2 :delete();break;
            case 3 :display();break;
            case 4 :break;
            default:printf("INVALID OPTION\n");
                    break;
          }
       }while(ch!=4);
   }

