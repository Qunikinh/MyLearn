#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 31;
typedef struct Graph
{
    int data[MAX][MAX] = {0};
    int vNum, eNum;
} Graph;
int visited[MAX] = {0};

Graph CreateGraph(int n, int e)
{
    int i;
    int a, b;
    Graph g;
    g.vNum = n;
    for (i = 0; i < e; i++)
    {
        scanf("%d %d", &a, &b);
        g.data[a][b] = 1;
        g.data[b][a] = 1;
        g.eNum++;
    }
    return g;
}

void DFS(Graph &g, int v)
{
    visited[v] = 1;
    printf("%d ", v);
    int i = 1;
    for (i = 1; i <= g.vNum; i++)
    {
        if (visited[i] == 0 && g.data[v][i] == 1)
        {
            DFS(g, i);
        }
    }
}
void BFS(Graph &g)
{
    int q[MAX], front = 0, back = 0;
    q[back++] = 1;
    visited[1] = 1;
    while (front != back)
    {
        int cur = q[front++];
        printf("%d ", cur);
        int i;
        for (i = 1; i <= g.vNum; i++)
        {
            if (visited[i] == 0 && g.data[cur][i])
            {
                q[back++] = i;
                visited[i] = 1;
            }
        }
    }
}
void ClearVisited(int n)
{
    int i;
    for (i = 0; i <= n; i++)
    {
        visited[i] = 0;
    }
}

int main()
{
    int n, e;
    while (scanf("%d %d", &n, &e) != EOF)
    {
        Graph g;
        int v;
        g = CreateGraph(n, e);
        DFS(g, 1);
        printf("\n");
        ClearVisited(n);
        BFS(g);
        printf("\n");
        ClearVisited(n);
    }
}