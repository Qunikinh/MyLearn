#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 21;
#define INF 1000000

typedef struct Graph
{
    int data[MAX][MAX];
    int vNum, eNum;
} Graph;

void CreateGraph(Graph *g, int n, int e)
{
    g->eNum = e;
    g->vNum = n;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            g->data[i][j] = 0;
        }
    }
    int a, b, t_val;
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d %d", &a, &b, &t_val);
        g->data[a][b] = t_val;
        g->data[b][a] = t_val;
    }
}

Graph GenTree(Graph *g)
{
    int n = g->vNum;
    int dist[MAX];
    int parent[MAX];
    int visited[MAX] = {0};
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[1] = 0;
    visited[1] = 1;
    for (int v = 1; v <= n; v++)
    {
        if (g->data[1][v] != 0)
        {
            dist[v] = g->data[1][v];
            parent[v] = 1;
        }
    }
    int edgeList[MAX][3];
    int edgeCount = 0;
    for (int count = 1; count < n; count++)
    {
        int u = -1;
        int minDist = INF;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                if (dist[i] < minDist || (dist[i] == minDist && i < u))
                {
                    minDist = dist[i];
                    u = i;
                }
            }
        }
        if (u == -1)
            break;
        visited[u] = 1;
        edgeList[edgeCount][0] = parent[u];
        edgeList[edgeCount][1] = u;
        edgeList[edgeCount][2] = dist[u];
        edgeCount++;
        for (int v = 1; v <= n; v++)
        {
            if (!visited[v] && g->data[u][v] != 0)
            {
                if (g->data[u][v] < dist[v])
                {
                    dist[v] = g->data[u][v];
                    parent[v] = u;
                }
            }
        }
    }
    Graph t;
    t.vNum = edgeCount;
    t.eNum = edgeCount;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            t.data[i][j] = 0;
        }
    }
    for (int i = 0; i < edgeCount; i++)
    {
        t.data[i][0] = edgeList[i][0];
        t.data[i][1] = edgeList[i][1];
        t.data[i][2] = edgeList[i][2];
    }

    return t;
}

void Print(Graph t)
{
    for (int i = 0; i < t.vNum; i++)
    {
        printf("%d %d %d\n", t.data[i][0], t.data[i][1], t.data[i][2]);
    }
}

int main()
{
    int n, e;
    while (scanf("%d %d", &n, &e) != EOF)
    {
        Graph g;
        CreateGraph(&g, n, e);
        Graph t = GenTree(&g);
        Print(t);
    }
    return 0;
}