#include <stdio.h>
int main()
{
    int array[100], n, swap;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    printf("Enter %d Elements : \n", n);
    for (int c = 0; c < n; c++)
        scanf("%d", &array[c]);

    int search, found = 0;
    printf("Enter element to search :");
    scanf("%d", &search);

    for (int i = 0; i < n; i++)
    {
        if (search == array[i])
        {
            printf("Element %d found at %d location", array[i], i + 1);
            found++;
        }
    }
    if (found == 0)
    {
        printf("Element %d not found !", search);
    }
    return 0;
}