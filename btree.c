#include<stdio.h>
#include<stdlib.h>
struct tree
  {
    struct tree *left;
    int data;
    struct tree *right;
  }*root=NULL,*newnode,*image=NULL,*par=NULL;
void builttree(struct tree *ptr,int key);
struct tree * search(struct tree *ptr,int key);
struct tree * findpar(struct tree *ptr,int item);
struct tree * mirror(struct tree *ptr);
int height(struct tree *ptr);
void inorder(struct tree *ptr);
void postorder(struct tree *ptr);
void preorder(struct tree *ptr);
void traversals();
void main()
   {
     int ch,item,p,h,opt;
     struct tree *ptr;
     do
       {
         printf("\tMENU\n");
         printf("1.BUILD TREE\n2.INSERT A NEW NODE\n3.DELETE A NODE\n4.SEARCH FOR A NODE\n5.FIND HEIGHT OF BINARY TREE\n6.TRAVERSALS\n7.MIRROR IMAGE\n8.EXIT\n");
         printf("ENTER YOUR OPTION :\n");
         scanf("%d",&ch);
         switch(ch)
           {
             case 1 :printf("ENTER DATA OF ROOT NODE:\n");
                     scanf("%d",&item);
                     newnode=(struct tree *)malloc(sizeof(struct tree));
                     newnode->left=NULL;
                     newnode->right=NULL;
                     root=newnode;
                                          /* OR Assign root->data=item; and pass only builttree(root); */
                     builttree(root,item);
                     break;
             case 2 :printf("ENTER DATA TO BE INSERTED :\n");
                     scanf("%d",&item);
                     printf("ENTER DATA OF PARENT NODE :\n");
                     scanf("%d",&p);
                     ptr=search(root,p);
                     if(ptr==NULL)
                       printf("ELEMENT DOESNT EXIST \n");
                     else
                       {  
                         printf("CHOOSE :\n1.LEFT CHILD\n2.RIGHT CHILD\n");
                         scanf("%d",&opt);
                         if(opt==1)
                           if(par->left!=NULL)
                               printf("INSERTION NOT POSSIBLE .LEFT CHILD ALREDY EXIST\n");
                            else
                              {
                                newnode=(struct tree *)malloc(sizeof(struct tree));
                                newnode->data=item;
                                newnode->left=NULL;
                                newnode->right=NULL;
                                par->left=newnode;
                              }
                         else if(opt==2)
                            if(par->right!=NULL)
                               printf("INSERTION NOT POSSIBLE .RIGHT CHILD ALREDY EXIST\n");
                             else
                               {
                                 newnode=(struct tree *)malloc(sizeof(struct tree));
                                 newnode->data=item;
                                 newnode->left=NULL;
                                 newnode->right=NULL;
                                 par->right=newnode;
                               }
                         else
                            printf("INVALID OPTION\n");
                        }
                     break;
             case 3 :printf("ENTER TO BE DELETED :\n");
                     scanf("%d",&item);
                     ptr=search(root,item);
                     if(ptr==NULL)
                       printf("ELEMENT DOESNT EXIST\n");
                     else
                       {
                         par=findpar(root,item);
                         if(par->left->data==item)
                            par->left=NULL;
                         else if(par->right->data==item)
                            par->right=NULL;
                         free(ptr);
                         printf("BINARY TREE IS :\n");
                         inorder(root);  
                       }
                     break;
             case 4 :printf("ENTER ELEMENT TO BE SEARCHED :\n");
                     scanf("%d",&item);
                     ptr=search(root,item);
                     if(ptr==NULL)
                       printf("UNSUCCESFUL SEARCH\n");
                     else
                       printf("SUCCESFUL SEARCH.\n%d PRESENT IN BINARY TREE.\n",item);
                     break;
             case 5 :h=height(root);
                     if(h==0)
                       printf("BINARY TREE DOESNT EXIST\n");
                     else
                       printf("HEIGHT OF BINARY TREE IS : %d\n",h);
                     break;
             case 6 :traversals();break;
             case 7 :image=mirror(root);
                     printf("BINARY TREE IS :\n");
                     inorder(root);
                     printf("MIRROR IMAGE IS :\n");
                     inorder(image);
                     break;
             case 8 :break;
             default:printf("INVALID OPTION\n");
                     break;
           }
        }while(ch!=8);
    }
void builttree(struct tree *ptr,int key)
   {
     int ch,item;
     if(ptr!=NULL)                          /* OR if(ptr=NULL) return; */
       ptr->data=key;
     else
       return;
     printf("DOES %d HAS A LEFT CHILD :\n",key);
     printf("0.NO\n1.YES\n");
     scanf("%d",&ch);
     if(ch==1)
      {
        printf("ENTER ELEMENT TO BE INSERTED :\n");
        scanf("%d",&item);
        newnode=(struct tree *)malloc(sizeof(struct tree));
        newnode->left=NULL;                                         /* OR newnode->data=item; */
        newnode->right=NULL;
        ptr->left=newnode;
        builttree(newnode,item);
      }
     else
       ptr->left=NULL;
     printf("DOES %d HAS A RIGHT CHILD :\n0.NO\n1.YES\n",key);
     scanf("%d",&ch);
     if(ch==1)
      {
         printf("ENTER ELEMENT TO BE INSERTED :\n");
         scanf("%d",&item);
         newnode=(struct tree *)malloc(sizeof(struct tree));
         newnode->left=NULL;
         newnode->right=NULL;
         ptr->right=newnode;
         builttree(newnode,item);
      }
     else
       ptr->right=NULL;
  }
struct tree * search(struct tree *ptr,int key)
  {
    struct tree *found=NULL;
    if(ptr==NULL)
       return NULL;
    else if(ptr->data==key)
       return ptr;
    found=search(ptr->left,key);
    if(found !=NULL)
      return found;
    found=search(ptr->right,key);
    if(found !=NULL)
      return found;
    return NULL;
   }
struct tree * findpar(struct tree *ptr,int item)
   {
     struct tree *ptr1,*ptr2;
     if(ptr->data !=item)
        {
          par=ptr;
          ptr1=ptr->left;
          ptr2=ptr->right;
          if(ptr1 != NULL)
            {
              par=findpar(ptr1,item);
              if(par !=NULL)
                return par;
            }
          if(ptr2 != NULL)
            {
              par=findpar(ptr2,item);
              if(par!=NULL)
                return par;
            }
          return NULL;
        }
      else
        return par;
   }
struct tree * mirror(struct tree *ptr)
   {
     struct tree * newnode=NULL;
     if(ptr==NULL)
       return NULL;
     newnode=(struct tree *)malloc(sizeof(struct tree));
     newnode->data=ptr->data;
     newnode->left=mirror(ptr->right);
     newnode->right=mirror(ptr->left);
     return newnode;
   }
int height(struct tree *ptr)
   {
     int l=0,r=0;
     if(ptr==NULL)
       return ;
     l=height(ptr->left)+1;
     r=height(ptr->right)+1;
     if(l>r)
       return l;
     else
       return r;
   }
void inorder(struct tree *ptr)
   {
     if(ptr!=NULL)
      {
        inorder(ptr->left);
        printf("%d\n",ptr->data);
        inorder(ptr->right);
      }
   }
void postorder(struct tree *ptr)
   {
     if(ptr!=NULL)
      {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d\n",ptr->data);
      }
    }
void preorder(struct tree *ptr)
   {
     if(ptr!=NULL)
      {
       printf("%d\n",ptr->data);
       preorder(ptr->left);
       preorder(ptr->right);
      }
   }
void traversals()
   {
     int ch;
     do
       {
         printf("\tDISPLAY :\n1.INORDER DISPLAY\n2.PREORDER DISPLAY\n3.POSTORDER DISPLAY\n4.EXIT\nENTER YOUR OPTION :\n");
         scanf("%d",&ch);
         switch(ch)
           {
             case 1 :printf("INORDER BINARY TREE :\n");
                     inorder(root);
                     break;
             case 2 :printf("PREORDER BINARY TREE :\n");
                     preorder(root);
                     break;
             case 3 :printf("POSTORDER BINARY TREE :\n");
                     postorder(root);
                     break;
             case 4 :break;
             default:printf("INVALID OPTION \n");
                     break;
           }
        }while(ch!=4);
   }
