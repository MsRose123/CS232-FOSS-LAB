#include<stdio.h>
#include<conio.h>

struct node
{
	int data;
	struct node *l,*r;
}*root=NULL,*ptr,*newnode,*loc,*par,*save,*parsuc,*suc,*child;
void find(int item)
{
	if(root==NULL)
	{
		loc=NULL;
		par=NULL;
	//	printf("\nLoc : %d",loc->data);
		//break;
		return;
	}
	if(item==root->data)
	{
		loc=root;
		par=NULL;
      //		printf("\nRoot :  %d ",root->data);
		return;
	}
	if(item<root->data)
	{
		ptr=root->l;
		save=root;
	}
	else
	{	ptr=root->r;
		save=root;
	}
	while(ptr!=NULL)
	{
		if (item==ptr->data)
		{
			loc=ptr;
			par=save;
    //			printf("\nLoc : %d Par : %d",loc->data,par->data);
			break;
			//return ;
		}
		else
		{
			if(item<ptr->data)
			{
				save=ptr;
				ptr=ptr->l;
			}
			else
			{
				save=ptr;
				ptr=ptr->r;
			}
		}
	}
	loc=NULL;
	par=save;
}
void display(struct node* ptr)
{
	if(ptr!=NULL)
	{
		display(ptr->l);
		printf("%d ",ptr->data);
		display(ptr->r);
	}
}
int height(struct node *tree)
{
	int lh,rh;
	if (tree==NULL)
		return 0;
	else
	{
		lh=height(tree->l);
		rh=height(tree->r);
		if(lh>rh)
			return lh+1;
		else
			return rh+1;
	}
}
void insertbst()
{
	int n,item,i;
	printf("\nEnter Value of n : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter Value : ");
		scanf("%d",&item);
		find(item);
		if(loc!=NULL)
			printf("\n\nCant Be Inserted As Element Already Present ");
		else
		{
			newnode=(struct node *)malloc(sizeof(struct node));
			loc=newnode;
			newnode->data=item;
			newnode->l=newnode->r=NULL;
			if(par==NULL)
			{
				root=newnode;
  //				printf("\nRoot : %d",root->data);
			}
			else if(item<par->data)
				par->l=newnode;
			else
				par->r=newnode;
		}
	}
	printf("\n\n|~|BINARY TREE->INORDER TRAVERSAL|~|\n\n");
	display(root);
	printf("\n");
}
void casea(struct node *lo,struct node * p)
{
	if((lo->l==NULL)&&(lo->r==NULL))
		child=NULL;
	else if(lo->l!=NULL)
		child=lo->l;
	else
		child=lo->r;
	if (p!=NULL)
	{
		if(lo==p->l)
			p->l=child;
		else
			p->r=child;
	}
	else
		root=child;
}
void caseb(struct node *lo,struct node *p)
{
	ptr=lo->r;
	save=lo;
	while(ptr->l!=NULL)
	{
		save=ptr;
		ptr=ptr->l;
	}
	suc=ptr;
	parsuc=save;
	casea(suc,parsuc);
	if(p!=NULL)
		if(lo==p->l)
			p->l=suc;
		else
			p->r=suc;
	else
		root=suc;
	suc->l=lo->l;
	suc->r=lo->r;
}
void del()
{
	int item;
	printf("\nEnter the Element To Be Deleted : ");
	scanf("%d",&item);
	find(item);
	if(root->data==item)
		loc=root;
	else if(par->l->data==item)
		loc=par->l;
	else
		loc=par->r;
//	printf("\nDelete Par : %d Loc : %d ",par->data,loc->data);
	if(loc==NULL)
		printf("\nElement Not Present");
	else if((loc->r!=NULL)&&(loc->l!=NULL))
		caseb(loc,par);
	else
		casea(loc,par);
	printf("\n\n|~|BINARY TREE->INORDER TRAVERSAL|~|\n\n");
	display(root);
	printf("\n");
}
void mirror(struct node *tree)
{
	struct node *ptr;
	if(tree!=NULL)
	{
		mirror(tree->l);
		mirror(tree->r);
		ptr=tree->l;
		tree->l=tree->r;
		tree->r=ptr;
	}
}
void main()
{
	int c,item,x;
	do
	{
		printf("\n|-|MENU|-|\n\\n1)Insert A New Node\n2)Delete A Node\n3)Search For Node \n4)Mirror Image\n5)Height Of Tree\n6)Display Tree\n7)Exit\n\nEnter Choice : ");
		scanf("%d",&c);
		switch(c)
		{
			case 1: insertbst();
			break;
			case 2: del();
				printf("\nRoot : %d",root->data);
			break;
			case 3:
				printf("\nEnter Item To Be Found : ");
				scanf("%d",&item);
				find(item);
				if(root->data==item)
					printf("\n\nItem Found");
				else if(par->l->data==item)
					printf("\n\nItem Found");
				else if(par->r->data==item)
					printf("\n\nItem Found ");
				else
					printf("\n\nItem Not Found");

			break;
			case 4:mirror(root);
			break;
			case 5:x=height(root);
				printf("\nHeight : %d \n",x);
			break;
			case 6:
				printf("\n\n|~|BINARY SEARCH TREE|~|\n\n");
				display(root);
				printf("\n");
			break;
		}
	}while(c!=7);
}
