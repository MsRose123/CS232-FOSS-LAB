#include<stdio.h>
#include<string.h>
void main()
   {
     int i;
     char s1[100],s2[100];
     printf("ENTER THE STRING :\n");
     gets(s1);
     printf("1");
     for(i=0;s1[i]!="\0";i++)
        s2[i]=s1[i];
     printf("2");
     s2[i]="\0";
     printf("COPIED STRING :%s\n",s2);
   }
