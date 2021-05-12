#include <stdio.h>
 
 
int swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void selectionSort(int arr[], int size) {
    int minIndex;
    int i, j;
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++) 
            if (arr[j] < arr[minIndex])
                minIndex = j;
         
        swap(&arr[i], &arr[minIndex]);
    }
}
void bubbleSort(int arr[], int size) {
    int i, j;
    for (i = size - 1; i>0; i--){
        for (j = 0; j<i; j++){
            if (arr[j]<arr[j+1]){
                swap(&arr[j], &arr[j + 1]);
	    }
	}
    }
}
void printArr(int arr[], int size){
    int i;
    for(i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int size) {
    int i, j,key;

    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0&&arr[j]>key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
 
int main() {
    int arr1[] = { 9,8,1,3,2 };
    int arr2[] = { 9,8,1,3,2 };
    int arr3[] = { 9,8,1,3,2 };
    int size = 5;
    printArr(arr1, size);
    selectionSort(arr1, size);
    printArr(arr1, size);
    printf("\n");
 
    printArr(arr2, size);
    bubbleSort(arr2, size);
    printArr(arr2, size);
    printf("\n");
 
    printArr(arr3, size);
    insertionSort(arr3, size);
    printArr(arr3, size);
 
    return 0;
}
