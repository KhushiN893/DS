/* Bubble sort code */
#include <stdio.h>
int main()
{
    int array[100], n, swap;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    printf("Enter %d Elements : \n", n);
    for (int c = 0; c < n; c++)
        scanf("%d", &array[c]);

    for (int c = 0; c < n - 1; c++)
    {
        for (int d = 0; d < n - c - 1; d++)
        {
            if (array[d] > array[d + 1])
            {
                swap = array[d];
                array[d] = array[d + 1];
                array[d + 1] = swap;
            }
        }
    }
    printf("Sorted Array :\n");
    for (int c = 0; c < n; c++)
        printf("%d\t", array[c]);
    return 0;
}