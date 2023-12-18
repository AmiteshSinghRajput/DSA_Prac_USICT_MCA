#include<stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int arr[],int low, int high){
    if(low<high){
        int partition= pivotAtItPlace(arr,low,high);

        quicksort(arr,low,partition-1);
        quicksort(arr,partition+1,high);

    }
}

int pivotAtItPlace(int arr[],int low,int high){
    int pivot=low;
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<arr[pivot]){
            i++;
        }
        while(arr[j]>arr[pivot]){
            j--;
        }
        if(i<j){swap(&arr[i], &arr[j]);}
    }
    swap(&arr[low], &arr[j]);
    return j;
}

int main(){

    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform quicksort
    quicksort(arr, 0, n - 1);

    // Display the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}