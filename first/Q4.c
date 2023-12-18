#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the singly linked list
struct Node {
    int data;
    struct Node* next;
};

/* `struct Node* head = NULL;` is declaring a global variable `head` of type `struct Node*` and
initializing it to `NULL`. This variable will be used to keep track of the first node in the linked
list. Initially, since the linked list is empty, the `head` is set to `NULL`. */
struct Node* head = NULL; // Global head pointer

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = NULL;/* `(struct Node*)malloc(sizeof(struct Node));` is allocating memory
    dynamically for a new node in the linked list. */
   newNode=(struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    // printf("abn:- %p/n",(void*)newNode);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Function to count the number of nodes in the linked list
int countNodes() {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to reverse the linked list
void reverseLinkedList() {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        // Store the next node
        next = current->next;

        // Reverse the current node's pointer to point to the previous node
        current->next = prev;

        // Move the pointers one step ahead
        prev = current;
        current = next;
    }

    // Update the head to point to the new first node (which was the last node)
    head = prev;
}

// Function to print the linked list
void printLinkedList() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\n1. Insert at the beginning\n");
        printf("2. Count the number of nodes\n");
        printf("3. Reverse the linked list\n");
        printf("4. Print the linked list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Number of nodes: %d\n", countNodes());
                break;
            case 3:
                reverseLinkedList();
                printf("Linked list reversed.\n");
                break;
            case 4:
                printf("Linked list: ");
                printLinkedList();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
