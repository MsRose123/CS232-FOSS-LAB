#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void main()
{
int id,i,j,rows,cols;
rows=5;
cols=5;
int a[rows][cols],b[rows][cols],c[rows][cols],x[rows][cols];
//int *d,*e,*f;
printf("ENTER ELEMENTS OF 5X5 MATRIX A :\n");
for(i=0;i<rows;i++)
  for(j=0;j<cols;j++)
    {
       scanf("%d",&x[i][j]);
    }


printf("ENTER ELEMENTS OF 5X5 MATRIX B :\n");
for(i=0;i<rows;i++)
  for(j=0;j<cols;j++)
    {
       scanf("%d",&b[i][j]);
    }

    printf("MATRIX  A :\n");
    for(i=0;i<rows;i++)
      {
      for(j=0;j<cols;j++)
           printf("%d\t",a[i][j]);
      printf("\n");
      }
      printf("MATRIX  A :\n");
      for(i=0;i<rows;i++)
        {
        for(j=0;j<cols;j++)
             printf("%d\t",b[i][j]);
        printf("\n");
        }


//pragma for TRANSPOSE operation starts here

        #pragma omp parallel num_threads(5)
        {
      #pragma omp for
      for(i=0;i<rows;i++)  //TRANSPOSE OF MATRIX A STORED IN MATRIX A
       for(j=0;j<cols;j++)
          a[i][j]=x[j][i];

          }
//pragma for TRANSPOSE operation ends here

/*d=(int *)malloc(sizeof(int)*rows*cols);
e=(int *)malloc(sizeof(int)*rows*cols);
f=(int *)malloc(sizeof(int)*rows*cols);

d=(int *)a;
e=(int *)b;
f=(int *)c;*/
/*

#pragma omp parallel num_threads(5)
  {
    id=omp_get_thread_num();
    f[id]=d[id]+e[id];
  }
  */

//pragma for ADDITION operation starts here
    #pragma omp parallel num_threads(5)
     {
      int i,j;
      #pragma omp for
      for( i =0;i<5;i++)
      {
        for( j=0;j<5;j++)
        {
          c[i][j]=a[i][j]+b[i][j];
        }
        printf("\n");
      }
     }

//pragma for ADDITION operation ENDS here

printf("TRANSPOSE MATRIX :\n");
for(i=0;i<rows;i++)
  {
  for(j=0;j<cols;j++)
       printf("%d\t",a[i][j]);
  printf("\n");
  }

printf("RESULTANT MATRIX :\n");
for(i=0;i<rows;i++)
  {
  for(j=0;j<cols;j++)
       printf("%d\t",c[i][j]);
  printf("\n");
  }
}

