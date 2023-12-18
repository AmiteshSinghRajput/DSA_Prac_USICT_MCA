#include<stdio.h>
#include<stdbool.h>
#define cap 5

int queue[cap];

int f=-1;
int r=-1;

bool isEmpty()
{
    if(f==-1)
    {
        return true;
    }

    return false;
}
bool isFull()
{
    if(r==cap-1)
    {
        return true;
    }

    return false;
}

void Enque(int n)
{
    if(isFull())
    {
        printf("\nFULL!\n");
        return;
    }

     if(isEmpty())
    {
        f=0;
        r=0;
    }
    else{
        r++;
    }

       queue[r] = n;

       printf("\n ENQUED! \n");

}

void Deque()
{
    if(isEmpty())
    {
        printf("\nEMPTY!\n");
        return;
    }
    else
    {
        if(f==r)
        {
            f=-1;
            r=-1;
        }
        else
        {
            f++;
        }
         printf("\n DEQUED! \n");
    }

}
void Display()
{
    if(f==-1 && r==-1)
    {
     printf("\nEMPTY!\n");
     return;
    }
    printf("\nThe Queue Is:\n");
    for(int i=f;i<=r;i++)
    {
        printf("%d\t",queue[i]);

    }
}
int main()
{

int choice,value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enque\n");
        printf("2. Deque\n");
        printf("3. CheckStatus\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:

                printf("Enter the value to enque: ");
                scanf("%d", &value);
                Enque(value);
                break;

            case 2:
                Deque();
                break;

            case 3:
            if(isEmpty())
            {
                printf("\nEMPTY!\n");
            }
            else if(isFull())
            {
                printf("\nFULL!\n");
            }
            else
            {
                printf("\nNeither Empty Nor Full! \n");
            }
                break;


            case 4:
            Display();
                break;

            case 5:
                printf("Exited\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;

}
