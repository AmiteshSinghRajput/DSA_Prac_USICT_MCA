#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Linked list for stack and queue
struct Node* top = NULL; // For stack
struct Node* front = NULL; // For queue
struct Node* rear = NULL; // For queue

// Push operation for the stack
void push(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = top;
    top = newNode;
}

// Pop operation for the stack
int pop() {
    if (top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return a sentinel value to indicate an error
    }

    int poppedItem = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return poppedItem;
}

// Enqueue operation for the queue
void enqueue(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Dequeue operation for the queue
int dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a sentinel value to indicate an error
    }

    int dequeuedItem = front->data;
    struct Node* temp = front;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }

    free(temp);
    return dequeuedItem;
}

// Display the stack or queue
void display(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("Empty\n");
        return;
    }
    printf("Elements: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, item;

    while (1) {
        printf("Select an option:\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            break;
        }

        if (choice == 1) {
            while (1) {
                printf("Stack Menu:\n");
                printf("1. Push\n");
                printf("2. Pop\n");
                printf("3. Display\n");
                printf("4. Back to Main Menu\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Enter the item to push: ");
                        scanf("%d", &item);
                        push(item);
                        break;
                    case 2:
                        printf("Popped: %d\n", pop());
                        break;
                    case 3:
                        printf("Stack: ");
                        display(top);
                        break;
                    case 4:
                        break;
                    default:
                        printf("Invalid choice. Please enter a valid option.\n");
                }
            }
        } else if (choice == 2) {
            while (1) {
                printf("Queue Menu:\n");
                printf("1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Display\n");
                printf("4. Back to Main Menu\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Enter the item to enqueue: ");
                        scanf("%d", &item);
                        enqueue(item);
                        break;
                    case 2:
                        printf("Dequeued: %d\n", dequeue());
                        break;
                    case 3:
                        printf("Queue: ");
                        display(front);
                        break;
                    case 4:
                        break;
                    default:
                        printf("Invalid choice. Please enter a valid option.\n");
                }
            }
        } else {
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
