#include <stdio.h>
#include <stdlib.h>
// ADJACENCY MATRIX
int start, Vertex, Edge, visited[50], Graph[50][50];
void DFSMatrix(int i)
{
    int j = 0;
    visited[i] = 1;
    printf(" %d -> ", i + 1);
    while (j < Vertex)
    {
        if (Graph[i][j] == 1 && visited[j] == 0)
            DFSMatrix(j);
        j++;
    }
}
int main()
{
    printf("Enter the no of edges:");
    scanf("%d", &Edge);
    printf("Enter the no of vertices:");
    scanf("%d", &Vertex);
    for (int i = 0; i < Vertex; i++)
    {
        for (int j = 0; j < Vertex; j++)
            Graph[i][j] = 0;
    }
    Graph[0][1] = 1;
    Graph[0][3] = 1;
    Graph[1][3] = 1;
    Graph[1][4] = 1;
    Graph[2][0] = 1;
    Graph[2][3] = 1;
    Graph[3][4] = 1;
    Graph[3][2] = 1;
    // print matrix
    for (int i = 0; i < Vertex; i++)
    {
        for (int j = 0; j < Vertex; j++)
            printf(" %d ", Graph[i][j]);
        printf("\n");
    }
    printf("Enter the start: ");
    scanf("%d", &start);
    DFSMatrix(start - 1);
    return 0;
}