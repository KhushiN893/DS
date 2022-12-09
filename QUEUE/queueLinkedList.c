#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = 0;
struct node *rear = 0;
void enqueue(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
void display()
{
    struct node *temp;
    if (front == NULL && rear == NULL)
        printf("Queue is empty!");
    else
    {
        temp = front;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}
void dequeue()
{
    struct node *temp;
    temp = front;
    if (front == NULL && rear == NULL)
        printf("Queue is empty!");
    printf("\n%d is removed", front->data);
    front = front->next;
    free(temp);
}
int main()
{
    int data, choice;
    while (1)
    {
        printf("\nQUEUE OPERATION");
        printf("\n1] ENQUEUE \n2] DEQUEUE \n3] DISPLAY \n4] EXIT");
        printf("enter choice  : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data :");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Please! Enter valid choice :(");
        }
    }
}
