#include<stdio.h>
#include<string.h>
void main()
   {
     int l,i,j,k;
     char s1[100],s2[50],s3[50];
     printf("ENTER THE STRING :\n");
     gets(s1);
     printf("ENTER SUBSTRING TO BE SEARCHED AND DELETED :\n");
     gets(s2);
     l=strlen(s2);
     for(i=0;s1[i]!="\0";i++)
         {
            if(s1[i]==s2[0])
              for(j=i,k=0;k<l;j++,k++)
                 s3[k]=s2[j];
            if(strcmp(s2,s3)==0)
              for(j=0;j<l;j++)
                 s1[i]=s1[i+l];
            else
              continue ;
         } 
     printf("FINAL STRING IS :%s\n",s1);
   }   
 
