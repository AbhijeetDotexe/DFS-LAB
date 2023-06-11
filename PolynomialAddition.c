#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a term in the polynomial
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term at the end of the polynomial
void insertTerm(struct Node** poly, int coefficient, int exponent) {
    struct Node* newNode = createNode(coefficient, exponent);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the polynomial
void displayPolynomial(struct Node* poly) {
    if (poly == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    struct Node* temp = poly;
    while (temp != NULL) {
        printf("(%dx^%d) ", temp->coefficient, temp->exponent);
        if (temp->next != NULL) {
            printf("+ ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0) {
                insertTerm(&result, sum, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    // Polynomial 4x^4 + 4x^3 - 2x^2 + x
    insertTerm(&poly1, 4, 4);
    insertTerm(&poly1, 4, 3);
    insertTerm(&poly1, -2, 2);
    insertTerm(&poly1, 1, 1);

    // Polynomial 11x^3 + 7x^2 - 4x
    insertTerm(&poly2, 11, 3);
    insertTerm(&poly2, 7, 2);
    insertTerm(&poly2, -4, 1);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    struct Node* sum = addPolynomials(poly1, poly2);

    printf("Sum of polynomials: ");
    displayPolynomial(sum);

    return 0;
}
