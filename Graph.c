#include <stdio.h>
#include <stdlib.h>

int **createGraph(int n)
{
    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }
    return graph;
}

void addEdge(int **graph, int u, int v)
{
    graph[u][v] = 1;
}

void printGraph(int **graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n = 5;
    int **graph = createGraph(n);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 1);
    addEdge(graph, 2, 4);
    addEdge(graph, 4, 3);
    printGraph(graph, n);
    return 0;
}