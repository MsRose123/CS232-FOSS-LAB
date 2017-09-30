#include<stdio.h>
#include<stdlib.h>
struct tree
  {
    struct tree *left;
    int data;
    struct tree *right;
  }*root=NULL,*newnode,*par=NULL;
void builttree(struct tree *ptr,int key);
struct tree * search(struct tree *ptr,int key);
struct tree * findpar(struct tree *ptr,int item);
void inorder(struct tree *ptr);
void main()
   {
     int ch,item,opt,p;
     struct tree *ptr;
     printf("\tBUILD TREE\n");
     printf("ENTER DATA OF ROOT NODE:\n");
     scanf("%d",&item);
     newnode=(struct tree *)malloc(sizeof(struct tree));
     newnode->left=NULL;           
     newnode->right=NULL;         
     root=newnode;  
     builttree(root,item);
     do
       {
         printf("\tMENU\n");
         printf("1.INSERT A NEW NODE\n2.DELETE A NODE\n3.SEARCH FOR A NODE\n4.DISPLAY\n5.EXIT\n");
         printf("ENTER YOUR OPTION :\n");
         scanf("%d",&ch);
         switch(ch)
           {
             case 1 :printf("ENTER DATA TO BE INSERTED :\n");
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
                           {
                           if(ptr->left!=NULL)
                               printf("INSERTION NOT POSSIBLE .LEFT CHILD ALREDY EXIST\n");
                            else
                              {
                                newnode=(struct tree *)malloc(sizeof(struct tree));
                                newnode->data=item;
                                newnode->left=NULL;
                                newnode->right=NULL;
                                ptr->left=newnode;
                              }
                            }
                         else if(opt==2)
                            if(ptr->right!=NULL)
                               printf("INSERTION NOT POSSIBLE .RIGHT CHILD ALREDY EXIST\n");
                             else
                               {
                                 newnode=(struct tree *)malloc(sizeof(struct tree));
                                 newnode->data=item;
                                 newnode->left=NULL;
                                 newnode->right=NULL;
                                 ptr->right=newnode;
                               }
                         else
                            printf("INVALID OPTION\n");
                        }
                     printf("BINARY TREE IS :\n");
                     display(root);
                     break;
             case 2 :printf("ENTER DATA TO BE DELETED :\n");
                     scanf("%d",&item);
                     ptr=search(root,item);
                     if(ptr==NULL)
                       printf("ELEMENT DOESNT EXIST\n");
                     else
                       {
                         par=findpar(root,item);
                         if(par->left || par->right)
                           {
                            printf("NOT A LEAF NODE .SO,CANNOT BE DELETED\n");
                            break;
                           }
                         else if(par->left->data==item)
                            par->left=NULL;
                         else if(par->right->data==item)
                            par->right=NULL;
                         free(ptr);
                       }
                     printf("BINARY TREE IS :\n");
                     display(root);
                     break;
             case 3 :printf("ENTER ELEMENT TO BE SEARCHED :\n");
                     scanf("%d",&item);
                     ptr=search(root,item);
                     if(ptr==NULL)
                       printf("UNSUCCESFUL SEARCH\n");
                     else
                       printf("SUCCESFUL SEARCH.\n%d PRESENT IN BINARY TREE.\n",item);
                     break;
             case 4 :display(root);
                     break;
             case 5 :break;
             default:printf("INVALID OPTION\n");
                     break;
           }
        }while(ch!=5);
    }
void builttree(struct tree *ptr,int key)
   {
     int ch,item;
     if(ptr != NULL)
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
        newnode->left=NULL;                                      
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
        return ptr;
   }
void display(struct tree *ptr)
   {
     if(ptr!=NULL)
      {
        display(ptr->left);
        printf("%d\n",ptr->data);
        display(ptr->right);
      }
   }

