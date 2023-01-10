#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int dqueue[MAX];
int left = -1;
int right = -1;

void insert_right();
void insert_left();
void delete_left();
void delete_right();
void display_que();

void input_restrict_dqueue()
{
    int choice;
    while (1)
    {
        printf("\n1].Insert at right: ");
        printf("\n2].Delete from left: ");
        printf("\n3].Delete from right: ");
        printf("\n4].Display: ");
        printf("\n5].Return");
        printf("\n6].Quit ");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_right();
            break;
        case 2:
            delete_left();
            break;
        case 3:
            delete_right();
            break;
        case 4:
            display_que();
            break;
        case 5:
            return;
        case 6:
            exit(1);
        default:
            printf("\n Wrong choice:");
        }
    }
}

void output_restrict_dqueue()
{
    int choice;
    while (1)
    {
        printf("\n1].Insert at right: ");
        printf("\n2].Insert at left : ");
        printf("\n3].Delete from left: ");
        printf("\n4].Display: ");
        printf("\n5].Return");
        printf("\n6].Quit ");
        printf("\nEnter your choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_right();
            break;
        case 2:
            insert_left();
            break;
        case 3:
            delete_left();
            break;
        case 4:
            display_que();
            break;
        case 5:
            return;
        case 6:
            exit(1);
        default:
            printf("\n Wrong choice:");
        }
    }
}
int main()
{
    int option;
    while (1)
    {
        printf("\n1.Input restricted dequeue  :");
        printf("\n2.Output restricted dequeue :");
        printf("\n3.Exit:");
        printf("\nEnter your choice:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            input_restrict_dqueue();
            break;
        case 2:
            output_restrict_dqueue();
            break;
        case 3:
            return 0;

        default:
            printf("\nWrong choice");
        }
    }
} // main

void insert_right()
{
    int data;
    if ((left == 0 && right == MAX - 1) || (left == right + 1))
    {
        printf("\nQueue Overflow:");
        return;
    }
    if (left == -1)
    {
        left = 0;
        right = 0;
    }
    else if (right == MAX - 1)
        return;
    else
        right = right + 1;
    printf("\nEnter Data:");
    scanf("%d", &data);
    dqueue[right] = data;
}
void insert_left()
{
    int data;
    if ((left == 0 && right == MAX - 1) || (left == right + 1))
    {
        printf("\nQueue Overflow");
        return;
    }
    if (left == -1)
    {
        left = 0;
        right = 0;
    }
    else if (left == 0)
        left = MAX - 1;
    else
        left = left - 1;

    printf("\nEnter Data: ");
    scanf("%d", &data);
    dqueue[left] = data;
}
void delete_left()
{
    if (left == -1)
    {
        printf("Queue Underflow");
        return;
    }
    printf("\nDeleted Data is:%d", dqueue[left]);
    if (left == right)
    {
        left = -1;
        right = -1;
    }
    else if (left == MAX - 1)
        left = 0;
    else
        left = left + 1;
}
void delete_right()
{
    if (left == -1)
    {
        printf("Queue Underflow ");
        return;
    }
    printf("\nDeleted data is:%d", dqueue[right]);
    if (left == right)
    {
        left = -1;
        right = -1;
    }
    else if (right == 0)
        right = MAX - 1;
    else
        right = right - 1;
}
void display_que()
{
    int fposition = left, rposition = right;
    if (left == -1)
    {
        printf("Queue is empty ");
        return;
    }
    printf("\nQueue elements : ");
    if (fposition <= rposition)
    {
        while (fposition <= rposition)
        {
            printf(" %d", dqueue[fposition]);
            fposition++;
        }
    }
    else
    {
        while (fposition <= MAX - 1)
        {
            printf("%d ", dqueue[fposition]);
            fposition++;
        }
        fposition = 0;
        while (fposition <= rposition)
        {
            printf("%d ", dqueue[fposition]);
            fposition++;
        }
    }
}
