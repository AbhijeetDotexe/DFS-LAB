#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        swap(&arr[i], &arr[maxIndex]);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = { 5, 2, 8, 12, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    // Sort array using Bubble Sort
    bubbleSort(arr, n);
    printf("Array sorted using Bubble Sort: ");
    printArray(arr, n);

    // Restore original array
    int arr2[] = { 5, 2, 8, 12, 1 };

    // Sort array using Selection Sort
    selectionSort(arr2, n);
    printf("Array sorted using Selection Sort: ");
    printArray(arr2, n);

    return 0;
}
