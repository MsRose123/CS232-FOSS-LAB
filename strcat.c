#include<stdio.h>
void main()
   {
     int i,j;
     char s1[100],s2[100];
     printf("ENTER FIRST STRING :\n");
     gets(s1);
     printf("ENTER SECOND STRING :\n");
     gets(s2);
     for(i=0;s1[i]!="\0";i++);
     for(j=0;s2[j]!="\0";j++,i++)
        s1[i]=s2[j];
     s1[i]="\0";
     printf("CONCATINATED STRING :%s\n",s1);
   }

      
