#include <stdio.h>
#include <string.h>
int stack[20];
int top = -1;
int pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

void push(int oper)
{
    stack[++top] = oper;
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
        if (ex == '+' || ex == '-' || ex == '*' || ex == '/' || ex == '^')
        {
            int val1 = pop();
            int val2 = pop();
            switch (ex)
            {
            case '+':
                push(val2 + val1);
                break;
            case '-':
                push(val2 - val1);
                break;
            case '*':
                push(val2 * val1);
                break;
            case '/':
                push(val2 / val1);
                break;
            case '^':
                push(val2 / val1);
                break;
            }
        }
        else
            push(ex - 48); // ascii value of number is number+48
    }
    printf("%d", pop());
    return 0;
}
