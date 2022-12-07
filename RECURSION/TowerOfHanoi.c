#include <stdio.h>
void tower(int n, char source, char dest, char auxiliary);
int main()
{
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    tower(n, 'A', 'B', 'C');
    return 0;
}
void tower(int n, char source, char dest, char auxiliary)
{
    int step = 0;
    if (n == 1)
        printf(" step %d : move from %c to %c \n ", ++step, source, dest);
    else
    {
        tower(n - 1, source, auxiliary, dest);
        printf(" step %d : move from %c to %c \n ", ++step, source, dest);
        tower(n - 1, auxiliary, dest, source);
    }
}
