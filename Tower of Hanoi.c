//Tower of Hanoi
//Submitted by G.Hruthesh Reddy ,Admn No.20BCB7031
#include<stdio.h>
#include<conio.h>
#define MAXSTK 10
struct item
{
    int n;
    char beg;
    char end;
    char aux;
    char add;
};
struct stack
{
    int top;
    struct item data[MAXSTK];
};
void push(struct stack*,struct item);
struct item pop(struct stack*);
void tower(int,char,char,char);
void main()
{
    int n;
    printf("No of rings:");
    scanf("%d",&n);
    tower(n,'A','B','C');
    getch();
}
void push(struct stack*p,struct item it)
{
    if(p->top==MAXSTK-1)
    {
        printf("Stack is full");
        return;
    }
    p->top++;
    p->data[p->top]=it;
}
struct item pop(struct stack *p)
{
    struct item it;
    if(p->top==-1)
    {
        printf("Stack is empty");
        return it;
    }
    it=p->data[p->top];
    p->top--;
    return(it);
}
void tower(int n,char beg,char aux,char end)
{
    struct stack s1;
    struct item currentitem;
    int t;
    s1.top=-1;
    step1:
    if(n==1)
    {
    printf("\nDisk 1 is moved from %c to %c",beg,end);
    goto step5;
    }
    step2:
    currentitem.n=n;
    currentitem.beg=beg;
    currentitem.end=end;
    currentitem.aux=aux;
    currentitem.add=3;
    push(&s1,currentitem);
    n--;
    t=end;
    end=aux;
    aux=t;
    goto step1;
    step3:
    printf("\nDisk %d is moved from %c to %c",n,beg,end);
    step4:
    currentitem.n=n;
    currentitem.beg=beg;
    currentitem.end=end;
    currentitem.aux=aux;
    currentitem.add=5;
    push(&s1,currentitem);
    n--;
    t=aux;
    aux=beg;
    beg=t;
    goto step1;
    step5:
    if(s1.top==-1)
    return;
    currentitem=pop(&s1);
    n=currentitem.n;
    beg=currentitem.beg;
    end=currentitem.end;
    aux=currentitem.aux;
    switch(currentitem.add)
    {
        case 3:
        goto step3;
        case 5:
        goto step5; 
    }
}
