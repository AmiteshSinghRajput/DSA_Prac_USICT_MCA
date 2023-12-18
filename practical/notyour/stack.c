#include<stdio.h>
#include<stdlib.h>

int top=-1;

void display(int ar[])
{
    if(top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("Stack = ");
        for(int i=0;i<=top;i++)
            printf("%d->",ar[i]);
        printf("\n");
    }
}

void push(int ar[],int size)
{
    if(top==size-1)
        printf("Stack overflow \n");
    else
    {
        int val;
        printf("Enter element\n");
        scanf("%d",&val);
        top++;
        ar[top]=val;
        printf("%d pushed into the stack\n",ar[top]);
    }
}

void pop(int ar[])
{
    if(top==-1)
        printf("Stack underflow\n");
    else
    {
        printf("Popped element = %d\n",ar[top]);
        top--;
    }
}

void peek(int ar[])
{
    if(top==-1)
        printf("Stack is empty\n");
    else
        printf("Element at top of stack is = %d\n",ar[top]);
}

int main()
{
    int size,ch;
    printf("Enter size of stack\n");
    scanf("%d",&size);
    int ar[size];
    do
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            push(ar,size);
            break;
        case 2:
            pop(ar);
            break;
        case 3:
            peek(ar);
            break;
        case 4:
            display(ar);
            break;
        case 5:
            printf("Exiting...");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while(ch!=5);
    return 0;
}
