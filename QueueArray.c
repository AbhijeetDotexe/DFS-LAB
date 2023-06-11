#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
int isFull() {
    return rear == MAX_SIZE - 1;
}

// Function to enqueue (insert) an element into the queue
void enqueue(int element) {
    if (isFull()) {
        printf("Queue Overflow. Cannot enqueue element.\n");
    } else {
        if (front == -1) {
            front = 0; // Set the front pointer for the first element
        }
        queue[++rear] = element;
        printf("Element %d enqueued successfully.\n", element);
    }
}

// Function to dequeue (delete) an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow. Cannot dequeue element.\n");
    } else {
        int dequeuedElement = queue[front++];
        printf("Element %d dequeued successfully.\n", dequeuedElement);
        if (front > rear) {
            front = rear = -1; // Reset the front and rear pointers when the queue becomes empty
        }
    }
}

// Function to display all elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Elements in the queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, element;

    while (1) {
        printf("\n**** MENU ****\n");
        printf("1. Enqueue (Insert an element)\n");
        printf("2. Dequeue (Delete an element)\n");
        printf("3. Display all elements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
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
