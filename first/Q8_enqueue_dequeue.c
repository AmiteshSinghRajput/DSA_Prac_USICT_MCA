#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 4

int front = 0;
int rear = -1;
int queue[MAX_SIZE];

bool isEmpty() {
    return (rear == -1);
}

bool isFull() {
    return (rear == MAX_SIZE - 1);
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    rear++;
    queue[rear] = item;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a sentinel value to indicate an error
    }

    int dequeuedItem = queue[front];
    if (front == rear) {
        front=-1; // Reset the front and rear pointers
        rear=-1;
    } 
    front++;


    return dequeuedItem;
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, item;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Check if Empty\n5. Check if Full\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                item = dequeue();
                    printf("Dequeued: %d\n", item);
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                isEmpty() ? printf("Queue is empty.\n") : printf("Queue is not empty.\n");
                break;
            case 5:
                isFull() ? printf("Queue is full.\n") : printf("Queue is not full.\n");
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
