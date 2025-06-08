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
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            g.data[i][j] = 0;
        }
    }
    int a, b, t;
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &a, &b, &t);
        g.data[a][b] = t;
        g.data[b][a] = t;
    }
}
void Prim(Graph g)
{
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
}