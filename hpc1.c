#include<stdio.h>
#include<omp.h>
int main()
{
  omp_set_num_threads(4);
  #pragma omp parallel
   {
     printf("VALUE OF PI = 3.14 FROM THREAD NUMBER %d WITH %d THREADS\n",omp_get_thread_num(),omp_get_num_threads());
   }
 printf("DONE\n");
}
