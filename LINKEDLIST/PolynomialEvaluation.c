#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int coefficient;
    int power;
    struct node *next;
} typedef node;
void display(node *poly)
{
    if (poly == NULL)
        printf("Polynomial Empty");
    else
    {
        node *temp = poly;
        while (temp != NULL)
        {
            if (temp->coefficient > 0 && temp != poly)
                printf("+");
            printf(" %da^%d ", temp->coefficient, temp->power);
            temp = temp->next;
        }
    }
    printf("\n");
}
int Evaluate(node *list, int x)
{
    int ans = 0;
    while (list != NULL)
    {
        ans += list->coefficient * pow(x, list->power);
        list = list->next;
    }
    return ans;
}
node *createNode(int coefficient, int power)
{
    node *temp = malloc(sizeof(node));
    temp->coefficient = coefficient;
    temp->power = power;
    temp->next = NULL;
    return temp;
}
void insert(node **list, node *newNode)
{
    node *temp = *list;
    if (temp == NULL)
    {
        *list = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
int main()
{
    node *poly1 = NULL, *poly2 = NULL;
    insert(&poly1, createNode(4, 4));
    insert(&poly1, createNode(1, 3));
    insert(&poly1, createNode(-5, 1));
    printf("Given Polynomial : ");
    display(poly1);
    printf("Enter Value of a: ");
    int x;
    scanf("%d", &x);
    printf("\nResult : %d", Evaluate(poly1, x));
    return 0;
}