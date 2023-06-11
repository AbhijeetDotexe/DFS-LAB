#include <stdio.h>

// Function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at given index
void heapify(int arr[], int size, int root) {
    int largest = root;       // Initialize largest as root
    int left = 2 * root + 1;  // Left child
    int right = 2 * root + 2; // Right child

    // If left child is larger than root
    if (left < size && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < size && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != root) {
        swap(&arr[root], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, size, largest);
    }
}

// Main function to perform heap sort
void heapSort(int arr[], int size) {
    // Build heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    // One by one extract an element from heap
    for (int i = size - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Original array: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array (ascending order): ");
    printArray(arr, n);

    return 0;
}
