#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#define cap 5

int queue[cap];
int f = -1;
int r = -1;

bool isEmpty() {
    if (f == -1 && r == -1)
    {
      return true;
    }
     return false;
}

bool isFull() {
    if ((r + 1) % cap == f)
    {
        return true;
    }
    return false;
}

void Enque(int n) {
    if (isFull())
     {
        printf("FULL!\n");
        return;
    }
    else if (isEmpty())
     {
        f = 0;
        r=0;
    } else {
        r = (r + 1) % cap;
    }
    queue[r] = n;
    printf("ENQUEUED!\n");
}

void Deque() {
    if (isEmpty()) {
        printf("EMPTY!\n");
        return;
    }
    else if
    (f == r)
    {
        f =-1;
        r=-1;
    }
    else {
        f = (f + 1) % cap;
    }
    printf("DEQUEUED!\n");
}

void Display() {
    if (isEmpty()) {
        printf("EMPTY!\n");
        return;
    }
    int i = f;
    printf("\nThe Queue Is:\n");
    do {
        printf("%d\t", queue[i]);
        i = (i + 1) % cap;
    } while (i != (r + 1) % cap);
    printf("\n");
}

struct CirNode {
    int data;
    struct CirNode* next;
};

struct CirNode* rare=NULL;
struct CirNode * front=NULL;

void EnqueCircular(int data)
{
   struct CirNode *newNode=( struct CirNode *)malloc(sizeof(struct CirNode));
   newNode->data=data;
   if(rare==NULL)
   {
    front=rare=newNode;
    rare->next=front;
   }

   else
   {
    newNode->next=front;
    rare->next=newNode;
   }

   rare=newNode;

}

void DequeCircular()
{
    if(front==NULL)
    {
        printf("\nEMPTY!\n");
        return;
    }
   struct CirNode* p;
   p=front;

   if(front==rare)
   {
    front=NULL;
    rare=NULL;
    free(p);
   }
   else
   {
    front=front->next;
    rare->next=front;
    free(p);
   }

}

void displayCircular() {
    if (rare == NULL) {
        printf("EMPTY!\n");
        return;
    }

   struct CirNode* current = front;
    do {
        printf("%d->", current->data);
        current = current->next;
    } while (current != front);
    printf("\n");
}


int main() {
    int choice, value;
while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enque\n");
        printf("2. Deque\n");
        printf("3. CheckStatus\n");
        printf("4. Display\n");
        printf("5. Enque using linked list\n");
        printf("6. Deque using linked list\n");
         printf("7. Display Linked list\n");
        printf("8. Exit\n");
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
            printf("Enter the value to enque: ");
            scanf("%d", &value);
            EnqueCircular(value);
                break;
            case 6:
            DequeCircular();
                break;
            case 7:
            displayCircular();
            break;
            case 8:
                printf("Exited\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
