#define max 50
#include<string.h>
#include <ctype.h>
#include<stdlib.h>
#include<stdio.h>
char s[max],pofx[max];
int top=-1,top1=-1;
int st[max];
void push(char e)
{
        s[++top]=e;
}
void push1(int e)
{
        st[++top1]=e;
}
char pop()
{
        return (s[top--]);
}
int pop1()
{
        return (st[top1--]);
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
void convert()
{
         char infx[max],ch,e;
         int i = 0, k = 0;
         printf("\nINFIX EXPRESSION : ");
         scanf("%s", infx);
         strcat(infx,")\0");
         push('(');
         while ((ch = infx[i++]) != '\0')
           {
                if (ch == '(')
                   push(ch);
                else if (isdigit(ch))
                   pofx[k++] = ch;
                else if (ch == ')')
                  {
                     while ((s[top] != '(')&&(top!=-1))
                         pofx[k++] = pop();   
                     e=pop();
                  }
                 else if(ch=='^'||ch=='+'||ch=='-'||ch=='*'||ch=='/')
                  {
                        while ((pr(s[top]) >= pr(ch))&&(top!=-1))
                            pofx[k++] = pop();
                        push(ch);
                  }

         }
         while ((s[top] != '(')&&(top!=-1))
                 pofx[k++] = pop();
         pofx[k] = '\0';
         printf("\nPostfix Expression: %s\n",pofx);
}
void evaluate()
{
        int i=0;
        float op2,op1;
        char ch;
        while( (ch=pofx[i++]) != '\0')
        {
                if(isdigit(ch))
                        push1(ch-'0');
                else
                {
                        op2=pop1();
                        op1=pop1();
                        switch(ch)
                        {
                            case '+':push1(op1+op2);break;
                            case '-':push1(op1-op2);break;
                            case '*':push1(op1*op2);break;
                            case '/':push1(op1/op2);break;
                            case '^':push1(pow(op1,op2));break;
                            default :printf("INVALID CASE\n");break;
                        }
                }
        }
        printf("\nEVALUATED RESULT : %d\n",st[top1]);
}
void main()
{
        int ch;
        do
        {
        printf("\tMENU\n1.INFIX TO POSTFIX\n2.POSTFIX EVALUATION\n3.EXIT\nENTER YOUR OPTION :\n");
        scanf("%d",&ch);
        switch(ch)
           {
                case 1 :convert();break;
                case 2 :evaluate();break;
                case 3 :break;
                default:printf("INVALID OPTION\n");break;
           }
        }while(ch!=3);
}
