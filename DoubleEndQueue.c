#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Deque {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

void initialize(struct Deque* deque) {
    deque->front = -1;
    deque->rear = -1;
}

int isEmpty(struct Deque* deque) {
    return deque->front == -1;
}

int isFull(struct Deque* deque) {
    return (deque->front == 0 && deque->rear == MAX_SIZE - 1) || (deque->front == deque->rear + 1);
}

void insertFront(struct Deque* deque, int element) {
    if (isFull(deque)) {
        printf("Deque Overflow.\n");
        return;
    }
    if (deque->front == -1) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = MAX_SIZE - 1;
    } else {
        deque->front--;
    }
    deque->arr[deque->front] = element;
    printf("Element %d inserted at the front of the deque.\n", element);
}

void insertRear(struct Deque* deque, int element) {
    if (isFull(deque)) {
        printf("Deque Overflow.\n");
        return;
    }
    if (deque->front == -1) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->rear == MAX_SIZE - 1) {
        deque->rear = 0;
    } else {
        deque->rear++;
    }
    deque->arr[deque->rear] = element;
    printf("Element %d inserted at the rear of the deque.\n", element);
}

int deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque Underflow.\n");
        return -1;
    }
    int deletedElement = deque->arr[deque->front];
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->front == MAX_SIZE - 1) {
        deque->front = 0;
    } else {
        deque->front++;
    }
    printf("Element %d deleted from the front of the deque.\n", deletedElement);
    return deletedElement;
}

int deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque Underflow.\n");
        return -1;
    }
    int deletedElement = deque->arr[deque->rear];
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->rear == 0) {
        deque->rear = MAX_SIZE - 1;
    } else {
        deque->rear--;
    }
    printf("Element %d deleted from the rear of the deque.\n", deletedElement);
    return deletedElement;
}

void display(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Elements in the deque: ");
    int i = deque->front;
    while (1) {
        printf("%d ", deque->arr[i]);
        if (i == deque->rear) {
            break;
        }
        if (i == MAX_SIZE - 1) {
            i = 0;
        } else {
            i++;
        }
    }
    printf("\n");
}

int main() {
    struct Deque deque;
    initialize(&deque);

    int choice, element;
    do {
        printf("\nDeque Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at the front: ");
                scanf("%d", &element);
                insertFront(&deque, element);
                break;
            case 2:
                printf("Enter the element to insert at the rear: ");
                scanf("%d", &element);
                insertRear(&deque, element);
                break;
            case 3:
                deleteFront(&deque);
                break;
            case 4:
                deleteRear(&deque);
                break;
            case 5:
                display(&deque);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
