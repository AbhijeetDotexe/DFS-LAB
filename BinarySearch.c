#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is present at the middle
        if (arr[mid] == target) {
            return mid;
        }

        // If the target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If the target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    // Target not found in the array
    return -1;
}

int main() {
    int arr[] = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int target = 23;
    int index = binarySearch(arr, 0, size - 1, target);

    if (index != -1) {
        printf("Element %d found at index %d.\n", target, index);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
