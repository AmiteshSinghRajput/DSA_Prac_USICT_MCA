
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int INFO;
    struct Node* next;
    struct Node* prev;

};
struct Node*head,*temp;
struct Node*head2=NULL;


void enterbeg_dll(int element)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        prinf("Memory allocation failed!!");
        return;
    }
    newNode->INFO=element;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL)
    {
        head=newNode;
        return;
    }

    else
    {
        temp=head;
        temp->prev=newNode;
        newNode->next=temp;
        head=newNode;

        return;
    }


}

void enterend_dll(int element)
{
    temp=head;
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->INFO=element;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL)
    {
        enterbeg_dll(element);
        return;
    }
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode;
        newNode->prev=temp;
        return;
    }


}

void entermid_dll(int element,int inselement)
{
    temp=head;
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->INFO=inselement;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL)
    {
        printf("\ninserting at first");
        enterbeg_dll(inselement);
        return;

    }
    while(temp->INFO!=element && temp->next!=NULL)
    {
        temp=temp->next;

    }
    if(temp->INFO==element)
    {
        if(temp->next==NULL)
        {
            temp->next=newNode;
            newNode->prev=temp;
            return;
        }
        else
        {

            newNode->prev=temp;
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
    else
    {

        printf("\nelementment Not found");
        return;
    }


}

void deletebeg_dll()
{
    if(head==NULL)
    {

        return;
    }
    else if(head->next==NULL)
    {
        head=NULL;
        return;
    }
    else
    {
        temp=head->next;
        temp->prev=NULL;
        free(head);
        head=temp;
        return;
    }

}

void deleteend_dll()
{
    if(head==NULL)
    {
        return;
    }
    else if(head->next==NULL)
    {
        deletebeg_dll();
        return;
    }
    else
    {


        temp=head;
        struct Node* temp2;
        while(temp->next!=NULL)
        {
            temp2=temp;
            temp=temp->next;
        }
        temp2->next=NULL;
        temp->prev=NULL;
        free(temp);
        return;

    }
}

void deletemid_dll(int element)
{
    if(head==NULL)
    {
        return;
    }
    if( head->INFO==element)
    {
        deletebeg_dll();
        return;
    }
    else
    {
        temp=head;
        struct Node* temp2;
        while(temp->next!=NULL && temp->INFO!=element)
        {
            temp2=temp;
            temp=temp->next;
        }
        if(temp->INFO==element)
        {
            if(temp->next==NULL)
            {
                delete_end_dll();
                return;
            }
            else
            {
                temp2->next=temp->next;
                temp->next->prev=temp2;
                temp->prev=NULL;
                temp->next=NULL;
                free(temp);
                return;
            }
        }
        else
        {
            printf("\nelementment Not found .");
            return;
        }
    }
}

void display_dll()
{
    if(head==NULL)
    {
        printf("\nList is Empty.");
        return;
    }
    else
    {
        temp=head;
        printf("\nNode : ");
        while(temp!=NULL)
        {
            printf("%d ",temp->INFO);
            temp=temp->next;
        }
        return;
    }
}

void display_cll()
{
    if(head2==NULL)
    {
        printf("\nList is Empty.");
    }
    else
    {
        temp=head2;
        printf("\nNode : ");
        while(temp->next!=head2)
        {
            printf("%d ",temp->INFO);
            temp=temp->next;
        }
        printf("%d ",temp->INFO);
    }
}
void enterbeg_cll(int element)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->INFO=element;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head2==NULL)
    {
        head2=newNode;
        newNode->next=head2;
        newNode->prev=head2;
        return;

    }
    else
    {
        temp=head2->prev;
        newNode->next=head2;
        head2->prev=newNode;
        temp->next=newNode;
        newNode->prev=temp;
        head2=newNode;
    }
}

void entermid_cll(int element,int inselement)
{

    if(head2==NULL)
    {
        printf("\ninserting at first");
        enterbeg_cll(inselement);
        return;
    }
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->INFO=inselement;
    newNode->next=NULL;
    newNode->prev=NULL;
    temp=head2;
    do
    {
        if(temp->INFO==element)
        {
            newNode->next=temp->next;
            newNode->prev=temp;
            temp->next->prev=newNode;
            temp->next=newNode;
            return;
        }
        temp=temp->next;
    }
    while(temp!=head2);
    if(temp->INFO==element)
    {
        enterend_cll(element);
        return;
    }
    else
    {
        printf("\nelement not found");
        return;
    }

}
void enterend_cll(int element)
{

    if(head2==NULL)
    {
        enterbeg_cll(element);
        return;
    }

    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->INFO=element;
    newNode->next=NULL;
    newNode->prev=NULL;
    temp=head2->prev;
    temp->next=newNode;
    newNode->prev=temp;
    newNode->next=head2;
    head2->prev=newNode;

}

void deletebeg_cll()
{
    if(head2==NULL)
    {
        return;
    }
    else if(head2->next==head2)
    {
        free(head2);
        head2=NULL;
        return;
    }
    struct Node* temp2;
    temp=head2->prev;
    temp2=head2;
    head2=head2->next;
    head2->prev=temp;
    temp->next=head2;
    free(temp2);
    temp2=NULL;

}

void deleteend_cll()
{
    if(head2==NULL)
    {
        return;
    }
    else if(head2->next==head2)
    {
        deletebeg_cll();
        return;
    }
    else
    {
        struct Node* temp2;
        temp=head2->prev;
        temp2=temp->prev;
        temp2->next=head2;
        head2->prev=temp2;
        free(temp);
        temp=NULL;
    }

}
void deletemid_cll(int element)
{
    if(head2==NULL)
    {
        return;
    }
    if( head2->INFO==element)
    {
        // printf("\ncalling right function");
        deletebeg_cll();
        return;
    }
    else
    {
        temp=head2;
        while(temp->INFO!=element && temp->next!=head2)
        {
            temp=temp->next;
        }
        if(temp->INFO==element)
        {
            if(temp->next==head2)
            {
                delete_end_cll();
                return;
            }
            else
            {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                free(temp);
                temp=NULL;

            }
        }
        else
        {
            printf("\nelementment not found.");

        }
    }

}


int main()
{
    int c=0,element,inselement,ch;

    do
    {
        printf("\n\n-");
        printf("\n\n1. singular link list");
        printf("\n2. circular  link list");
        printf("\n3. exit");
        printf("\n enter your choice .");
        scanf("%d",&ch);
        if(ch==1 || ch==2)
        {
            c=0;
            while(c!=8)
            {


                printf("\n\n1. insery at beigning.");
                printf("\n2. insert after specified element.");
                printf("\n3. insert at end .");
                printf("\n4. delete element at begining .");
                printf("\n5. delete element specified Node .");
                printf("\n6. delete element at end .");
                printf("\n7. display.");
                printf("\n8. return to main menu");
                printf("\n9. exit .");
                printf("\nplease enter your choice.");

                scanf("%d",&c);


                switch (c)
                {
                case 1:
                {
                    printf("\nenter node you want to insert .");
                    scanf("%d",&inselement);
                    if(ch==1)
                    {
                        enterbeg_dll(inselement);
                        display_dll();
                    }

                    if(ch==2)
                    {
                        enterbeg_cll(inselement);
                        display_cll();
                    }
                    // enterbeg_cll(inselement);
                    break;

                }
                case 2:
                {
                    printf("\nenter Node you want to insert .");
                    scanf("%d",&inselement);
                    printf("\nenter element after you want to insertNode .");
                    scanf("%d",&element);
                    if(ch==1)
                    {
                        entermid_dll(element,inselement);
                        display_dll();
                    }
                    if(ch==2)
                    {
                        entermid_cll(element,inselement);
                        display_cll();
                    }
                    break;

                }
                case 3:
                    printf("\nEnter Node you want to insert .");
                    scanf("%d",&inselement);
                    if(ch==1)
                    {
                        enterend_dll(inselement);
                        display_dll();
                    }
                    if(ch==2)
                    {
                        enterend_cll(inselement);
                        display_cll();
                    }
                    break;
                case 4:
                    if(ch==1)
                    {
                        deletebeg_dll();
                        display_dll();
                    }
                    if(ch==2)
                    {
                        deletebeg_cll();
                        display_cll();
                    }
                    break;

                case 5:
                    printf("\nenter node you want to delete .");
                    scanf("%d",&inselement);
                    if(ch==1)
                    {
                        delete_mid_dll(inselement);
                        display_dll();
                    }
                    if(ch==2)
                    {
                        deletemid_cll(inselement);
                        display_cll();
                    }
                    break;


                case 6:
                    if(ch==1)
                    {
                        deleteend_dll();
                        display_dll();
                    }
                    if(ch==2)
                    {
                        deleteend_cll();
                        display_cll();
                    }

                    break;

                case 7:
                    if(ch==1)
                    {
                        display_dll();
                    }
                    if(ch==2)
                    {
                        display_cll();
                    }
                    break;
                case 8:
                    break;
                case 9:
                    exit(1);

                default:
                {
                    printf("\n please enter valid choice .");
                    break;

                }

                }
            }
        }
    }
    while(ch!=3);

    return 0;
}









