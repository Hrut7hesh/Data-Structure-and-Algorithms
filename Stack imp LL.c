// Stack implementation using Linked list
// Submitted by G.Hruthesh reddy, Admn.No.20BCB7031
#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void display();
struct node
{
    int val;
    struct node*next;
};
struct node*head;

void main()
{
    int x=0;
    printf("\n************Menu*************\n");
    while(x!=4)
    {
        printf("\nChoose from one from options:");
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your option:");
        scanf("%d",&x);
        switch(x)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("Exiting");
                break;
            }
            default:
            {
                printf("Please enter valid option");
            }
        };
    }
}
void push()
{
    int val;
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Not able to insert");
    }
    else
    {
        printf("Enter value:");
        scanf("%d",&val);
        if(head==NULL)
        {
            ptr->val=val;
            ptr->next=NULL;
            head=ptr;
        }
        else
        {
            ptr->val=val;
            ptr->next=head;
            head=ptr;
        }
        printf("Inserted");
    }
}
void pop()
{
    int b;
    struct node*ptr;
    if(head==NULL)
    {
        printf("Underflow");
    }
    else
    {
        b=head->val;
        ptr=head;
        head=head->next;
        free(ptr);
        printf("Deleted");
    }
}
void display()
{
    int c;
    struct node*ptr;
    ptr=head;
    if(ptr==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Displaying elements\n");
        while(ptr!=NULL)
        {
            printf("%d",ptr->val);
            ptr=ptr->next;
        }
    }
}