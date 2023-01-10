#include <stdio.h>

int binarySearch(int arr[], int n, int key)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {13, 2, 3, 4, 53};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    printf("Enter Element to search :");
    scanf("%d", &key);
    int index = binarySearch(arr, n, key);
    if (index == -1)
    {
        printf("Key not found\n");
    }
    else
    {
        printf("Key found at index %d\n", index);
    }
    return 0;
}
