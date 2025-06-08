
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 100;
#define INF 1000000

typedef struct Graph
{
    int data[MAX][MAX];
    int vNum, eNum;
} Graph;

void CreateGraph(Graph &g, int n)
{
    int i, j;
    g.vNum = n;
    int edges = n * (n - 1) / 2;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            g.data[i][j] = (i == j) ? 0 : INF;
        }
    }
    int a, b, t;
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d %d", &a, &b, &t);
        g.data[a][b] = t;
        g.data[b][a] = t;
    }
}

void Prim(Graph g)
{
    int n = g.vNum;
    int dist[MAX];
    int visited[MAX] = {0};
    int totalWeight = 0;

    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }

    dist[1] = 0;

    for (int i = 0; i < n; i++)
    {
        int u = -1;
        int minDist = INF;
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] && dist[j] < minDist)
            {
                minDist = dist[j];
                u = j;
            }
        }
        if (u == -1)
            break;
        visited[u] = 1;
        totalWeight += dist[u];
        for (int v = 1; v <= n; v++)
        {
            if (!visited[v] && g.data[u][v] < dist[v])
            {
                dist[v] = g.data[u][v];
            }
        }
    }
    printf("%d\n", totalWeight);
}

int main()
{
    int n;
    while (scanf("%d", &n), n != 0)
    {
        Graph g;
        CreateGraph(g, n);
        Prim(g);
    }
    return 0;
}