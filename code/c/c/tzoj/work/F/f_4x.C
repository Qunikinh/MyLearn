#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 31;
const int INF = 0x3f3f3f3f;

typedef struct ArcNode
{
    int vertex;
    int length;
    struct ArcNode *next;
} ArcNode;

typedef struct Graph
{
    ArcNode *head[MAX];
    int vNum;
    int eNum;
} Graph;

void CreateGraph(Graph &g, int n)
{
    g.vNum = n;
    g.eNum = 0;
    for (int i = 0; i < n; i++)
    {
        g.head[i] = NULL;
    }

    int a, b, t;
    while (1)
    {
        scanf("%d %d %d", &a, &b, &t);
        if (a == 0 && b == 0 && t == 0)
        {
            break;
        }
        g.eNum++;
        ArcNode *e = (ArcNode *)malloc(sizeof(ArcNode));
        e->vertex = b;
        e->length = t;
        e->next = NULL;
        if (g.head[a] == NULL)
        {
            g.head[a] = e;
        }
        else
        {
            ArcNode *q = g.head[a];
            if (b < q->vertex)
            {
                e->next = q;
                g.head[a] = e;
            }
            else
            {
                ArcNode *p = q->next;
                while (p != NULL)
                {
                    if (b < p->vertex)
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

void Search(Graph &g, int k)
{
    int dist[MAX];
    int visited[MAX];
    int n = g.vNum;
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1;
        int minDist = INF;
        for (int j = 0; j < n; j++)
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
        ArcNode *p = g.head[u];
        while (p != NULL)
        {
            int v = p->vertex;
            int w = p->length;
            if (!visited[v] && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
            p = p->next;
        }
    }
    if (dist[k] == INF)
    {
        printf("NO WAY!\n");
    }
    else
    {
        printf("%d\n", dist[k]);
    }
}

void Destroy(Graph &g)
{
    for (int i = 0; i < g.vNum; i++)
    {
        ArcNode *p = g.head[i];
        while (p != NULL)
        {
            ArcNode *temp = p;
            p = p->next;
            free(temp);
        }
    }
}

int main()
{
    int n, k;
    while (scanf("%d", &n), n != 0)
    {
        Graph g;
        CreateGraph(g, n);
        scanf("%d", &k);
        Search(g, k);
        Destroy(g);
    }
    return 0;
}