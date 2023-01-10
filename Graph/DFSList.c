#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *next;
    int vertex;
} node;

node *Graph[20];
int visited[20], Vertex;

void insert(int vi, int vj)
{
    node *p, *q;
    q = (node *)malloc(sizeof(node));
    q->vertex = vj;
    q->next = NULL;
    if (Graph[vi] == NULL)
        Graph[vi] = q;
    else
    {
        p = Graph[vi];
        while (p->next != NULL)
            p = p->next;
        p->next = q;
    }
}

void readGraph()
{
    int i, vi, vj, edges;
    printf("Enter number of vertices:");
    scanf("%d", &Vertex);

    for (i = 0; i < Vertex; i++)
    {
        Graph[i] = NULL;
        printf("Enter number of edges:");
        scanf("%d", &edges);
        for (i = 0; i < edges; i++)
        {
            printf("Enter an edge(u,v):");
            scanf("%d%d", &vi, &vj);
            insert(vi, vj);
        }
    }
}
void DFS(int i)
{
    node *p;

    printf("%d ->", i);
    p = Graph[i];
    visited[i] = 1;
    while (p != NULL)
    {
        i = p->vertex;

        if (!visited[i])
            DFS(i);
        p = p->next;
    }
}

void main()
{
    int i, start;
    readGraph();
    for (i = 0; i < Vertex; i++)
        visited[i] = 0;
    printf("Enter the start: ");
    scanf("%d", &start);
    printf("Result : ");
    DFS(start - 1);
}
