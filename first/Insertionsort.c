#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 0; i < n; i++) {
        j=i;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j > 0 && arr[j] < arr[j-1]) {
            int temp = arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            
            j--;
        }
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
