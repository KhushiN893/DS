#include <stdio.h>
#define size 50
int stack[size], top = -1;
void push(int i);
int pop();
void push(int i)
{
    if (top == size - 1)
        printf("Stack is full");
    else
        stack[++top] = i;
}
int pop()
{
    return stack[top--];
}

int main()
{
    int num, remainder;
    printf("Enter Decimal Number to convert into Binary : ");
    scanf("%d", &num);
    while (num > 0)
    {
        remainder = num % 2;
        num = num / 2;
        push(remainder);
    }
    printf("Converted Binary Number  : ");
    while (top >= 0)
    {
        printf("%d", pop());
    }
    return 0;
}
