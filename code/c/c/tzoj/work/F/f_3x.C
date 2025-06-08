#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 31
typedef struct ArcNode
{
    int vertex;
    struct ArcNode *next;
} ArcNode;
typedef struct
{
    ArcNode *head[N];
    int vNum;
    int eNum;
} Graph;
int visited[N] = {0};

void CreateGraph(Graph &g, int nNum, int eNum)
{
    ArcNode *e;
    g.vNum = nNum;
    g.eNum = eNum;
    int i, j, x, y;
    for (i = 1; i <= g.vNum; i++)
    {
        g.head[i] = NULL;
    }
    for (i = 0; i < g.eNum; i++)
    {
        scanf("%d%d", &x, &y);
        e = (ArcNode *)malloc(sizeof(ArcNode));
        e->next = NULL;
        e->vertex = y;
        if (g.head[x] == NULL)
        {
            g.head[x] = e;
        }
        else
        {
            ArcNode *p = g.head[x];
            if (y < p->vertex)
            {
                e->next = p;
                g.head[x] = e;
            }
            else
            {
                ArcNode *q = p;
                p = p->next;
                while (p != NULL)
                {
                    if (y < p->vertex)
                        break;
                    q = p;
                    p = p->next;
                }
                e->next = p;
                q->next = e;
            }
        }
    }
}

void DFS(Graph &g, int i)
{
    visited[i] = 1;
    printf("%d ", i);
    ArcNode *p = g.head[i];
    while (p)
    {
        if (!visited[p->vertex])
            DFS(g, p->vertex);
        p = p->next;
    }
}
void BFS(Graph &g)
{
    int q[N], front = 0, back = 0;
    q[back++] = 1;
    visited[1] = 1;
    while (front != back)
    {
        int cur = q[front++];
        printf("%d ", cur);
        ArcNode *p = g.head[cur];
        while (p)
        {
            if (!visited[p->vertex])
            {
                q[back++] = p->vertex;
                visited[p->vertex] = 1;
            }
            p = p->next;
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
void Destroy(Graph &g)
{
    int i;
    for (i = 1; i < g.eNum; i++)
    {
        if (g.head[i] == NULL)
        {
            continue;
        }
        else
        {
            ArcNode *q = g.head[i];
            ArcNode *p = q->next;
            free(q);
            while (p != NULL)
            {
                q = p;
                p = q->next;
                free(q);
            }
        }
    }
}
int main()
{
    int n, e;
    while (scanf("%d %d", &n, &e) != EOF)
    {
        Graph g;
        int v;
        CreateGraph(g, n, e);
        DFS(g, 1);
        printf("\n");
        ClearVisited(n);
        BFS(g);
        printf("\n");
        ClearVisited(n);
        Destroy(g);
    }
}