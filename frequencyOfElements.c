#include <stdio.h>

void findFrequency(int arr[], int n) {
    int freq[n];
    int visited = -1;

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                freq[j] = visited;
            }
        }
        if (freq[i] != visited) {
            freq[i] = count;
        }
    }

    printf("Element\tFrequency\n");
    for (int i = 0; i < n; i++) {
        if (freq[i] != visited) {
            printf("%d\t%d\n", arr[i], freq[i]);
        }
    }
}

int main() {
    int arr[] = {2, 4, 2, 6, 4, 8, 2, 4, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    findFrequency(arr, size);

    return 0;
}
