#include<stdio.h>
int x[30],n,aux[30],temp[30];
void merge1()
{
int size,l1,l2,u1,u2,i,j,k;
size=1;
while(size<n)
{
l1=0;
k=0;
while(l1+size<n)
{
l2=l1+size;
u1=l2-1;
u2=(l2+size<n)?l2+size-1:n-1;

for(i=l1,j=l2;i<=u1&&j<=u2;k++)
{
if(x[i]<=x[j])
	aux[k]=x[i++];
else
	aux[k]=x[j++];
}
for(;i<=u1;k++)
	aux[k]=x[i++];
for(;j<=u2;k++)
	aux[k]=x[j++];
l1=u2+1;
}
for(i=l1;i<n;i++)
	aux[k++]=x[i];
for(i=0;i<n;i++)
	x[i]=aux[i];
size=size*2;
}
for(i=0;i<n;i++)
	printf("%d\t",x[i]);
}
void merge(int beg,int mid,int end)
{
	int i,j,h,k,f;
	i=beg;
	j=mid+1;
	h=0;
	while((i<=mid)&&(j<=end))
	{
		if(x[i]<x[j])
			temp[h++]=x[i++];
		else
			temp[h++]=x[j++];
	}
	while(j<=end)
		temp[h++]=x[j++];
	while(i<=mid)
		temp[h++]=x[i++];
	for(k=beg,f=0;k<=end;k++,f++)
	{

		//printf("\nT : %d ",temp[k]);
		x[k]=temp[f];
	}
	//g=k;
}
void mergesort(int beg,int end)
{
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		mergesort(beg,mid);
		mergesort(mid+1,end);
		merge(beg,mid,end);
	}
}
void main()
{
int ch,i;
printf("Enter the no of elements:");
scanf("%d",&n);
printf("Enter the values:");
for(i=0;i<n;i++)
	scanf("%d",&x[i]);
do
{
printf("\n1.merge non recursiver\n2.merge recursive\nenter choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
	merge1();
	break;
case 2:mergesort(0,n-1);
	printf("\nSorted Array : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",temp[i]);
	}
	break;
default:printf("Invalid\n");
	break;
}
}while(ch!=0);
}




