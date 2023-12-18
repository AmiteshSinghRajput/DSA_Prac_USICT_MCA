#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5

int front = -1;
int rear = -1;
int queue[MAX_SIZE];

bool isEmpty() {
    return (front == -1 && rear == -1);
}

bool isFull() {
    return ((rear + 1) % MAX_SIZE == front);
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }

    queue[rear] = item;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a sentinel value to indicate an error
    }

    int dequeuedItem = queue[front];

    if (front == rear) {
        front = rear = -1; // Reset the front and rear pointers
    } else {
        front = (front + 1) % MAX_SIZE;
    }

    return dequeuedItem;
}

void display() {
    int i = front;
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    while (i != rear) {
        printf("%d, ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[rear]);
}

int main() {
    int choice, item;

    while (1) {
        printf("Circular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
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
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}
