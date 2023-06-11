#include <stdio.h>
#include <stdlib.h>

struct DoubleStack {
    int* array;
    int top1;
    int top2;
    int capacity;
};

struct DoubleStack* createDoubleStack(int capacity) {
    struct DoubleStack* doubleStack = (struct DoubleStack*)malloc(sizeof(struct DoubleStack));
    if (doubleStack == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    doubleStack->capacity = capacity;
    doubleStack->array = (int*)malloc(capacity * sizeof(int));
    if (doubleStack->array == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    doubleStack->top1 = -1;
    doubleStack->top2 = capacity;
    return doubleStack;
}

int isFull(struct DoubleStack* doubleStack) {
    return doubleStack->top1 + 1 == doubleStack->top2;
}

int isEmpty1(struct DoubleStack* doubleStack) {
    return doubleStack->top1 == -1;
}

int isEmpty2(struct DoubleStack* doubleStack) {
    return doubleStack->top2 == doubleStack->capacity;
}

void push1(struct DoubleStack* doubleStack, int data) {
    if (isFull(doubleStack)) {
        printf("Stack Overflow.\n");
        return;
    }
    doubleStack->array[++doubleStack->top1] = data;
}

void push2(struct DoubleStack* doubleStack, int data) {
    if (isFull(doubleStack)) {
        printf("Stack Overflow.\n");
        return;
    }
    doubleStack->array[--doubleStack->top2] = data;
}

int pop1(struct DoubleStack* doubleStack) {
    if (isEmpty1(doubleStack)) {
        printf("Stack Underflow.\n");
        return -1;
    }
    return doubleStack->array[doubleStack->top1--];
}

int pop2(struct DoubleStack* doubleStack) {
    if (isEmpty2(doubleStack)) {
        printf("Stack Underflow.\n");
        return -1;
    }
    return doubleStack->array[doubleStack->top2++];
}

void displayStack1(struct DoubleStack* doubleStack) {
    printf("Stack 1: ");
    for (int i = doubleStack->top1; i >= 0; i--) {
        printf("%d ", doubleStack->array[i]);
    }
    printf("\n");
}

void displayStack2(struct DoubleStack* doubleStack) {
    printf("Stack 2: ");
    for (int i = doubleStack->top2; i < doubleStack->capacity; i++) {
        printf("%d ", doubleStack->array[i]);
    }
    printf("\n");
}

int main() {
    int capacity;
    printf("Enter the capacity of the double stack: ");
    scanf("%d", &capacity);

    struct DoubleStack* doubleStack = createDoubleStack(capacity);

    // Push elements into the double stack
    push1(doubleStack, 10);
    push1(doubleStack, 20);
    push2(doubleStack, 30);
    push2(doubleStack, 40);

    // Display the stacks
    displayStack1(doubleStack);
    displayStack2(doubleStack);

    // Pop elements from the stacks
    int popped1 = pop1(doubleStack);
    int popped2 = pop2(doubleStack);
    printf("Popped element from Stack 1: %d\n", popped1);
    printf("Popped element from Stack 2: %d\n", popped2);

    // Display the stacks again
    displayStack1(doubleStack);
    displayStack2(doubleStack);

    return 0;
}
