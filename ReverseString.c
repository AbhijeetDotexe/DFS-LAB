#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char array[MAX_SIZE];
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

void push(struct Stack* stack, char ch) {
    if (isFull(stack)) {
        printf("Stack Overflow.\n");
        return;
    }
    stack->array[++stack->top] = ch;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow.\n");
        return '\0';
    }
    return stack->array[stack->top--];
}

void reverseString(char* str) {
    int length = strlen(str);
    struct Stack stack;
    initialize(&stack);

    // Push characters of the string into the stack
    for (int i = 0; i < length; i++) {
        push(&stack, str[i]);
    }

    // Pop characters from the stack to print in reverse order
    printf("Reversed string: ");
    while (!isEmpty(&stack)) {
        char ch = pop(&stack);
        printf("%c", ch);
    }
    printf("\n");
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character from the input string
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    reverseString(str);

    return 0;
}
