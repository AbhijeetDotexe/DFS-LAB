#include <stdio.h>

int main()
{
    int n, i, item, flag = 0;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n]; // creation of array
    printf("\nEnter elements in the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &item);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == item)
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        printf("\n%d found at position %d", item, i + 1);
    }
    else
    {
        printf("\n%d not found in the array.", item);
    }

    return 0;
}
