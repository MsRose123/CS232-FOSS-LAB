#include<stdio.h>
#include<omp.h>
#define n 5
void main()
{
   int id,i,j,k,a[5][5],b[5][5],c[5][5],d[5][5],p;
   p=omp_get_num_threads();
   printf("TOTAL NO OF THREADS = %d \n",p);
   printf("ENTER ELEMENTS OF 5X5 MATRIX A :\n");
   for(i=0;i<n;i++)
     {
      for(j=0;j<n;j++)
         scanf("%d",&a[i][j]);
      printf("\n");
     }
   /*TRANSPOSE OF A */
   #pragma omp parallel num_threads(5*5)
    {
     id=omp_get_thread_num();
     printf("USED THREAD ID : %d WITH %d THREADS \n",id,omp_get_num_threads());
           d[id]=a[id];
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
          scanf("%d",&b[i][j]);
      printf("\n");
     }
   /*SUM OF MATRIX A TRANSPOSE AND MATRIX B */
   #pragma omp parallel num_threads(5*5)
     {
      id=omp_get_thread_num();
      printf("THREAD ID = %d WITH %d THREADS \n",id,omp_get_num_threads());
      c[id]=d[id]+b[id];
     }
   printf("SUM OF MATRICES :\n");
   for(i=0;i<n;i++)
      {
       for(j=0;j<n;j++)
          printf("%d\t",c[i][j]);
       printf("\n");
      }
}

