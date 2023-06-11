#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100

void generateRandomNumbers(int numbers[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        numbers[i] = rand();
    }
}

void writeToFile(int numbers[], int n, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", numbers[i]);
    }

    fclose(file);
}

void copyNumbersToFiles(const char* inputFilename, const char* oddFilename, const char* evenFilename) {
    FILE* inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        printf("Error opening file %s\n", inputFilename);
        return;
    }

    FILE* oddFile = fopen(oddFilename, "w");
    if (oddFile == NULL) {
        printf("Error opening file %s\n", oddFilename);
        fclose(inputFile);
        return;
    }

    FILE* evenFile = fopen(evenFilename, "w");
    if (evenFile == NULL) {
        printf("Error opening file %s\n", evenFilename);
        fclose(inputFile);
        fclose(oddFile);
        return;
    }

    int number;
    while (fscanf(inputFile, "%d", &number) != EOF) {
        if (number % 2 == 0) {
            fprintf(evenFile, "%d\n", number);
        } else {
            fprintf(oddFile, "%d\n", number);
        }
    }

    fclose(inputFile);
    fclose(oddFile);
    fclose(evenFile);
}

void displayFileContents(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    int number;
    printf("Contents of %s:\n", filename);
    while (fscanf(file, "%d", &number) != EOF) {
        printf("%d\n", number);
    }

    fclose(file);
}

int main() {
    int numbers[MAX_NUMBERS];
    int n;

    printf("Enter the number of random integers to generate: ");
    scanf("%d", &n);

    generateRandomNumbers(numbers, n);
    writeToFile(numbers, n, "All.txt");

    copyNumbersToFiles("All.txt", "Odd.txt", "Even.txt");

    displayFileContents("All.txt");
    printf("\n");
    displayFileContents("Odd.txt");
    printf("\n");
    displayFileContents("Even.txt");

    return 0;
}
