#define max 50
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
char stack[max],prfx[max];
int top=-1;
void push(char e)
{
        stack[++top]=e;
}
char pop()
{
        return(stack[top--]);
}
int pr(char e)
{
        switch (e)
        {
                case '+':
                case '-':
                         return 1;break;
                case '*':
                case '/':
                         return 2;break;
                case '^':return 3;break;
                default :return 0;break;
        }
}
void main()
{
         char infxx[max],ch,e;
         char *infx,*pr;
         int i = 0, k = 0;
         printf("\nINFIX EXPRESSION : ");
         scanf("%s",infxx);
         infx=rev(infxx);
         strcat(infx,")\0");
         push('(');
         while ((ch =infx[i++]) != '\0')
           {
                if (ch == '(')
                   push(ch);
                else if (isalnum(ch))
                   prfx[k++] = ch;
                else if (ch == ')')
                  {
                     while ((stack[top] != '(')&&(top!=-1))
                         prfx[k++] = pop();
                     e=pop();
                  }
                 else if(ch=='^'||ch=='+'||ch=='-'||ch=='*'||ch=='/')
                  {
                        while ((pr(stack[top]) >= pr(ch))&&(top!=-1))
                            prfx[k++] = pop();
                        push(ch);
                  }

         }
         while ((stack[top] != '(')&&(top!=-1))
                 prfx[k++] = pop();
         infx=rev(infx);
         pr=rev(prfx);
         printf("\nPREFIX EXPRESSION :%s\n",prfx);
}

