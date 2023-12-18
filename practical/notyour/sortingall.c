#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int A[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d, ", A[i]);
}

void merge(int A[], int l, int mid, int h) {
    int i, j, k;
    i = l, j = mid + 1, k = l;
    int B[100];

    while (i <= mid && j <= h) {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    while (i <= mid)
        B[k++] = A[i++];

    while (j <= h)
        B[k++] = A[j++];

    for (int i = l; i <= h; i++)
        A[i] = B[i];
}

void merge_sort(int A[], int l, int h) {
    int mid;
    if (l < h) {
        mid = (l + h) / 2;
        merge_sort(A, l, mid);
        merge_sort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}

int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l, j = h;

    do {
        do {
            i++;
        } while (A[i] <= pivot);

        do {
            j--;
        } while (A[j] > pivot);

        if (i < j)
            swap(&A[i], &A[j]);
    } while (i < j);

    swap(&A[l], &A[j]);
    return j;
}

void quick_sort(int A[], int l, int h) {
    int j;
    if (l < h) {
        j = partition(A, l, h);
        quick_sort(A, l, j);
        quick_sort(A, j + 1, h);
    }
}

void insertion_sort(int A[], int n) {
    int i, j, temp;

    for (i = 1; i < n; i++) {
        temp = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > temp) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
}

int main() {
    int A[10];
    int n = 10;
    int option;

    printf("Enter 10 integers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    do {
        printf("\nMenu\n");
        printf("1. Merge Sort\n");
        printf("2. Quick Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                merge_sort(A, 0, n - 1);
                printf("Sorted array using Merge Sort:\n");
                display(A, n);
                break;

            case 2:
                quick_sort(A, 0, n - 1);
                printf("Sorted array using Quick Sort:\n");
                display(A, n);
                break;

            case 3:
                insertion_sort(A, n);
                printf("Sorted array using Insertion Sort:\n");
                display(A, n);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

    } while (option != 4);

    return 0;
}
