#include<stdio.h>
#define max 5
int q[max],l=-1,r=-1;
void input();
void output();
void insleft();
void insright();
void delleft();
void delright();
void display();
void main()
   {
     int ch;
     do
       {
        printf("\tMENU\n");
        printf("1.INPUT RESTRICTED DEQUE\n2.OUTPUT RESTRICTED DEQUE\n3.DISPLAY\n4.EXIT\n");
        printf("ENTER YOUR OPTION :\n");scanf("%d",&ch);
        switch(ch)
           {
             case 1 :input();break;
             case 2 :output();break; 
             case 3 :display();break;
             case 4 :break;
             default:printf("INVALID OPTION\n");break;
           }
       }while(ch!=4);
   }
void input()
   {
     int ch;
     do
      {
        printf("CHOOSE OPERATION :\n");
        printf("1.INSERTION AT RIGHT\n2.DELETION AT LEFT\n3.DELETION AT RIGHT\n4.EXIT\n");scanf("%d",&ch);
        switch(ch)
          {
            case 1 :insright();break;
            case 2 :delleft();break;
            case 3 :delright();break;
            case 4 :break;
            default:printf("INVALID OPTION \n");break;
          }
       }while(ch!=4);
   }
void output()
   {
     int ch;
     do
      {
        printf("CHOOSE OPERATION :\n");
        printf("1.INSERTION AT LEFT\n2.INSERTION AT RIGHT\n3.DELETION AT LEFT\n4.EXIT\n");scanf("%d",&ch);
        switch(ch)
          {
            case 1 :insleft();break;
            case 2 :insright();break;
            case 3 :delleft();break;
            case 4 :break;
            default:printf("INVALID OPTION \n");break;
          }
       }while(ch!=4);
   }
void insleft()
   {
     int item;
     printf("ENTER ELEMENT TO BE INSERTED :\n");scanf("%d",&item);
     if((l==r+1) ||(l==0 && r==max-1))
      {  printf("OVERFLOW\n");return;}
     else if(l==-1)
        l=r=0;
     else
        l=(l+1)%max;
     q[l]=item;
   }
void insright()
   {
     int item;
     printf("ENTER ELEMENT TO BE INSERTED :\n");scanf("%d",&item);
     if(r==l-1)
       {
         printf("OVERFLOW\n");
         return;
       }
     else if(r==-1)
       l=r=0;
     else
       r=(r+1)%max;
     q[r]=item;
   }
void delleft()
   {
     if(l==-1)
         printf("UNDERFLOW\n");
     else if(l==r)
         l=r=-1;
     else
         l=(l+1)%max;
   }
void delright()
   {
     if(r==-1)
        printf("UNDERFLOW\n");
     else if(l==r)
        l=r=-1;
     else
        r=(r+1)%max;
   }
void display()
   {
     int i;
     for(i=l;i!=r;i=(i+1)%max)   
        printf("%d\n",q[i]);
     printf("%d\n",q[i]);
   }
     
   
         

