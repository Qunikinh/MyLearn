#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 21;

typedef struct Graph
{
    int data[MAX][MAX] = {0};
    int vNum = 0, eNum = 0;
} Graph;

void CreateGraph(Graph &g, int n, int e)
{
    g.eNum = e;
    g.vNum = n;
    int i;
    int a, b, t;
    for (i = 0; i < e; i++)
    {
        scanf("%d %d %d", &a, &b, &t);
        g.data[a][b] = t;
        g.data[b][a] = t;
    }
}
Graph GenTree(Graph &g);
void Print(Graph t)
{
}
int main()
{
    int n, e;
    while (scanf("%d %d", &n, &e) != EOF)
    {
        Graph g;
        CreateGraph(g, n, e);
        Graph t = GenTree(g);
        Print(t);
    }
}