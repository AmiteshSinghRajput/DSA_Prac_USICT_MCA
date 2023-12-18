#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/**
 * The function initializes an empty linked list by setting the head pointer to NULL.
 * 
 * @param list The parameter "list" is a pointer to a struct LinkedList. It is used to access and
 * modify the linked list.
 */
// Singly Linked List structure
struct LinkedList {
    struct Node* head;
};

// Initialize an empty linked list
void initLinkedList(struct LinkedList* list) {
    list->head = NULL;
}

// Insertion at the beginning of the list
void insertAtBeginning(struct LinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

// Insertion at a specified location in the list
void insertAtLocation(struct LinkedList* list, int data, int position) {
    struct Node* newNode = createNode(data);

    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        newNode->next = list->head;
        list->head = newNode;
        return;
    }

    struct Node* current = list->head;
    struct Node* prev = NULL;
    int count = 1;
    while (current != NULL && count < position) {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Invalid position.\n");
        return;
    }

    newNode->next = current;
    if (prev != NULL) {
        prev->next = newNode;
    } else {
        list->head = newNode;
    }
}

// Insertion at the end of the list
void insertAtEnd(struct LinkedList* list, int data) {
    struct Node* newNode = createNode(data);

    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    struct Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

// Deletion at the beginning of the list
void deleteAtBeginning(struct LinkedList* list) {
    if (list->head != NULL) {
        struct Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
    } else {
        printf("List is empty. Nothing to delete.\n");
    }
}

// Deletion at a specified location in the list
void deleteAtLocation(struct LinkedList* list, int position) {
    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        deleteAtBeginning(list);
        return;
    }

    struct Node* current = list->head;
    struct Node* prev = NULL;
    int count = 1;
    while (current != NULL && count < position) {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Invalid position.\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

// Deletion at the end of the list
void deleteAtEnd(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        return;
    }

    struct Node* current = list->head;
    struct Node* prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    free(current);
}

// Display the linked list
void display(struct LinkedList* list) {
    struct Node* current = list->head;
    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct LinkedList sll;
    initLinkedList(&sll);

    int choice, data, position;

    while (1) {
        printf("\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at a specified location\n");
        printf("3. Insert at the end\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at a specified location\n");
        printf("6. Delete at the end\n");
        printf("7. Display the list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&sll, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtLocation(&sll, data, position);
                break;
            case 3:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&sll, data);
                break;
            case 4:
                deleteAtBeginning(&sll);
                break;
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtLocation(&sll, position);
                break;
            case 6:
                deleteAtEnd(&sll);
                break;
            case 7:
                display(&sll);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
