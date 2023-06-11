#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void initialize(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Element %d enqueued to the queue.\n", data);
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow.\n");
        return -1;
    }
    struct Node* temp = queue->front;
    int dequeuedElement = temp->data;
    queue->front = temp->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    printf("Element %d dequeued from the queue.\n", dequeuedElement);
    return dequeuedElement;
}

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* current = queue->front;
    printf("Elements in the queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    initialize(&queue);

    int choice, element;
    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(&queue, element);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
