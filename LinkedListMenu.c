#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Element inserted at the beginning successfully.\n");
}

// Function to insert a node at a specific location in the list
void insertAtLocation(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        printf("Element inserted at position %d successfully.\n", position);
        return;
    }
    struct Node* temp = *head;
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("Element inserted at position %d successfully.\n", position);
        return;
    }
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position.\n");
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Element inserted at position %d successfully.\n", position);
    }
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        printf("Element inserted at the end successfully.\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Element inserted at the end successfully.\n");
}

// Function to delete a node from the beginning of the list
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
    printf("Element deleted from the beginning successfully.\n");
}

// Function to delete a node from a specific location in the list
void deleteFromLocation(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if (position == 1) {
        *head = temp->next;
        free(temp);
        printf("Element deleted from position %d successfully.\n", position);
        return;
    }
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
    } else {
        struct Node* deleteNode = temp->next;
        temp->next = deleteNode->next;
        free(deleteNode);
        printf("Element deleted from position %d successfully.\n", position);
    }
}

// Function to delete a node from the end of the list
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Element deleted from the end successfully.\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Element deleted from the end successfully.\n");
}

// Function to display all elements of the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Elements of the list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to search for a specific element in the list
void searchElement(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the list.\n", key);
}

int main() {
    struct Node* head = NULL;
    int choice, element, position;

    while (1) {
        printf("\n**** MENU ****\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at specific location\n");
        printf("3. Insert at end\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from specific location\n");
        printf("6. Delete from end\n");
        printf("7. Display all elements\n");
        printf("8. Search an element\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertAtBeginning(&head, element);
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertAtLocation(&head, element, position);
                break;
            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertAtEnd(&head, element);
                break;
            case 4:
                deleteFromBeginning(&head);
                break;
            case 5:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteFromLocation(&head, position);
                break;
            case 6:
                deleteFromEnd(&head);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                searchElement(head, element);
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
