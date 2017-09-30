//To Implement Hash Table
#include<stdio.h>
#include<math.h>
int n,a[100]={0} ,i=0,d,c1,c2;
int hash(int e)
{
	return e%n;
}
int linear(int e)
{
	int h,k;
	h=hash(e);
	k=hash(h+i);
	if(a[k]==0)
	{
		a[k]=e;

		return;
	}
	else
	{
		i++;
		linear(e);
	}
}
int quad(int e)
{
	int h,k;
	h=hash(e)+(c1*i)+(c2*i*i);
	k=hash(h);
	//printf("\nK : %d ",k);
	if(a[k]==0)
	{
		a[k]=e;
		return ;
	}
	else
	{
		i=i+1;
		//printf("\nI : %d",i);
		quad(e);
		d=k   ;
	}
}
void main()
{
	int e,j,ch,k,h;
	printf("\nEnter Size of Array : ");
	scanf("%d",&n);
	do
	{
		printf("\n:MENU:\n1)Insert Elements Using Linear Probing\n2)Insert Elements Using Quadratic Probing\n3)Exit \nEnter Choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("\nEnter No Of Elements ");
				scanf("%d",&k);
				for(j=0;j<k;j++)
				{
					printf("\nEnter Element : ");
					scanf("%d",&e);
					i=0;
					linear(e);
				}
				printf("\n|~|Final Array|~|\n\nPositions : ");
				for(j=0;j<n;j++)
				{
					if(a[j]!=0)
					{
						printf("  %d  ",j);
					}
				}
				printf("\nElements : ");
				for(j=0;j<n;j++)
				{
					if(a[j]!=0)
					{
						printf("  %d ",a[j]);
					}
				}
			break;
			case 2:
				printf("\nEnter No Of Elements ");
				scanf("%d",&k);
				printf("\nEnter Values of c1 : ");
				scanf("%d",&c1);
				printf("\nEnter Values of c2 : ");
				scanf("%d",&c2);
				for(j=0;j<k;j++)
				{
					printf("\nEnter Element : ");
					scanf("%d",&e);
					i=0;
					quad(e);
				}
				printf("\n|~|Final Array|~|\n\nPostions : ");
				for(j=0;j<n;j++)
				{
					if(a[j]!=0)
			{
						printf("  %d  ",j);
					}
				}
				printf("\nElements : ");
				for(j=0;j<n;j++)
				{
					if(a[j]!=0)
					{
						printf("  %d ",a[j]);
					}
				}

			break;
		}
	}while(ch!=3);
}
