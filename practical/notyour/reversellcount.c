#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node * head=NULL;


void insertSingly(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void reverse()
{
  struct  Node* current=head;
  struct  Node* prev=NULL;
  while (current!=NULL)
  {
    struct Node* temp=current->next;//storing the address of the next node
    current->next=prev;//current nodes next pointing to prev;
    prev=current;//moving previous to current
    current=temp;//moving current  to next
  }
  head=prev;//Assigning prev which is now head to head pointer
}
int countNodes()
{
    int count=0;
    struct  Node* current=head;
    while(current!=NULL)
    {
        count++;
        current=current->next;
    }
    return count;

}

void display() {
    struct Node* current = head;
    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, data;
while (1) {
        printf("1. Insert In Singly Linked List\n");
        printf("2. Reverse Singly Linked List\n");
        printf("3. Display Singly Linked List\n");
        printf("4. Count Nodes Singly Linked List\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:

                printf("Enter value to insert at the end of Singly Linked List: ");
                scanf("%d", &data);
                insertSingly( data);
                break;
            case 2:
               reverse();
                 break;
            case 3:
              display();
                break;
            case 4:
             printf("The Number of Nodes In The Linked List Is %d\n.",countNodes());
                break;
            case 5:
            return 0;
                break;

            default:
                printf("Invalid choice. please try again.\n");
        }
}
return 0;
}
