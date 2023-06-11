#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, count = 1;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    printf("\nEnter elements in the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int* freq = (int*)malloc(n * sizeof(int));
    int visited = -1;

    for (i = 0; i < n; i++)
    {
        count = 1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                freq[j] = visited;
            }
        }
        if (freq[i] != visited)
            freq[i] = count;
    }

    printf("\nFrequencies of Elements are:\n");
    for (i = 0; i < n; i++)
    {
        if (freq[i] != visited)
        {
            printf("%d %d\n", arr[i], freq[i]);
        }
    }

    free(arr);
    free(freq);
    return 0;
}
