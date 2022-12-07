#include <stdio.h>
#include <stdlib.h>
#define size 20
int queue[size];
int front = -1, rear = -1;
void enqueue(int data);
void display();
void dequeue();
void enqueue(int data)
{
    if (rear == size - 1)
        printf("\n Sorry! Queue is full!");
    else
    {
        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
        }
        queue[rear++] = data;
        printf("%d inserted successfully!", data);
    }
}
void dequeue()
{
    if (front == -1 || front > rear)
        printf("Queue is empty!");
    else
        printf("%d is deleted!", queue[front++]);
}
void display()
{
    if (rear == -1)
        printf("Queue is empty");
    else
    {
        printf("Queue Elements are : ");
        for (int i = front; i < rear; i++)
            printf("%d \t", queue[i]);
    }
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
    return 0;
}
