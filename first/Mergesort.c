#include <stdio.h>


void merge(int arr[],int low,int mid,int high){
    int n1= mid-low+1;
    int n2 = high-mid;
    int L[n1],R[n2];

    for(int i=0; i<n1;i++){
        L[i]=arr[low+i];
    }
    for(int j=0; j<n1;j++){
        R[j]=arr[mid+1+j];
    }
    int i=0;
    int j=0;
    int k = low;
    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }else{
            arr[k]=R[j];
            j++;
        }

        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}


void mergesort(int arr[],int low,int high){
    if(low>=high){return;}
     int mid = (low + high) /2;
     mergesort(arr,low,mid);
     mergesort(arr,mid+1,high);

     merge(arr,low,mid,high);
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

    // Perform merge sort
    mergesort(arr, 0, n - 1);

    // Display the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

return 0;
}