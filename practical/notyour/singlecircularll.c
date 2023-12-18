#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct CirNode {
    int data;
    struct CirNode* next;
};

struct Node * head=NULL;
struct CirNode * Circularhead=NULL;

void insertBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int data) {
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

void insertAtPosition(int data, int userdata) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* current=head;
    while(current->next!=NULL)
    {
        if (current->data==userdata)
        {
            break;
        }
        current=current->next;
    }
    if(current->data!=userdata)
    {
        printf("The value entered to insert after does not exist\n");
    }
    newNode->next=current->next;
    current->next=newNode;

}

void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

void deleteAtPosition(int userdata) {

    struct Node* current=head;
    struct Node* prev=NULL;
    if(current!=NULL && current->data==userdata)
    {
        head=current->next;
        free(current);
        return;
    }
    while(current!=NULL && current->data!=userdata)
    {
        prev=current;
        current=current->next;
    }

    if(current==NULL)
    {
        printf("Data to delete does not exist\n");
        return;
    }
prev->next=current->next;
free(current);
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

void insertAtBeginningCircular(int data) {
    struct CirNode* newNode = (struct CirNode*)malloc(sizeof(struct CirNode));
    newNode->data = data;
    newNode->next = NULL;
    if(Circularhead==NULL)
        newNode->next=newNode;
    else{
        struct CirNode* current =Circularhead;
        while (current->next!=Circularhead){
            current=current->next;
        }
        current->next=newNode;
        newNode->next=Circularhead;
    }
    Circularhead=newNode;
}
void insertAtEndCircular( int data) {
    struct CirNode* newNode = (struct CirNode*)malloc(sizeof(struct CirNode));
    newNode->data = data;
    newNode->next = NULL;
    if (Circularhead == NULL) {
        newNode->next = newNode;
        Circularhead = newNode;
    } else {
        struct CirNode* current = Circularhead;
        while (current->next != Circularhead) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = Circularhead;
    }
}
void insertAtPositionCircular( int data, int userdata) {

    struct CirNode* newNode = (struct CirNode*)malloc(sizeof(struct CirNode));
    newNode->data = data;

    struct CirNode* current=Circularhead;
    while(current->next!=Circularhead)
    {
        if (current->data==userdata)
        {
            break;
        }
        current=current->next;
    }
    if(current->data!=userdata)
    {
        printf("Sorry,The Value You Entered To Insert After Is Not Present In Linked List\n");
    }
    newNode->next=current->next;
    current->next=newNode;

}

void deleteAtBeginningCircular() {
    if (Circularhead == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }
    struct CirNode* current = Circularhead;
    while (current->next != Circularhead) {
        current = current->next;
    }
    if (current == Circularhead) {
        free(current);
        Circularhead = NULL;
    } else {
        struct CirNode* temp = Circularhead->next;
        current->next = temp;
        free(Circularhead);
        Circularhead = temp;
    }
}

void deleteAtEndCircular() {
    if (Circularhead == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }
    struct CirNode* current = Circularhead;
    struct CirNode* prev = NULL;
    while (current->next != Circularhead) {
        prev = current;
        current = current->next;
    }
    if (current == Circularhead) {
        free(current);
        Circularhead = NULL;
    } else {
        prev->next = Circularhead;
        free(current);
    }
}
void deleteAtPositionCircular( int userdata) {

    struct CirNode* current = Circularhead;
    struct CirNode* prev=NULL;
    if(current->next!=Circularhead && current->data==userdata)
    {
        Circularhead=current->next;
        free(current);
        return;
    }
    while(current->next!=Circularhead && current->data!=userdata)
    {
        prev=current;
        current=current->next;
    }

    if(current->next==Circularhead)
    {
        printf("Data To Delete Is Not Present In The Linked List\n");
        return;
    }
prev->next=current->next;
free(current);

}
void displayCircular() {
    if (Circularhead == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }

    struct CirNode* current = Circularhead;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != Circularhead);
    printf("...->");
    printf("%d",Circularhead->data);
    printf("\n");
}

int main()
{
    int choice, data, userdata;
while (1) {
        printf("1. Insert at the beginning of Singly Linked List\n");
        printf("2. Insert at the end of Singly Linked List\n");
        printf("3. Insert after a data given of Singly Linked List\n");
        printf("4. Delete at the beginning of Singly Linked List\n");
        printf("5. Delete at the end of Singly Linked List\n");
        printf("6. Delete the value of the data given in Singly Linked List\n");
        printf("7. Display Singly Linked List\n");
        printf("8. Insert at the beginning of Circular Linked List\n");
        printf("9. Insert at the end of Circular Linked List\n");
        printf("10. Insert after a data given of Circular Linked List\n");
        printf("11. Delete at the beginning of Circular Linked List\n");
        printf("12. Delete at the end of Circular Linked List\n");
        printf("13. Delete the value of the data given in Circular Linked List\n");
        printf("14. Display Circular Linked List\n");
        printf("15. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at the beginning of Singly Linked List: ");
                scanf("%d", &data);
                insertBeginning(data);
                break;
            case 2:
                printf("Enter value to insert at the end of Singly Linked List: ");
                scanf("%d", &data);
                insertEnd( data);
                break;
            case 3:
                printf("Enter value to insert after certain value in Singly Linked List: ");
                scanf("%d", &data);
                printf("Enter data value to search for insertion in single linked list: ");
                scanf("%d", &userdata);
                insertAtPosition( data, userdata);
                break;
            case 4:
                deleteBeginning();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter data to delete from Singly Linked List: ");
                scanf("%d", &userdata);
                deleteAtPosition( userdata);
                break;
            case 7:
                printf("Singly Linked List: ");
                display();
                break;
            case 8:
                printf("Enter value to insert at the beginning of Circular linked List: ");
                scanf("%d", &data);
                insertAtBeginningCircular(data);
                break;
            case 9:
                printf("Enter value to insert at the end of Circular Linked list: ");
                scanf("%d", &data);
                insertAtEndCircular(data);
                break;
            case 10:
                printf("Enter data to insert after certain value of circular Linked List: ");
                scanf("%d", &data);
                printf("Enter the value to search for insertion in Circular linked List: ");
                scanf("%d", &userdata);
                insertAtPositionCircular( data
                ,userdata);
                break;
            case 11:
                deleteAtBeginningCircular();
                break;
            case 12:
                deleteAtEndCircular();
                break;
            case 13:
                printf("Enter data to delete from Circular Linked List: ");
                scanf("%d", &userdata);
                deleteAtPositionCircular( userdata);
                break;
            case 14:
                printf("Circular Linked List: ");
                displayCircular();
                break;
            case 15:
                return 0;
            default:
                printf("Invalid choice. please try again.\n");
        }
    }

    return 0;
}
