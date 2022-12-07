#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
void push(int data);
void pop();
void display();
void main()
{
    while (1)
    {
        int choice, data;
        printf("\n----STACK OPERATIONS----\n");
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
            printf("Please! Enter valid choice:(\n");
            break;
        }
    }
}
// push data
void push(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = top;
    top = newnode;
}
// display data
void display()
{
    struct node *temp;
    temp = top;
    if (top == NULL)
        printf("\nStack Empty!");
    else
    {
        while (top != NULL)
        {
            printf("%d \t", temp->data);
            temp = temp->next;
        }
    }
}
// pop data
void pop()
{
    if (top == NULL)
        printf("\nStack Empty!");
    else
    {
        printf("%d is deleted!\n", top->data);
        top = top->next;
    }
}
