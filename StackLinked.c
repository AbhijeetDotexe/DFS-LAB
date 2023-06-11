#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void initialize(struct Stack* stack) {
    stack->top = NULL;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Element %d pushed to the stack.\n", data);
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow.\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int poppedElement = temp->data;
    stack->top = temp->next;
    free(temp);
    printf("Element %d popped from the stack.\n", poppedElement);
    return poppedElement;
}

void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* current = stack->top;
    printf("Elements in the stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initialize(&stack);

    int choice, element;
    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(&stack, element);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                display(&stack);
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
