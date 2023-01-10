#include <stdio.h>
int main()
{
    int array[50], i, j, n, t;
    printf("Enter the no of elements :");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    for (i = 1; i <= n - 1; i++)
    {
        for (j = i; j > 0 && array[j - 1] > array[j]; j--)
        {
            t = array[j];
            array[j] = array[j - 1];
            array[j - 1] = t;
        }
    }
    printf("Sorting :");
    for (i = 0; i < n; i++)
        printf("%d\t", array[i]);
    return 0;
}
