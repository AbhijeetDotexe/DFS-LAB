#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(struct Node* hashTable[], int data) {
    int index = hashFunction(data);
    struct Node* newNode = createNode(data);

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        struct Node* current = hashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayHashTable(struct Node* hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        struct Node* current = hashTable[i];
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct Node* hashTable[TABLE_SIZE] = { NULL };

    // Insert integers into the hash table
    int integers[] = { 10, 3, 9, 5, 10, 6, 2, 8, 7, 9, 1, 4, 3, 5, 6, 8, 2, 7, 1, 4 };
    int numIntegers = sizeof(integers) / sizeof(integers[0]);

    for (int i = 0; i < numIntegers; i++) {
        insert(hashTable, integers[i]);
    }

    // Display the hash table
    displayHashTable(hashTable);

    return 0;
}
