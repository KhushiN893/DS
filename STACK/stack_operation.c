#include <stdio.h>
#include <stdlib.h>
#define size 10
void push(int data);
void pop();
void display();
int top = -1;
int stack[size];
int main()
{
    while (1)
    {
        int choice, data;
        printf("----STACK OPERATIONS----\n");
        printf("\n1: PUSH \n2: POP \n3: DISPLAY \n4: EXIT\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to Insert :");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Please! Enter valid choice:(");
            break;
        }
    }
    return 0;
}
//function to insert data
void push(int data)
{
    if (top == size - 1)
        printf("SORRY! STACK IS OVERFLOW\n");
    else
    {
        top++;
        stack[top] = data;
        printf("%d is inserted successfully \n", data);
    }
}
//function to delete the element
void pop()
{
    if (top == -1)
        printf("SORRY! STACK IS EMPTY\n");
    else
    {
        printf("%d is deleted successsfully! \n", stack[top]);
        top--;
    }
}
//function to dispaly stack data
void display()
{
    if (top == -1)
        printf("SORRY! STACK IS EMPTY\n");
    else
    {
        printf("STACK ELEMENTS ARE : \n");
        for (int i = top; i >= 0; i--)
            printf("%d\t", stack[i]);
    }
}
