#include<stdio.h>
int a[50],size;
void builttree(int i,int item);
int search(int key,int pos,int i);
void main()
   {
     int ch,item,x,h;
     printf("ENTER HEIGHT OF BINARY TREE :\n");
     scanf("%d",&h);
     size=pow(2,h)-1;
     do
     {
      printf("\tMENU\n");
      printf("1.BUILD BINARY TREE\n2.DELETE A NODE\n3.SEARCH A NODE\n4.EXIT\nENTER YOUR OPTION :\n");
      scanf("%d",&ch);
      switch(ch)
        {
          case 1 :printf("ENTER ELEMENT TO BE INSERTED :\n");
                  scanf("%d",&item);
                  builttree(1,item);
                  break;
          case 2 :printf("ENTER ELEMENT TO BE DELETED :\n");
                  scanf("%d",&item);
                  x=search(item,0,1);
                  if(x==0)
                    printf("ELEMENT DOESNT EXIST\n");
                  else if((a[2*x])||(a[2*x+1]))
                    printf("NOT A LEAF NODE.SO,CANNOT BE DELETED\n");
                  else
                    a[x]=0;
                  break;
          case 3 :printf("ENTER ELEMENT TO BE SEARCHED\n");
                  scanf("%d",&item);
                  x=search(item,0,1);
                  if(x==0)
                     printf("UNSUCCESFUL SEARCH\n");
                  else
                     {
                       printf("SUCCESFUL SEARCH \n");
                       printf("%d PRESENT AT POSITION %d OF THE BINARY TREE\n",item,x);
                     }
                  break;
          case 4 :break;
          default:printf("INVALID OPTION \n");
                  break;
       }
      }while(ch != 4);
   }
void builttree(int i,int item)
   {
     int opt,elem;
     if(i!=0)
       a[i]=item;
     else
       return;
     printf("DOES NODE %d HAS A LEFT CHILD :\n",i);
     printf("1. YES\n0. NO\n");
     scanf("%d",&opt);
     if(opt==1)
       {
        printf("ENTER ELEMENT TO BE INSERTED :\n");
        scanf("%d",&elem);
        builttree(2*i,elem);
       }
     else
       builttree(0,0);
     printf("DOES NODE %d HAS A RIGHT CHILD :\n",i);
     printf("1. YES\n0. NO\n");
     scanf("%d",&opt);
     if(opt==1)
       {
        printf("ENTER ELEMENT TO BE INSERTED :\n");
        scanf("%d",&elem);
        builttree(2*i+1,elem);
       }
     else
       builttree(0,0);
   }
int search(int key,int pos,int i)
   {
     if(pos !=0)
       return pos;
     else
       {
        if(a[i] != key)
         {
          if(2*i<=size)
            pos=search(key,pos,2*i);
          if(2*i+1<=size)
            pos=search(key,pos,2*i+1);
          else
            return 0;
         }
        else
           return i;
       }
   }
