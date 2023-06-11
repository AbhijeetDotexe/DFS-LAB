#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Student {
    float grade;
    char name[50];
};

void findHighestGrade(struct Student students[], int numStudents) {
    float highestGrade = -1.0;
    int i;

    // Find the highest grade
    for (i = 0; i < numStudents; i++) {
        if (students[i].grade > highestGrade) {
            highestGrade = students[i].grade;
        }
    }

    // Display all students with the highest grade
    printf("Students with the highest grade:\n");
    for (i = 0; i < numStudents; i++) {
        if (students[i].grade == highestGrade) {
            printf("%s\n", students[i].name);
        }
    }
}

void findThirdHighestGrade(struct Student students[], int numStudents) {
    float grades[MAX_SIZE];
    int i, j;

    // Copy grades to a separate array
    for (i = 0; i < numStudents; i++) {
        grades[i] = students[i].grade;
    }

    // Sort the grades in descending order
    for (i = 0; i < numStudents; i++) {
        for (j = i + 1; j < numStudents; j++) {
            if (grades[i] < grades[j]) {
                float temp = grades[i];
                grades[i] = grades[j];
                grades[j] = temp;
            }
        }
    }

    // Find the 3rd highest grade and display the student details
    float thirdHighestGrade = grades[2];
    printf("\nStudent(s) with the 3rd highest grade:\n");
    for (i = 0; i < numStudents; i++) {
        if (students[i].grade == thirdHighestGrade) {
            printf("Name: %s, Grade: %.2f\n", students[i].name, students[i].grade);
        }
    }
}

int main() {
    FILE *file = fopen("grades.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    struct Student students[MAX_SIZE];
    int numStudents = 0;

    // Read student details from the file
    while (fscanf(file, "%f %s", &students[numStudents].grade, students[numStudents].name) != EOF) {
        numStudents++;
    }

    fclose(file);

    findHighestGrade(students, numStudents);
    findThirdHighestGrade(students, numStudents);

    return 0;
}
