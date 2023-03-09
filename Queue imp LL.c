//Queue implementation using Linked list
//Submitted by G.Hruthesh reddy, Admn.No.20BCB7031
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node*front;
struct node*rear;
void push();
void pop();
void display();
void main()
{
    int x;
    while(x!=4)
    {
        printf("\n*************MENU***************\n");
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nChoose one from above options:");
        scanf("%d",&x);
        switch(x)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("\nEnter your choice:");
        }
    }
}
void push()
{
    struct node*ptr;
    int a;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nOVERFLOW");
        return;
    }
    else
    {
        printf("\nEnter your value");
        scanf("%d",&a);
        ptr->data=a;
        if(front==NULL)
        {
            front=ptr;
            rear=ptr;
            front->next=NULL;
            rear->next=NULL;
        }
        else
        {
            rear->next=ptr;
            rear=ptr;
            rear->next=NULL;
        }
    }
}
void pop()
{
    struct node*ptr;
    if(front==NULL)
    {
        printf("\nUNDERFLOW");
        return;
    }
    else
    {
        ptr=front;
        front=front->next;
        free(ptr);
    }
}
void display()
{
    struct node*ptr;
    ptr=front;
    if(front==NULL)
    {
        printf("\nEmpty queue");
    }
    else
    {
        printf("\nDisplaying values:");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
}