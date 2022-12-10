#include <stdio.h>
#include <stdlib.h>
#define max 20
int queue[max];
int front = -1;
int rear = -1;
void enqueue(int data);
void dequeue();
void display();
// inserting data
void enqueue(int data)
{
    if (front == (rear + 1) % max)
        printf("Queue is full");

    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = data;
    }
    else
    {
        rear = (rear + 1) % max;
        queue[rear] = data;
    }
}
// deleting data
void dequeue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is Empty!");
    }
    else if (front == rear)
    {
        printf("\n%d is deleted ", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\n%d is deleted!", queue[front]);
        front = (front + 1) % max;
    }
}
// displaying data
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is empty..");
    }
    else
    {
        printf("\nData in Queue :");
        while (i != rear)
        {
            printf("%d,", queue[i]);
            i = (i + 1) % max;
        }
    }
}
int main()
{
    int data, choice;
    while (1)
    {
        printf("\nQUEUE OPERATION");
        printf("\n1] ENQUEUE \n2] DEQUEUE \n3] DISPLAY \n4] EXIT");
        printf("\nenter choice  : ");
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
