nclude<stdio.h>
#include<stdlib.h>

typedef struct node 							//For Creating Adjacency list
{
	int data;
	struct node *next;
}adj;

int search(int a[],int n,int item)					//Linear Search
{
	int i;
	for (i=0;i<n;++i)
		if (a[i]==item)
			return 1;
	return 0;
}

void main()
{
	int V[10],E[45][3],visit[10],q[10],front=-1,rear=-1,n,i,j,k,ch,ch1,ch2,node,e,count,flag,stack[10],vn=0,top=-1;
	adj *link[10],*ptr,*new;
	do
	{
	a:
	for (i=0;i<10;++i)  //Initialising Adjacency list with NULL value
	   link[i]=NULL;
	printf("\n\t\t1. Input Details of the graph.");
	printf("\n\t\t2. Exit.");
	printf("\n\t\tEnter the choice: ");
	scanf("%d",&ch2);
	switch (ch2)
	{
	   case 1:
		printf("\n\t\t\tEnter the number of vertices of the graph: ");
		scanf("%d",&n);
		for (i=0;i<n;++i)			//Read the vertices
		{
			printf("\n\t\tVertex %d: ",i+1);
			scanf("%d",&V[i]);
		}
		k=0,e=0;
		for (i=0;i<n;++i)			//Reading the Adacency matrix(in sparse rep) and Adjacency List
		{
		 link[i]=(adj*)malloc(sizeof(adj));
		 link[i]->data=V[i];
		 link[i]->next=NULL;
		 for(j=0;j<n;++j)
	       	 {
		   printf("\n\t\tIs there an edge from %d to %d (0/1): ",V[i],V[j]);
		   scanf("%d",&ch);
                   if (ch==1)
		    {
			E[k][0]=V[i];
			E[k][1]=V[j];
			E[k][2]=1;
			k++;
			e++;
		        ptr=link[i];
		        while (ptr->next!=NULL)
			ptr=ptr->next;
			new=(adj*)malloc(sizeof(adj));
			new->data=V[j];
			new->next=NULL;
			ptr->next=new;
	             }
		  }
		}
		do
		{
		  flag=1;
		  printf("\n\n\t\t\t\tGRAPH MENU...");
		  printf("\n\t\t1. In degree of a particular node.");
		  printf("\n\t\t2. Out degree of a particular node. ");
		  printf("\n\t\t3. DFS.");
		  printf("\n\t\t4. BFS.");
		  printf("\n\t\t5. Display using Adjacency List. ");
		  printf("\n\t\t6. Display using Adjacency Matrix. ");
		  printf("\n\t\t7. Go back to previous Menu.");
		  printf("\n\t\tEnter the choice: ");
		  scanf("%d",&ch);
		  count=0;
		  switch(ch)
		   {
			case 1:
			        printf("\n\t\t\tEnter the node: ");
				scanf("%d",&node);
				for(i=0;i<e;++i)	//Counting number of links to node
				if(E[i][1]==node)
			        	count++;
				if (count==0)
					flag=search(V,n,node);
				if (flag==0)
					printf("\n\t\t\t%d is not a vertex.",node);
				else
			        	printf("\n\t\t\tIn degree of %d: %d",node,count);
					break;
			case 2:
				printf("\n\t\t\tEnter the node: ");
				scanf("%d",&node);
				for(i=0;i<e;++i)	//Counting number of links out of node
				  if(E[i][0]==node)
					count++;
			       	  if (count==0)
					flag=search(V,n,node);
				  if (flag==0)
					printf("\n\t\t\t%d is not a vertex.",node);
			       	  else
					printf("\n\t\t\tOut degree of %d: %d",node,count);
				  break;
			case 3:
				vn=0;			//Number of nodes in visit[]
				printf("\n\t\t\tDFS TRAVERSAL...\n");
				stack[++top]=V[0];
				while(top!=-1)
				{
				  ch1=stack[top--];
				  flag=search(visit,vn,ch1);
	       			  if (flag==0)//Displaying unvisited nodes and appending it to visit
				    {
					printf("\t%d",ch1);
					visit[vn++]=ch1;
                 		    }
	        	          for (i=0;i<e;++i)
				    {
					if (E[i][0]==ch1)
					{
					  flag=search(visit,vn,E[i][1]);
			               	  if (flag==0)
						stack[++top]=E[i][1];
					}
					if (E[i][1]==ch1)
					{
						flag=search(visit,vn,E[i][0]);
						if (flag==0)
		    	         		stack[++top]=E[i][0];
					}
				      }
				    }
	        	            break;
			case 4:
							vn=0,front=rear=0;
							printf("\n\t\t\tBFS TRAVERSAL...\n");
							if (front==-1 &&  rear==-1)
								front=rear=0;
							q[rear++]=V[0];
							while(front!=-1)
							{
									ch1=q[front++];
									flag=search(visit,vn,ch1);
									if (flag==0)
									{
										printf("\t%d",ch1);
										visit[vn++]=ch1;
									}
									for (i=0;i<e;++i)
									{
										if (E[i][1]==ch1)
										{
											flag=search(visit,vn,E[i][0]);
											if (flag==0)
												q[rear++]=E[i][0];
										}
										if (E[i][0]==ch1)
										{
											flag=search(visit,vn,E[i][1]);
											if (flag==0)
												q[rear++]=E[i][1];
										}
									}
									if (front==rear)
										front=rear=-1;
							}
							break;
						case 5:
							printf("\n\t\t\t\tGRAPH REPRESENTATION USING ADJACENCY LIST...\n");
							printf("\n\t{ ");
							for(i=0;i<n;++i)		//Printing set rep from adjacency list
							{
								ptr=link[i]->next;
								while (ptr!=NULL)
								{
									printf(" (%d,%d) ",link[i]->data,ptr->data);
									ptr=ptr->next;
								}
							}
							printf("}\n");
							break;
						case 6:

							printf("\n\t\t\t\tGRAPH REPRESENTATION USING ADJACENCY MATRIX...\n");
							printf("\n\t{ ");
							for(i=0;i<e-1;++i)		//Printing set rep from adjacency matrix
								printf(" (%d,%d),",E[i][0],E[i][1]);
							printf("(%d,%d) }\n",E[i][0],E[i][1]);

							break;
						case 7:
							goto a;
					}
				}while(1);
			case 2:
				return;
			default:
				printf("\n\tWRONG CHOICE MADE");
		}
	}while(1);
}
