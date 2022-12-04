#include <stdio.h>
#include <string.h>
#define size 50
int stack[size], top = -1;
void push(char c);
char pop();
void push(char c)
{
    if (top == size - 1)
        printf("String size is not allowed!");
    else
        stack[++top] = c;
}
char pop()
{
    return stack[top--];
}
int main()
{
    char str[size];
    printf("Enter String : ");
    gets(str);
    for (int i = 0; i < strlen(str); i++)
        push(str[i]);

    for (int i = 0; i < strlen(str); i++)
        printf("%c", pop());
    return 0;
}
