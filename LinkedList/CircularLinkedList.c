#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *head = NULL, *x, *y;
void insertBegin(int);
void insertEnd(int);
void insertAfter(int, int);
void deleteBegin();
void deleteEnd();
void deleteAfter(int);
void display(struct Node *head);
int main()
{
    int data, location, choice, subchoice;
    while (1)
    {
        printf("\nMENU");
        printf("\n1 : INSERT\n2 : DELETE\n3 : DISPALY \n4 : EXIT");
        printf("\nEnter Your Choice :");
        scanf("%d", &choice);
        printf("\n===============================================\n");
        switch (choice)
        {
        case 1:
            printf("SUB MENU");
            printf("\n1 : AT BEGIN \n2 : AT END \n3 : AT SPECIFIC");
            printf("\nEnter Sub Choice : ");
            scanf("%d", &subchoice);
            printf("\n===============================================\n");
            if (subchoice == 1)
            {
                printf("\nEnter Data : ");
                scanf("%d", &data);
                insertBegin(data);
            }
            else if (subchoice == 2)
            {
                printf("\nEnter Data : ");
                scanf("%d", &data);
                insertEnd(data);
            }
            else if (subchoice == 3)
            {
                printf("\nEnter Data : ");
                scanf("%d", &data);
                printf("\nEnter Location : ");
                scanf("%d", &location);
                insertAfter(data, location);
            }
            else
            {
                printf("INVALID\n");
            }

            break;
        case 2:
            printf("SUB MENU");
            printf("\n1 : FROM BEGIN \n2 : FROM END \n3 : FROM SPECIFIC");
            printf("\nEnter Sub Choice : ");
            scanf("%d", &subchoice);
            printf("\n===============================================\n");
            if (subchoice == 1)
                deleteBegin();
            else if (subchoice == 2)
                deleteEnd();
            else if (subchoice == 3)
            {
                printf("\nEnter Location : ");
                scanf("%d", &location);
                deleteAfter(location);
            }
            else
            {
                printf("\nINVALID ");
            }
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(0);
        default:
            printf("\nINVALID ");
            break;
        }
    }
}
void insertBegin(int data)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        head = newNode;
        temp->next = head;
    }

    printf("\nOne node inserted!!!\n");
    printf("\n===============================================\n");
}
void insertEnd(int data)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    printf("\nOne node inserted!!!\n");
    printf("\n===============================================\n");
}
void insertAfter(int data, int location)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->data != location)
        {
            if (temp->next == head)
            {
                printf("Given node is not found in the list!!!");
                return;
            }
            else
            {
                temp = temp->next;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
        printf("\nOne node inserted!!!\n");
        printf("\n===============================================\n");
    }
}
void deleteBegin()
{
    if (head == NULL)
        printf("\n List is empty");
    else
    {
        x = head;
        y = head;
        while (x->next != head)
        {
            x = x->next;
        }
        head = y->next;
        x->next = head;
        free(y);
        printf("\nOne node deleted!!!\n");
        printf("\n===============================================\n");
    }
}
void deleteEnd()
{
    if (head == NULL)
        printf("List is Empty!!! Deletion not possible!!!");
    else
    {
        struct Node *temp1 = head, *temp2;
        if (temp1->next == head)
        {
            head = NULL;
            free(temp1);
        }
        else
        {
            while (temp1->next != head)
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            temp2->next = head;
            free(temp1);
        }
        printf("Node Deleted\n");
        printf("\n===============================================\n");
    }
}
void deleteAfter(int location)
{
    if (head == NULL)
        printf("Empty Linked List\n");
    else
    {
        struct Node *temp1;
        temp1 = head;
        struct Node *temp2;
        while (temp1->data != location)
        {
            if (temp1->next == head)
            {
                printf("Node Not Found!\n");
                printf("\n===============================================\n");
                return;
            }
            else
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
        }
        temp2->next = temp1->next;
        free(temp1);
        printf("Node Deleted\n");
        printf("\n===============================================\n");
    }
}
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
        struct Node *temp = head;
        printf("\nList elements are - \n");
        while (temp->next != head)
        {
            printf("%d --->", temp->data);
            temp = temp->next;
        }
        printf("%d --->head", temp->data);
        printf("\n===============================================");
    }
}
