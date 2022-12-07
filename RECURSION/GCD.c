// Find Greatest Common Divisor
#include <stdio.h>
int gcdCalculate(int, int);
int main()
{
    int a, b;
    printf("Enter a :");
    scanf("%d", &a);
    printf("\nEnter b :");
    scanf("%d", &b);
    printf("%d & %d is %d", a, b, gcdCalculate(a, b));
    return 0;
}
int gcdCalculate(int a, int b)
{
    if (b == 0)
        return a;
    if (a == 0)
        return b;
    return gcdCalculate(b, a % b);
}
