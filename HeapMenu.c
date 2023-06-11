#include <stdio.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int size = 0;

// Function to swap two elements in the heap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to insert a node into the heap
void insertNode(int element) {
    if (size >= MAX_SIZE) {
        printf("Heap is full. Cannot insert element.\n");
        return;
    }

    size++;
    int index = size;
    heap[index] = element;

    while (index > 1 && heap[index / 2] < heap[index]) {
        swap(&heap[index / 2], &heap[index]);
        index /= 2;
    }

    printf("Element %d inserted successfully.\n", element);
}

// Function to delete the root node from the heap
void deleteNode() {
    if (size == 0) {
        printf("Heap is empty. Cannot delete element.\n");
        return;
    }

    int deletedElement = heap[1];
    heap[1] = heap[size];
    size--;

    int index = 1;
    while (1) {
        int leftChild = 2 * index;
        int rightChild = 2 * index + 1;

        if (leftChild > size) {
            break; // No child nodes exist
        }

        int maxChildIndex = leftChild;
        if (rightChild <= size && heap[rightChild] > heap[leftChild]) {
            maxChildIndex = rightChild;
        }

        if (heap[index] < heap[maxChildIndex]) {
            swap(&heap[index], &heap[maxChildIndex]);
            index = maxChildIndex;
        } else {
            break;
        }
    }

    printf("Element %d deleted successfully.\n", deletedElement);
}

// Function to display all elements of the heap
void display() {
    if (size == 0) {
        printf("Heap is empty.\n");
        return;
    }

    printf("Elements in the heap: ");
    for (int i = 1; i <= size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int choice, element;

    while (1) {
        printf("\n**** MENU ****\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Display all elements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertNode(element);
                break;
            case 2:
                deleteNode();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}
