#include <stdio.h>
#include <ctype.h>
int stack[40];
int top = -1;
int temp = 0;
int pop()
{
    return stack[top--];
}
int push(int data)
{
    if (temp == 1)
    {
        int num;
        num = pop();
        stack[++top] = data + 10 * num;
    }
    else if (temp == 0)
    {
        stack[++top] = data;
        temp = 1;
    }
}

int main()
{
    char expression[50];
    char ch;
    int i = 0;
    printf("Enter the Postfix Expression(include space after each operator and operand) :");
    fgets(expression, 100, stdin);
    while ((ch = expression[i++]) != '\n')
    {
        if (isdigit(ch))
            push(ch - 48);
        else if (ch == ' ')
            temp = 0;
        else
        {
            temp = 0;
            int num2 = pop();
            int num1 = pop();
            if (ch == '+')
                push(num1 + num2);
            else if (ch == '-')
                push(num1 - num2);
            else if (ch == '*')
                push(num1 * num2);
            else if (ch == '/')
                push(num1 / num2);
            else if (ch == '%')
                push(num1 % num2);
            else if (ch == '^')
                push(num1 ^ num2);
            else
                printf("Sorry Invalid Choice!");
        }
    }

    printf("Result: %d\n", stack[top]);
}
