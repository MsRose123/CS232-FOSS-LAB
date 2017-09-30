#include<stdio.h>
struct node
   {
     int data;
     struct note *next;
   }*ptr,*preptr,*start=NULL;
struct node* ins_beg(struct node * start);
struct node* ins_end(struct node * start);
struct node* ins_aft(struct node * start);
struct node* del_beg(struct node * start);
struct node* del_end(struct node * start);
struct node* del_spf(struct node * start);
void display(struct node *start);
void insertion();
void deletion();
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
               case 1 :insertion();break;
               case 2 :deletion();break;
               case 3 :if(start==NULL)
                          printf("EMPTY LINKED LIST\n");
                       else
                        {
                          display(start);break;
                        }
               case 4 :break;
               default:printf("INVALID OPTION\n");
                       break;
            }
         }while(ch!=4);
   }
void insertion()
  {
    int ch;
    printf("\tINSERTION\n");
    do 
     {
        printf("1.INSERTION AT THE BEGINING\n2.INSERTION AT THE END\n3.INSERTION AFTER A SPECIFIED NODE\n4.EXIT\n");
        printf("ENTER YOUR OPTION:\n");
        scanf("%d",&ch);
        switch(ch)
           {
             case 1 :ins_beg(start);
                     break;
             case 2 :ins_end(start);
                     break;
             case 3 :ins_aft(start);
                     break;
             case 4 :break;
             default:printf("INVALID OPTION\n");break;
           }
     }while(ch!=4);
  }
void deletion()
  {
        int ch;
        printf("\tDELETION\n");
        do
         {
            printf("1.DELETION AT THE BEGINING\n2.DELETION AT THE END\n3.DELETION OF A SPECIFIED NODE\n4.EXIT\n");
            printf("ENTER YOUR OPTION:\n");
            scanf("%d",&ch);
            switch(ch)
               {
                   case 1 :del_beg(start);break;
                   case 2 :del_end(start);break;
                   case 3 :del_spf(start);break;
                   case 4 :break;
                   default:printf("INVALID OPTION\n");break;
               }
            }while(ch!=4);
   }
void displayln()
     { 
       if(start==NULL)
         printf("EMPTY LINKED LIST\n");
       else
        {
          printf("LINKED LIST IS :\n");
          display(start);
        }
     } 
struct node* ins_beg(struct node * start)
    { 
      struct node *newnodea;
      int x;
      printf("ENTER ELEMENT TO BE INSERTED\n");
      scanf("%d",&x);
      newnodea=(struct node*)malloc(sizeof(struct node));
      newnodea->data=x;
      newnodea->next=NULL;
      if(start==NULL)
         start=newnodea;
      else 
       {
        newnode->next=start;
        start=newnodea;
       }
      return start;
     }
struct node* ins_end(struct node * start)
   {
      struct node *newnodeb;
      int x;
      printf("ENTER ELEMENT TO BE INSERTED\n");
      scanf("%d",&x);
      newnodeb=(struct node*)malloc(sizeof(struct node));
      newnodeb->data=x;
      newnodeb->next=NULL;
      ptr=start;
      while(ptr->next!=NULL)
        ptr=ptr->next;
      ptr->next=newnodeb;
      return start;
   }
struct node* ins_aft(struct node * start)
   { 
     struct node *newnodec;
     int num;
      int x;
      printf("ENTER ELEMENT TO BE INSERTED\n");
      scanf("%d",&x);
      newnodec=(struct node*)malloc(sizeof(struct node));
      newnodec->data=x;
      newnodec->next=NULL;
      printf("ENTER DATA OF NODE AFTER WHICH NEW NODE TO BE INSERTED\n");
      scanf("%d",&num);
      ptr=start;
      while(ptr->data!=num)
        ptr=ptr->next;
      newnodec->next=ptr->next;
      ptr->next=newnodec;
      return start;
   }
struct node* del_beg(struct node* start)
   {
     if(start==NULL)
       printf("EMPTY LINKED LIST\n");
     else
      {
         ptr=start;
         start=start->next;
         free(ptr);
      }
     return start;
   }
struct node* del_end(struct node* start)
   {
     if(start==NULL)
       printf("EMPTY LINKED LIST\n");
     else
      {
        ptr=start;
        while(ptr->next!=NULL)
         {
           preptr=ptr;
           ptr=ptr->next;
         }
      free(ptr);
      preptr->next=NULL;
      return start;
      }
  }
struct node* del_spf(struct node* start)
   {
    if(start==NULL)
      printf("EMPTY LINKED LIST\n");
    else
      {
        int num;
        printf("ENTER ELEMENT TO BE DELETED:\n");
        scanf("%d",&num);
        ptr=start;
        while(ptr->data!=num)
         {
           preptr=ptr;
           ptr=ptr->next;
         }
        if(ptr==NULL)
          printf("ELEMENT NOT PRESENT\n");
        else
          {
            preptr->next=ptr->next;
            free(ptr);
          }
       }
     return start;
   }
void display(struct node * start)
   {
    ptr=start;
    while(ptr!=NULL)
      {
        printf("%d-->",ptr->data);
        ptr=ptr->next;
      }
   }
 

     

