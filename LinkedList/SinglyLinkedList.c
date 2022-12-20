#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;
void insertBegin(int);
void insertEnd(int);
void insertAfter(int, int);
void deleteBegin();
void deleteEnd();
void deleteAfter(int);
void display(struct Node *head);
void reverse();
void Concat(struct Node *first, struct Node *second);
struct Node *Create(int A[], int n)
{
    int i;
    struct Node *t, *last, *temp;
    temp = NULL;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = A[0];
    temp->next = NULL;
    last = temp;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return temp;
}
int main()
{
    int data, location, choice, subchoice;
    struct Node *first = NULL, *second = NULL;
    int A[] = {9, 7, 4, 3};
    int B[] = {2, 5, 6, 8};
    while (1)
    {
        printf("\nMENU");
        printf("\n1 : INSERT\n2 : DELETE\n3 : DISPALY \n4 : REVERSE \n5 : CONCATENATE \n6 : EXIT");
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
            reverse();
            display(head);
            break;
        case 5:
            first = Create(A, 4);
            second = Create(B, 4);
            printf("1st Linked List: ");
            display(first);
            printf("\n2nd Linked List: ");
            display(second);
            Concat(first, second);
            printf("\n\nConcantenated Linked List: \n");
            display(first);
            break;
        case 6:
            exit(0);
            break;
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
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    printf("\nOne node inserted!!!\n");
    printf("\n===============================================\n");
}
void insertEnd(int data)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else
    {
        struct Node *temp;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("\nOne node inserted!!!\n");
    printf("\n===============================================\n");
}
void insertAfter(int data, int location)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node *temp;
    temp = head;
    while (temp->data != location && temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("\nOne node inserted!!!\n");
    printf("\n===============================================\n");
}
void deleteBegin()
{
    if (head == NULL)
        printf("Empty Linked List\n");
    else
    {
        struct Node *temp;
        temp = head;
        if (head->next == NULL)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            head = temp->next;
            free(temp);
            printf("Node Deleted\n");
            printf("\n===============================================\n");
        }
    }
}
void deleteEnd()
{
    if (head == NULL)
        printf("Empty Linked List\n");
    else
    {
        struct Node *temp1;
        struct Node *temp2;
        temp1 = head;
        if (temp1->next == NULL)
        {
            head = NULL;
            free(temp1);
        }
        else
        {
            while (temp1->next != NULL)
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            temp2->next = NULL;
            free(temp1);
            printf("Node Deleted\n");
            printf("\n===============================================\n");
        }
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
            if (temp1->next == NULL)
            {
                printf("Node Not Found!\n");
                printf("\n===============================================\n");
            }
            temp2 = temp1;
            temp1 = temp1->next;
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
        while (temp->next != NULL)
        {
            printf("%d --->", temp->data);
            temp = temp->next;
        }
        printf("%d --->NULL", temp->data);
        printf("\n===============================================");
    }
}
void reverse()
{
    struct Node *prev;
    struct Node *current;
    struct Node *nextnode;
    prev = NULL;
    current = head;
    nextnode = head;
    while (nextnode != NULL)
    {
        nextnode = nextnode->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    head = prev;
}
void Concat(struct Node *first, struct Node *second)
{
    struct Node *p = first;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = second;
    second = NULL;
}
