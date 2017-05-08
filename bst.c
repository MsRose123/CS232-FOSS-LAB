#include<stdio.h>
#include<stdlib.h>
struct tree
   {
     int data;
     struct tree *left,*right;
   }*newnode,*ptr,*loc,*par,*root=NULL;
void insbst(int item);
void delbst(int item);
void findbst(int item);
void mirrorimage();
void height();
void leafcound();
void rectraversals();
void nonrectraversals();
void rinorder(struct tree *ptr);
void rpreorder(struct tree *ptr);
void rpostorder(struct tree *ptr);
void nonrinorder();
void nonrpreorder();
void nonrpostorder();
void casea();
void caseb();
void main()
   {
     int ch,item;
     printf("CREATE A BINARY SEARCH TREE :\n");
     while(ch!=0)
      {
        printf("ENTER ELEMENT TO BE INSERTED :\n");
        scanf("%d",&item);
        insbst(item);
        printf("ENTER :\n0.EXIT\n1.CONTINUE\n");
        scanf("%d",&ch);
      }
     do
      {
       printf("\tMENU\n");
       printf("1.INSERTION\n2.DELETION\n3.SEARCH FOR A SPECIFIED NODE\n4.MIRROR IMAGE\n5.HEIGHT OF BST\n6.RECCURSIVE TRAVERSALS\n7.NON-RECCURSIVE TRAVERSALS\n8.COUNT NO. OF LEF NODES\n9.EXIT\n");
       printf("ENTER YOUR OPTION :\n");
       scanf("%d",&ch);
       switch(ch)
         {
           case 1 :printf("ENTER ELEMENT TO BE INSERTED :\n");
                   scanf("%d",&item);
                   insbst(item);
                   break;
           case 2 :printf("ENTER ELEMENT TO BE DELETED :\n");
                   scanf("%d",&item);
                   delbst(item);
                   break;
           case 3 :printf("ENTER ELEMENT TO BE SEARCHED :\n");
                   scanf("%d",&item);
                   findbst(item);
                   break;
           case 4 :mirrorimage();
                   break;
  	   case 5 :height();
                   break;
           case 6 :rectraversals();
                   break;
           case 7 :nonrectraversals();
                   break;
           case 8 :leafcound();
                   break;
           case 9 :break;
           default:printf("INVALID OPTION\n");
                   break;
         }
      }while(ch!=9);
   }
void rectraversals()
   {
     int ch;
     do
      {
        printf("RECCURSIVE TRAVERSALS\n");
        printf("1.INORDER\n2.PREORDER\n3.POSTORDER\n4.EXIT\n");
        scanf("%d",&ch);
        switch(ch)
           {
             case 1 :rinorder(root);break;
             case 2 :rpreorder(root);break;
             case 3 :rpostorder(root);break;
             case 4 :break;
             default:printf("INVALID OPTION\n");
                     break;
          }
       }while(ch!=4);
   }
void nonrectraversals()
   { 
    int ch;
     do
      {
        printf("NON-RECCURSIVE TRAVERSALS\n");
        printf("1.INORDER\n2.PREORDER\n3.POSTORDER\n4.EXIT\n");
        scanf("%d",&ch);
        switch(ch)
           {
             case 1 :nonrinorder();break;
             case 2 :nonrpreorder();break;
             case 3 :nonrpostorder();break;
             case 4 :break;
             default:printf("INVALID OPTION\n");
                     break;
          }
       }while(ch!=4);
   }
void findbst(int item)
   {         
     struct tree *save;         
     if(root==NULL)
       {
         loc=NULL;
         par=NULL;
         return;
       }
     else if(item=root->data)
       {
         loc=root;
         par=NULL;
         return;
       }
     else if(item<root->data) 
       {
         ptr=root->left;
         save=root;
       }
     else
       {
         ptr=root->right;
         save=root;
       }
     while(ptr!=NULL)
       {
         if(item=ptr->data)
           {
             loc=ptr;
             par=save;
             return;
           }
         else if(item<ptr->data)
           {
             save=ptr;
             ptr=ptr->left;
           }
         else
           {
             save=ptr;
             ptr=ptr->right;
           }
       }
     if(ptr==NULL)
       {
         printf("UNSUCCESFUL SEARCH\n");
         loc=NULL;
         par=save;
       } 
   }
void insbst(int item)
   {
      findbst(item);
      if(loc!=NULL)
        {
          printf("%d ALREADY PRESENT IN THE BST.",item);
          return;
        }
      loc=newnode;
      newnode=(struct tree *)malloc(sizeof(struct tree));
      newnode->data=item;
      newnode->left=NULL;
      newnode->right=NULL;
      if(par==NULL)
         root=newnode;
      else if(item<par->data)
         par->left=newnode;
      else
         par->right=newnode;
   }
void delbst(int item)
   {
      findbst(item);
      if(loc==NULL)
        {
          printf("ELEMENT DOESNT EXIST\n");
          return;
        }
      if(loc->left !=NULL && loc->right !=NULL)
         caseb();
       else
         casea(loc,par);
   }      
void casea(struct tree *loc,struct tree *par)
   {
     struct tree *child;
     if(loc->left==NULL && loc->right==NULL)
         child=NULL;
     else if(loc->left!=NULL)
         child=loc->left;
     else
         child=loc->right;
     if(par!=NULL)
       if(par->left=loc)
          par->left=child;
       else
          par->right=child;
     else 
       root=child;
     free(loc);
   }
void caseb()
   {
     struct tree *save,*suc,*parsuc;
     ptr=loc->left;
     save=loc;
     while(ptr->left!=NULL)
       {
         save->data=ptr->data;
         save=ptr;
         ptr=ptr->left;
       }
     suc=ptr;
     parsuc=save;
     casea(suc,parsuc);
   }
void mirrorimage()
   {
   }
void leafcound()
   {
   }
void rinorder(struct tree *ptr)
   {
     while(ptr!=NULL)
      {
        rinorder(ptr->left);
        printf("%d\n",ptr->data);
        rinorder(ptr->right);
      }
   }
void rpreorder(struct tree *ptr)
   {
     while(ptr!=NULL)
       {
         printf("%d\n",ptr->data);
         rpreorder(ptr->left);
         rpreorder(ptr->right);
       }
   }
void rpostorder(struct tree *ptr)
   {
     while(ptr!=NULL)
       {
         rpostorder(ptr->left);
         rpostorder(ptr->right);
         printf("%d\n",ptr->data);
       }
   }
void nonrpostorder()
   {
   }
void nonrinorder()
   {
   }
void nonrpreorder()
   {
   }
void height()
   {
   }
