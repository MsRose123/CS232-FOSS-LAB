#include<stdio.h>
#include<stdlib.h>
struct node
   {
     int coeff;
     int exp;
     struct node *next;
   }*start1=NULL,*start2=NULL,*start3=NULL,*start4=NULL,*newnode;
struct node * rep(int n,struct node *start);
void add(struct node *start1,struct node *start2);
void multiply(struct node *start1,struct node *start2);
void display(struct node *start);
void main()
   {
     int ch,n1,n2;
     printf("ENTER NUMBER OF TERMS OF FIRST  POLYNOMIAL:\n");
     scanf("%d",&n1);
     start1=rep(n1,start1);
     printf("ENTER NUMBER OF TERMS OF SECOND POLYNOMIAL:\n");
     scanf("%d",&n2);
     start2=rep(n2,start2);
     do
      {
        printf("WHICH OPERATION DO U WANT TO PERFORM:\n");
        printf("1.ADDITION\n2.MULTIPLICATION\n3.EXIT\n");
        printf("ENTER YOUR CHOICE:\n");
        scanf("%d",&ch);
        switch(ch)
           {
             case 1 :add(start1,start2);break;
             case 2 :multiply(start1,start2);break;
             case 3 :break;
             default:printf("INVALID OPTON\n");
                     break;
           }
      }while(ch!=3);
   }
struct node * rep(int n,struct node *start)
   {
     int i,c,e;
     struct node *ptr;
     for(i=0;i<n;i++)
       {
         printf("ENTER VALUES OF COEFFICENT & EXPONENT:\n");
         scanf("%d%d",&c,&e);
         newnode=(struct node *)malloc(sizeof(struct node));
         newnode->coeff=c;
         newnode->exp=e;
         newnode->next=NULL;
         if(start==NULL)
            {
              start=newnode;
              ptr=start;
            }
          else
            {
              ptr->next=newnode;
              ptr=newnode;
            }
        }
      display(start);
      return start;

   }
void display(struct node *start)
      {
         struct node *ptr=start;
         if(start==NULL)
           printf("EMPTY LINKED LIST\n");
         else
          {
            while(ptr!=NULL)
             {
               if(ptr->next==NULL)
                   printf("%dx^%d",ptr->coeff,ptr->exp);
               else
                   printf("%dx^%d+",ptr->coeff,ptr->exp);
               ptr=ptr->next;
           }
         printf("\n");
        }
    }
void add(struct node *start1,struct node *start2)
     {
       struct node *ptr1,*ptr2,*ptr3;
       ptr1=start1;
       ptr2=start2;
       while(ptr1!=NULL&&ptr2!=NULL)
         {
           newnode=(struct node*)malloc(sizeof(struct node));
           if(ptr1->exp==ptr2->exp)
              {
                newnode->coeff=ptr1->coeff+ptr2->coeff;
                newnode->exp=ptr1->exp;
                newnode->next=NULL;
                if(start3==NULL)
                   {
                     start3=newnode;
                     ptr3=start3;
                   }
                else
                   {
                     ptr3->next=newnode;
                     ptr3=newnode;
                   }
                ptr1=ptr1->next;
                ptr2=ptr2->next;
              }
           else if(ptr1->exp > ptr2->exp)
                  {
                    newnode->coeff=ptr1->coeff;
                    newnode->exp=ptr1->exp;
                    newnode->next=NULL;
                    if(start3==NULL)
                      {
                        start3=newnode;
                        ptr3=start3;
                      }
                    else
                      {
                        ptr3->next=newnode;
                        ptr3=newnode;
                      }
                    ptr1=ptr1->next;
                  }
            else if(ptr1->exp < ptr2->exp)
                  {
                    newnode->coeff=ptr2->coeff;
                    newnode->exp=ptr2->exp;
                    newnode->next=NULL;
                    if(start3==NULL)
                      {
                        start3=newnode;
                        ptr3=start3;
                      }
                    else
                      {
                        ptr3->next=newnode;
                        ptr3=newnode;
                      }
                    ptr2=ptr2->next;
                  }
          }
         while(ptr1!=NULL)
              {
                 newnode=(struct node *)malloc(sizeof(struct node));
                 newnode->coeff=ptr1->coeff;
                 newnode->exp=ptr1->exp;
                 newnode->next=NULL;
                 if(start3==NULL)
                      {
                        start3=newnode;
                        ptr3=start3;
                      }
                 else
                      {
                        ptr3->next=newnode;
                        ptr3=newnode;
                      }
                 ptr1=ptr1->next;
              }
          while(ptr2!=NULL)
             {
                 newnode=(struct node *)malloc(sizeof(struct node));
                 newnode->coeff=ptr2->coeff;
                 newnode->exp=ptr2->exp;
                 newnode->next=NULL;
                 if(start3==NULL)
                      {
                        start3=newnode;
                        ptr3=start3;
                      }
                 else
                      {
                        ptr3->next=newnode;
                        ptr3=newnode;
                      }
                 ptr2=ptr2->next;
             }
         display(start3);
        }
void multiply(struct node *start1,struct node *start2)
        {
           struct node *ptr1,*ptr2,*ptr4,*ptr5;
           int coef,ex,flag=0;
           if(start1==NULL||start2==NULL)
              {
                printf("RESULTANT POLYNOMIAL IS : 0\n");
                return;
              }
           ptr1=start1;
           while(ptr1!=NULL)
           {       
                   ptr2=start2;
                   while(ptr2!=NULL)
                   {  
                       flag=0;
                       coef=ptr1->coeff*ptr2->coeff;
                       ex=ptr1->exp+ptr2->exp;
                       if(start4==NULL)
                        {
                         newnode=(struct node *)malloc(sizeof(struct node));
                         newnode->coeff=coef;
                         newnode->exp=ex;
                         newnode->next=NULL;
                         start4=newnode;
                        }
                       else
                        {
                         ptr4=start4;
                         while(ptr4 != NULL)
                         {
                           if(ptr4->exp==ex)
                             { 
                                ptr4->coeff+=coef;
                                flag=1;
                           
                             }
                           ptr4=ptr4->next;
                         }
                         if(flag==0)
                           { 
                             newnode=(struct node *)malloc(sizeof(struct node));
                             newnode->coeff=coef;
                             newnode->exp=ex;
                             newnode->next=NULL;
                             ptr5=start4;
                             while(ptr5->next!=NULL)
                                ptr5=ptr5->next;
                             ptr5->next=newnode;
                            }
                         }
                         ptr2=ptr2->next;
                   }
                  ptr1=ptr1->next;
          }
          printf("\nRESULTANT POLYNOMIAL : ");
          display(start4);
     }


