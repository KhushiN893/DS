#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100 // Maximum number of nodes in the graph

// The adjacency matrix representation of the graph
int graph[MAX_NODES][MAX_NODES];

// The number of nodes in the graph
int numNodes;

// Array to keep track of which nodes have been visited
bool visited[MAX_NODES];

// Queue for storing the nodes to visit
int queue[MAX_NODES];
int head = 0; // Head of the queue
int tail = 0; // Tail of the queue

// Function to perform a breadth-first search on the graph
void BFS(int startNode)
{
    // Mark the start node as visited
    visited[startNode] = true;

    // Enqueue the start node
    queue[tail++] = startNode;

    // Loop until the queue is empty
    while (head < tail)
    {
        // Dequeue the next node
        int node = queue[head++];

        // Print the node
        printf("%d ", node);

        // Enqueue all the unvisited neighbors of the node
        for (int i = 0; i < numNodes; i++)
        {
            if (graph[node][i] && !visited[i])
            {
                visited[i] = true;
                queue[tail++] = i;
            }
        }
    }
}

int main(void)
{
    // Initialize the adjacency matrix and the number of nodes
    // in the graph (assuming the graph is not necessarily connected)
    // For example:
    numNodes = 5;
    graph[0][1] = 1;
    graph[0][4] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;
    graph[2][3] = 1;
    graph[3][4] = 1;

    // Perform a BFS starting at node 0
    BFS(1);

    return 0;
}
