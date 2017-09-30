nclude<stdio.h>
#include<conio.h>
void display(int b[],int n )
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",b[i]);
	}
}
void bubble(int c[],int n)
{
	int tmp,i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(c[j]>c[j+1])
			{
				tmp=c[j];
				c[j]=c[j+1];
				c[j+1]=tmp;
			}
		}
	}
	printf("\nThe Array After Bubble Sort ");
	display(c,n);
}
void selection(int d[],int n)
{
	int i,j,min,pos,tmp;
	for(i=0;i<n;i++)
	{
		min=d[i];
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(min>d[j])
			{
				min=d[j];
				pos=j;
			}

		}
			tmp=d[i];
			d[i]=d[pos];
			d[pos]=tmp;
	}
	printf("\nThe Array After Selection Sort ");
	display(d,n);
}
void insertion(int e[],int n)
{
	int i,j,tmp;
	for(i=1;i<n;i++)
	{
		tmp=e[i];
		j=i-1;
		while(tmp<e[j]&&j>-1)
		{
			e[j+1]=e[j];
			j--;
		}
		e[j+1]=tmp;
	}
	printf("\nThe Array After Insertion Sort ");
	display(e,n);
}
int binarysearch(int p[],int n)
{
	int item,beg,end,mid,flag=0;
	int pos;
	printf("\nEnter The Item To Be Searched For : ");
	scanf("%d",&item);
	beg=0;
	end=n-1;
	mid=(beg+end)/2  ;
	while(beg<=end)
	{
		if(p[mid]==item)
			return 1;
		else if(p[mid]<item)
			beg=mid+1;
		else
			end=mid-1;
		mid=(beg+end)/2;
	}
	return 0;
}
void main()
{
	int a[10],i,n,ch,x;
	clrscr();
	do
	{
		printf("\n\nMenu\n\n1.Create\n2.Display\n3.Bubble Sort\n4.Selection Sort\n5.Insertion Sort\n6.Binary Search ");
		printf("\n7)Exit\n\nEnter The Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter The No Of Elements : ");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				scanf("%d",&a[i]);
			break;
			case 2:display(a,n);
			break;
			case 3:bubble(a,n);
			break;
			case 4:selection(a,n);
			break;
			case 5:insertion(a,n);
			break;
			case 6:
			{
				x=binarysearch(a,n);
				if(x==1)
					printf("\nItem Is Found ");
				else
					printf("\nItem Is Not Found");
			}
			break;
		}
	}while(ch!=7);
	getch();
}
