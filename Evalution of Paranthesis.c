//Evalution of Paranthesis
//Submitted by G Hruthesh reddy, Admn No.20BCB7031
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

struct stack
{
    char stk[MAX];
    int top;
}s;
void push(char item)
{
    if(s.top==(MAX-1))
    printf("Stack is Full\n");
    else
    {
        s.top=s.top+1;
        s.stk[s.top]=item;
    }
}
void pop()
{
    if(s.top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
     s.top=s.top-1;   
    }
}
int main()
{
    char exp[MAX];
    int i=0;
    s.top=-1;
    printf("\nEnter your Paranthesis:");
    scanf("%s",exp);
    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
        {
            push(exp[i]);
            continue;
        }
        else if(exp[i]=')' || exp[i]==']' || exp[i]=='}')
        {
            if(exp[i]==')')
            {
                if(s.stk[s.top]=='(')
                {
                    pop();
                }
                else
                {
                    printf("\nUnbalanced\n");
                    break;
                }
            }
            if(exp[i]==']')
            {
                if(s.stk[s.top]=='[')
                {
                    pop();
                }
                else
                {
                    printf("\nUnbalanced\n");
                    break;
                }
            }
            if(exp[i]=='}')
            {
                if(s.stk[s.top]=='{')
                {
                    pop();
                }
                else
                {
                 printf("\nUnbalanced\n");
                 break;
                }
            }
        }    
    }
    if(s.top==-1)
    {
        printf("\nBalanced\n");
    }
}