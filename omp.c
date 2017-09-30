#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void main()
{
 int rows=5,cols=5;
 int id,i,j,x[rows][cols],a[rows][cols],b[rows][cols],c[rows][cols];
 omp_set_num_threads(5);
 printf("ENTER ELEMENTS OF 5X5 MATRIX A :\n");
 for(i=0;i<rows;i++)
    for(j=0;j<cols;j++)
       scanf("%d",&x[i][j]);
 #pragma omp parallel
 {
   #pragma omp for
   for(i=0;i<rows;i++)
    {
      for(j=0;j<cols;j++)
         a[i][j]=x[j][i];
      printf("THREAD ID : %d WITH %d THREADS\n",omp_get_thread_num(),omp_get_num_threads());
    }
 }
 printf("TRANSPOSE OF MATRIX A :\n");
 for(i=0;i<rows;i++)
   {
    for(j=0;j<cols;j++)
       printf("%d\t",a[i][j]);
    printf("\n");
   }
 printf("ENTER ELEMENTS OF 5X5 MATRIX B :\n");
 for(i=0;i<rows;i++)
    for(j=0;j<cols;j++)
       scanf("%d",&b[i][j]);
 #pragma omp parallel num_threads(5)
   {
     #pragma omp for
     for(i=0;i<rows;i++)
        {
         for(j=0;j<cols;j++)
            c[i][j]=a[i][j]+b[i][j];
         printf("THREAD ID : %d\n",omp_get_thread_num());
        }
   }
 printf("RESULTANT MATRIX :\n");
 for(i=0;i<rows;i++)
   {
    for(j=0;j<cols;j++)
       printf("%d\t",c[i][j]);
    printf("\n");
   }
 }


