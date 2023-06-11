#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to check if the stack is full
int isFull() {
    return top == MAX_SIZE - 1;
}

// Function to push (insert) an element into the stack
void push(int element) {
    if (isFull()) {
        printf("Stack Overflow. Cannot push element.\n");
    } else {
        stack[++top] = element;
        printf("Element %d pushed successfully.\n", element);
    }
}

// Function to pop (delete) an element from the stack
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow. Cannot pop element.\n");
    } else {
        int poppedElement = stack[top--];
        printf("Element %d popped successfully.\n", poppedElement);
    }
}

// Function to display all elements of the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Elements in the stack: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, element;

    while (1) {
        printf("\n**** MENU ****\n");
        printf("1. Push (Insert an element)\n");
        printf("2. Pop (Delete an element)\n");
        printf("3. Display all elements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
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
