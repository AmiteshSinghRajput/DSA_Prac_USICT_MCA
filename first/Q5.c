#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5                              // Define the maximum size of the stack

int stack[MAX_SIZE];
int top = -1;                                   // Initialize the top of the stack to -1

// Function to check if the stack is empty
bool is_empty() {
    return top == -1;
}

// Function to check if the stack is full
bool is_full() {
    return top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(int item) {
    if (is_full()) {
        printf("Stack Overflow: Cannot push item onto a full stack.\n");
    } else {
        top++;
        stack[top] = item;
        printf("Pushed %d onto the stack.\n", item);
    }
}

// Function to pop an element from the stack
int pop() {
    if (is_empty()) {
        printf("Stack Underflow: Cannot pop item from an empty stack.\n");
        return -1; // Return a sentinel value to indicate an error
    } else {
        int item = stack[top];
        top--;
        printf("Popped %d from the stack.\n", item);
        return item;
    }
}


// Function to display the Top elements from the stack
void Peep() {
    if (is_empty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack contents: ");
            printf("%d ", stack[top]);
        
        printf("\n");
    }
}




// Function to display the elements in the stack
void display() {
    if (is_empty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack contents: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, item;

    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                Peep();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
