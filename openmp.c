#include<stdio.h>
#include<omp.h>
#define n 5
void main()
{
   int id,i,j,k,a[5][5],b[5][5],c[5][5],d[5][5];
   printf("ENTER ELEMENTS OF 5X5 MATRIX A :\n");
   for(i=0;i<n;i++)
     {
      for(j=0;j<n;j++)
         scanf("%d",&a[i][j]);
      printf("\n");
     }
   /*TRANSPOSE OF A */
   for(i=0;i<n;i++)
    {
     #pragma omp parallel
     id=omp_get_thread_num();
     printf("USED THREAD ID : %d\n",id);
        for(j=0;j<n;j++)
           d[i][j]=a[j][i];
    }
   printf("TRANSPOSE OF A :\n");
   for(i=0;i<n;i++)
      {
       for(j=0;j<n;j++)
          printf("%d\t",d[i][j]);
       printf("\n");
      }
   printf("ENTER ELEMENTS OF 5X5  MATRIX B :\n");
   for(i=0;i<n;i++)  
     {
      for(j=0;j<n;j++)
          scanf("%d",&b[i][j]);
      printf("\n");
     }
   /*SUM OF MATRIX A TRANSPOSE AND MATRIX B */
   for(i=0;i<n;i++)
     {
     #pragma omp parallel
      id=omp_get_thread_num();
      printf("THREAD ID = %d\n",id); 
      for(j=0;j<n;j++)
      {
       c[i][j]=0; 
       c[i][j]=d[i][j]+b[i][j];
      }
     }
   printf("SUM OF MATRICES :\n");
   for(i=0;i<n;i++)
      {
       for(j=0;j<n;j++)
          printf("%d\t",c[i][j]);
       printf("\n");
      }
}
