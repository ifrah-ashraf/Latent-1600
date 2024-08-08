#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;

// Find vertex with the minimum key value
int findMinimumKey(int key[], bool mstSet[])
{
    int minKey = INT_MAX;
    int minIndex = -1;
    for (int v = 0; v < numVertices; v++)
    {
        if (!mstSet[v] && key[v] < minKey)
        {
            minKey = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Print the MST
void printMST(int parent[])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < numVertices; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Prim's algorithm to find MST
void primMST()
{
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];
    for (int i = 0; i < numVertices; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < numVertices - 1; count++)
    {
        int u = findMinimumKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < numVertices; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent);
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Minimum Spanning Tree:\n");
    primMST();
    return 0;
}


/* this is the adjacency matrix you will give for prims

int graph[4][4] = {
    {0, 10, 6, 5},
    {10, 0, 0, 15},
    {6, 0, 0, 4},
    {5, 15, 4, 0}
}; */