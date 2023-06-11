#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int array[MAX_SIZE];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int num) {
    if (isFull(stack)) {
        printf("Stack Overflow.\n");
        return;
    }
    stack->array[++stack->top] = num;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow.\n");
        return -1;
    }
    return stack->array[stack->top--];
}

void decimalToBinary(int decimal) {
    struct Stack stack;
    initialize(&stack);

    // Convert decimal to binary using stack
    while (decimal != 0) {
        int remainder = decimal % 2;
        push(&stack, remainder);
        decimal /= 2;
    }

    // Print the binary number by popping elements from the stack
    printf("Binary equivalent: ");
    while (!isEmpty(&stack)) {
        int binaryDigit = pop(&stack);
        printf("%d", binaryDigit);
    }
    printf("\n");
}

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    decimalToBinary(decimal);

    return 0;
}
