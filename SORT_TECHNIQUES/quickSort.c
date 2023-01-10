#include <stdio.h>
void quicksort(int[], int, int);
int main()
{
    int list[50];
    int size, i;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    printf("Enter the elements :\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &list[i]);
    }
    quicksort(list, 0, size - 1);
    printf("SORTED ARRAY :\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}
void quicksort(int list[], int low, int high)
{
    int pivot, i, j, temp;
    if (low >= high)
    {
        return;
    }
    else
    {
        pivot = list[low];
        i = low + 1;
        j = high;
        while (i <= j)
        {
            while (list[i] <= pivot && i <= high)
            {
                i++;
            }
            while (list[j] > pivot && j > low)
            {
                j--;
            }
            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        list[low] = list[j];
        list[j] = pivot;
        quicksort(list, low, j - 1);
        quicksort(list, j + 1, high);
    }
}
