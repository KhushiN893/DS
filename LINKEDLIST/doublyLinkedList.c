#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next, *prev;
} typedef Node;

Node *start;

Node *newNode(int data)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void insertBegin(Node *temp)
{
    if (start == NULL)
        start = temp;
    else
    {
        temp->next = start;
        start->prev = temp;
        start = temp;
    }
}
void insertEnd(Node *temp)
{
    if (start == NULL)
        start = temp;
    else
    {
        Node *curr = start;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }
}
void insertMiddle(Node *temp, int pos)
{
    if (start == NULL)
        start = temp;
    else
    {
        Node *curr = start, *prev = NULL;
        for (int i = 1; i < pos; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = temp;
        temp->prev = prev;
        temp->next = curr;
        curr->prev = temp;
    }
}
void deleteBegin()
{
    if (start == NULL)
        printf("List Empty!!");
    else
    {
        Node *temp = start;
        start = start->next;
        start->prev = NULL;
        printf("%d Deleted successfully!\n", temp->data);
        free(temp);
    }
}

void deleteEnd()
{
    if (start == NULL)
        printf("List Empty!!");
    else
    {
        Node *curr = start, *prev = NULL;
        while (curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        printf("%d Deleted successfully!\n", curr->data);
        free(curr);
    }
}
void deleteMiddle(int pos)
{
    if (start == NULL)
        printf("List Empty!!");
    else
    {
        Node *curr = start, *prev = NULL;
        for (int i = 1; i < pos; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next->prev = prev;
        printf("%d Deleted successfully!\n", curr->data);
        free(curr);
    }
}

void display_list()
{
    Node *temp = start;
    printf("Your List : ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    insertBegin(newNode(5));
    insertEnd(newNode(2));
    insertEnd(newNode(13));
    insertEnd(newNode(8));
    insertMiddle(newNode(13), 2);
    display_list();
    insertMiddle(newNode(35), 2);
    display_list();
    deleteMiddle(4);
    display_list();
    deleteBegin();
    display_list();
    deleteEnd();
    display_list();
    return 0;
}