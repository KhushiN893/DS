#include <stdio.h>
int fibonacciSeries(int n);
int main()
{
    int n;
    printf("Enter Number : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        printf("%d\t", fibonacciSeries(i));
    return 0;
}
int fibonacciSeries(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return fibonacciSeries(n - 1) + fibonacciSeries(n - 2);
}
