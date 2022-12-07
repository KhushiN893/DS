#include <stdio.h>
int ackermann(int, int);
int main()
{
    int m, n;
    printf("enter m : ");
    scanf("%d", &m);
    printf("enter n : ");
    scanf("%d", &n);
    printf("magical number is : %d ", ackermann(m, n));
    return 0;
}
int ackermann(int m, int n)
{
    if (m == 0)
        return n + 1;
    else if (n == 0 && m > 0)
    {
        return ackermann(m - 1, 1);
    }
    else
    {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}
