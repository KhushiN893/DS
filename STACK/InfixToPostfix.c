#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char stack[20];
int top = -1;
char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

void push(char oper)
{
    stack[++top] = oper;
}
int precedence(char ch)
{
    if (ch == '(')
        return 0;
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 3;
}
int main()
{
    char experssion[20];
    char ex, x;
    printf("Enter Infix Expression : ");
    scanf("%s", experssion);
    for (int i = 0; i < strlen(experssion); i++)
    {
        ex = experssion[i];
        if ((ex >= 'A' && ex <= 'Z') || (ex >= 'a' && ex <= 'z') || (ex >= '0' && ex <= '9'))
            printf("%c", ex);
        else if (ex == '(')
            push(ex);
        else if (ex == ')')
        {
            while ((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while (precedence(stack[top]) >= precedence(ex))
                printf("%c", pop());
            push(ex);
        }
    }
    while (top != -1)
        printf("%c", pop());
    return 0;
}
