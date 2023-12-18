#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct CirNode {
    int data;
    struct CirNode* prev;
    struct CirNode* next;
};

struct Node * head=NULL;
struct CirNode * Circularhead=NULL;


void insertAtBeginning( int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    if (head == NULL) {
        head = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtEnd( int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}


void insertAfterData( int data, int dataAfter) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        if (current->data == dataAfter) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data=data;
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != NULL) {//handling end node case
                current->next->prev = newNode;
            }
            current->next = newNode;
            return;
        }
        current = current->next;
    }

    printf("%d not found in the list.\n", dataAfter);
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {//checking if the list has only one node
        head->prev = NULL;
    }
    free(temp);
}
void deleteAtEnd() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next = NULL;
    }
    else {
        // The list had only one node
        head = NULL;
    }
    free(current);
}

void deleteByData( int dataToDelete) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        if (current->data == dataToDelete) {
            if (current->prev != NULL) {//handling beginning node case
                current->prev->next = current->next;
            }
            else {
                // Deleting the first node
                head = current->next;
            }
            if (current->next != NULL) {//handling end node case
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
    printf("%d not found in the list.\n", dataToDelete);
}

void display() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void insertAtBeginningCircular( int data) {
    struct CirNode* newNode = (struct CirNode*)malloc(sizeof(struct CirNode));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    if (Circularhead == NULL) {
        Circularhead = newNode;
        newNode->next = newNode;//self pointing
        newNode->prev = newNode;
    }
    else {
        struct CirNode* tail = Circularhead->prev; // Get the last node before breaking the link
        newNode->next = Circularhead;
        newNode->prev = tail;
        Circularhead->prev = newNode;
        tail->next = newNode;
        Circularhead = newNode; // Update the head to the new node
    }
}
void insertAtEndCircular( int data) {
    struct CirNode* newNode = (struct CirNode*)malloc(sizeof(struct CirNode));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    if (Circularhead == NULL) {
        Circularhead = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        struct CirNode* tail = Circularhead->prev; // storing the last node before breaking link
        newNode->next = Circularhead;
        newNode->prev = tail;
        Circularhead->prev = newNode;
        tail->next = newNode;
    }
}

void insertAfterDataCircular( int data, int dataAfter) {
    if (Circularhead == NULL) {
        printf("The list is empty\n");
        return;
    }

    struct CirNode* current = Circularhead;
    do {
        if (current->data == dataAfter) {
            struct CirNode* newNode =(struct CirNode*)malloc(sizeof(struct CirNode));
            newNode->data=data;
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
            return;
        }
        current = current->next;
    } while (current != Circularhead);

    printf("%d does not exist in the list\n", dataAfter);
}

void deleteAtBeginningCircular() {
    if (Circularhead == NULL) {
        printf("The list is empty\n");
        return;
    }

    struct CirNode* tail = Circularhead->prev;
    struct CirNode* temp = Circularhead;
    if (temp->next == temp) {
        Circularhead = NULL; // List has only one node, make it empty
    }
    else {
        Circularhead = temp->next;
        tail->next = Circularhead;
        Circularhead->prev = tail;
    }
    free(temp);
}


void deleteAtEndCircular() {
    if (Circularhead == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct CirNode* tail = Circularhead->prev;
    struct CirNode* temp = tail;
    if (temp->next == temp) {
        Circularhead = NULL; // List has only one node, make it empty
    } else {
        tail = temp->prev;
        tail->next = Circularhead;
        Circularhead->prev = tail;
    }
    free(temp);
}


void deleteByDataCircular( int dataToDelete) {
    if (Circularhead == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct CirNode* current = Circularhead;
    do {
        if (current->data == dataToDelete) {
            struct CirNode* temp = current;
            if (temp->next == temp) {
                Circularhead = NULL; // List has only one node, make it empty
            } else {
                current = current->next;
                temp->prev->next = current;
                current->prev = temp->prev;
                if (Circularhead == temp) {
                    Circularhead = current;
                }
            }
            free(temp);
            return;
        }
        current = current->next;
    } while (current != Circularhead);

    printf("%d does not exist in the list.\n", dataToDelete);
}

void displayCircular() {
    if (Circularhead == NULL) {
        printf("Double Circular linked list is empty.\n");
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
int main(){
int choice, data, userdata;
while (1) {
        printf("1.Insert at the beginning of Double Linked List\n");
        printf("2.Insert at the end of Double Linked List\n");
        printf("3.Insert after a data given of Double Linked List\n");
        printf("4.Delete at the beginning of Double Linked List\n");
        printf("5.Delete at the end of Double Linked List\n");
        printf("6.Delete the value of the data given in Double Linked List\n");
        printf("7.Display Double Linked List\n");
        printf("8.Insert at the beginning of Double Circular Linked List\n");
        printf("9.Insert at the end of Double Circular Linked List\n");
        printf("10.Insert after a data given of Double Circular Linked List\n");
        printf("11.Delete at the beginning of Double Circular Linked List\n");
        printf("12.Delete at the end of Double Circular Linked List\n");
        printf("13.Delete the value of the data given in Double Circular Linked List\n");
        printf("14.Display Double Circular Linked List\n");
        printf("15.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at the beginning of Double Linked List: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter value to insert at the end of Double Linked List: ");
                scanf("%d", &data);
                insertAtEnd( data);
                break;
            case 3:
                printf("Enter value to insert after certain value in Double Linked List: ");
                scanf("%d", &data);
                printf("Enter data value to search for insertion in Double linked list: ");
                scanf("%d", &userdata);
                insertAfterData( data, userdata);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter data to delete from Double Linked List: ");
                scanf("%d", &userdata);
                deleteByData( userdata);
                break;

            case 7:
                printf("Double Linked List: ");
                display();
                break;

            case 8:
                printf("Enter value to insert at the beginning of Double Circular linked List: ");
                scanf("%d", &data);
                insertAtBeginningCircular(data);
                break;
            case 9:
                printf("Enter value to insert at the end of Double Circular Linked list: ");
                scanf("%d", &data);
                insertAtEndCircular(data);
                break;
            case 10:
                printf("Enter data to insert after certain value of Double circular Linked List: ");
                scanf("%d", &data);
                printf("Enter the value to search for insertion in Double Circular linked List: ");
                scanf("%d", &userdata);
                insertAfterDataCircular( data,userdata);
                break;
            case 11:
                deleteAtBeginningCircular();
                break;
            case 12:
                deleteAtEndCircular();
                break;
            case 13:
                printf("Enter data to delete from Double Circular Linked List: ");
                scanf("%d", &userdata);
                deleteByDataCircular( userdata);
                break;
            case 14:
                printf("Double Circular Linked List: ");
                displayCircular();
                break;

            case 15:
                return 0;
            default:
                printf("Invalid choice please enter correct data \n");
        }
    }
    return 0;
}
