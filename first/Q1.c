#include <stdio.h>

#define MAX_SIZE 100
// Function to Create the array
void createArr(int arr[],int size){
    int element;
    for(int i=0;i<size;i++){
        printf("Enter element for arr[%d] = ",i);
        scanf("%d", &element);
        arr[i]=element;
    }
}


// Function to traverse the array
void traverse(int arr[], int size) {
    printf("Array Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element after a specific element by value
void insertAfterValue(int arr[], int *size, int afterElement, int newElement) {
    if (*size >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }

    int position = -1; // Initialize position to -1 (not found)

    // Search for the element after which to insert the new element
    for (int i = 0; i < *size; i++) {
        if (arr[i] == afterElement) {
            position = i;
            break;
        }
    }

    if (position == -1) {
        printf("Element %d not found in the array. Insertion failed.\n", afterElement);
        return;
    }
    (*size)++;
    // Shift elements to the right to make space for the new element
    for (int i = *size; i > position + 1; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element
    arr[position + 1] = newElement;

    // (size)++;

    printf("Element %d inserted after %d.\n", newElement, afterElement);
}

// Function to delete an element at a specified position in the array
void delete(int arr[], int* size, int element) {
    if (*size == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }

    int position = -1; // Initialize position to -1 (not found)
    
    for (int i = 0; arr[i]== element; i++) {
        position=i;
    }
    if(position==-1){
        printf("Element %d not found in the array. Insertion failed.\n", element);
        return;
    }

    for(int i=position;i<*size-1;i++){
        arr[i]=arr[i+1];
    }

    (*size)--;
    printf("Element %d deleted from position %d.\n", element, position);
}

// Function to perform linear search for an element in the array
void linearSearch(int arr[], int size, int element) {
    // int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("Element %d found at position %d.\n", element, i);
            // found = 1;
            return;
        }
    }
    
    // if (!found) {
        printf("Element %d not found in the array.\n", element);
    // }
}

int main() {
    int arr[MAX_SIZE];
    int size =0;
    int choice, position, element;

    while (1) {
        printf("\nArray Operations Menu\n");
        printf("1. Create Array\n");
        printf("2. Traverse (Display) Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Linear Search\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter array size = ");
                scanf("%d", &size);
                createArr(arr,size);
                break;
            case 2:
                traverse(arr, size);
                break;
            case 3:
                printf("Enter position to insert: ");
                scanf("%d", &position);
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insertAfterValue(arr, &size, position, element);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                delete(arr, &size, position);
                break;
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &element);
                linearSearch(arr, size, element);
                break;
            case 6:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
