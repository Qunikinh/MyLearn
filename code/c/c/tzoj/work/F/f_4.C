#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 31;
typedef struct ArcNode
{
    int vertex;
    int length;
    struct ArcNode *next;
} ArcNode;
typedef struct Graph
{
    ArcNode *head[MAX];
    int vNum = 0;
    int eNum = 0;
} Graph;

void CreateGraph(Graph &g, int n)
{
    int i;
    g.vNum = n;
    for (i = 1; i <= n; i++)
    {
        g.head[i] == NULL;
    }

    int a, b, t;
    while (scanf("%d %d %d", &a, &b, &t))
    {
        if (a == 0 && b == 0 && t == 0)
        {
            return;
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

void Search(Graph &g, int k);

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
    int n, e, k;
    while (scanf("%d", &n), n != 0)
    {
        Graph g;
        CreateGraph(g, n);
        scanf("%d", &k);
        Search(g, k);
        Destroy(g);
    }
}