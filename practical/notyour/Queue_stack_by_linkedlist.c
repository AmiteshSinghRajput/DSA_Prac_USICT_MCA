#include <stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *head,*rear = NULL;
void *createnode()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    return temp;
}

//Operations on stack

void display_s()
{
    if (head == NULL)
        printf("\nunderflow\n");
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            printf("%d->", temp->info);
            temp = temp->next;
        }
        printf("%d->NULL", temp->info);
        printf("\n");
    }
}
void push()
{
    struct node *ptr = createnode();
    int data;
    printf("enter data you want to insert\n");
    scanf("%d", &data);
    ptr->info = data;
    if (head == NULL)
    {

        ptr->next = NULL;
        head = ptr;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }
    printf("value inserted\n");
    display_s();
}
void pop()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("underflow\n");
    }
    else
    {
        printf("value deleted is %d\n ", temp->info);
        head = temp->next;
        free(temp);
        display_s();
    }
}
void top()
{
    if (head == NULL)
    {
        printf("underflow\n");
    }
    else
    {
        printf("value  on top is %d\n ", head->info);
    }
}

//Operations over on Stack

//Operations on Queue

void display_q()
{
    if(head==NULL)
    {
        printf("underflow\n");
    }
    else
    {
        struct node* temp=head;
        while(temp->next!=NULL)
        {
            printf("%d->",temp->info);
            temp=temp->next;
        }
        printf("%d->NULL",temp->info);
        printf("\n");

    }
}
void enqueue()
{
    struct node *ptr = createnode();
    int data;
    printf("enter data you want to insert\n");
    scanf("%d", &data);
    ptr->info = data;
    if(head==NULL )
    {
        ptr->next=NULL;

        head=ptr;
        rear=ptr;
    }
    else
    {
        rear->next=ptr;
        rear=ptr;
        rear->next=NULL;
    }
    printf("element inserted\n");
    display_q();
}
void dequeue()
{
    struct node *ptr = createnode();
    if(head==NULL)
    {
        printf("underflow\n");
        return;
    }
    else
    {
        struct node*temp=head;
        printf("Element deleted is %d\n ",temp->info);
        head=head->next;
        free(temp);
    }
    printf("element deleted\n");
    display_q();
}

//Operations over for Queue

int main()
{
    char ch;
    int choice,chm,ch1;
    do
    {
        printf("Main Menu \n1.Queue \n2.Stack\n");
        scanf("%d",&chm);
        switch(chm)
        {
        case 1:
            head=NULL;
            do
            {
                printf("1.enqueue\n2.dequeue\n");
                printf("enter choice\n");
                scanf("%d",&choice);
                switch (choice)
                {
                case 1:
                    enqueue();
                    break;
                case 2:
                    dequeue();
                    break;
                default:
                    printf("Wrong choice \n");
                    break;
            }
            printf("Do you want to continue ?(y=yes)\n");
            scanf(" %c",&ch);
            }while (ch == 'Y' || ch == 'y');
            break;
        case 2:
            head=NULL;
            do
            {
                printf("1.push\n2.pop\n3.peek\n");
                printf("enter choice\n");
                scanf("%d",&choice);
                switch (choice)
                {
                case 1:
                    push();
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    top();
                    break;
                default:
                    printf("wrong choice\n");
                    break;
                }
            printf("Do you want to continue ?(y=yes)\n");
            scanf(" %c",&ch);
            }while (ch == 'Y' || ch == 'y');
            break;
            default:
            printf("Wrong Choice\n");
            break;
        }
        printf("Do you want to continue to Main Menu?(1-yes)\n");
        scanf("%d",&ch1);
    }while(ch1==1);
    return 0;
}
