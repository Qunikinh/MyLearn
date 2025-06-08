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

void insertNode(ArcNode **head, int vertex)
{
    ArcNode *e = (ArcNode *)malloc(sizeof(ArcNode));
    e->vertex = vertex;
    e->next = NULL;

    if (*head == NULL || vertex < (*head)->vertex)
    {
        e->next = *head;
        *head = e;
        return;
    }

    ArcNode *p = *head;
    while (p->next != NULL && p->next->vertex < vertex)
    {
        p = p->next;
    }
    e->next = p->next;
    p->next = e;
}

void CreateGraph(Graph &g, int nNum, int eNum)
{
    g.vNum = nNum;
    g.eNum = eNum;
    for (int i = 1; i <= g.vNum; i++)
    {
        g.head[i] = NULL;
    }

    for (int i = 0; i < g.eNum; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        insertNode(&g.head[x], y); //! 添加双向边
        insertNode(&g.head[y], x);
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
        {
            DFS(g, p->vertex);
        }
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
                visited[p->vertex] = 1;
                q[back++] = p->vertex;
            }
            p = p->next;
        }
    }
}

void ClearVisited(int n)
{
    for (int i = 0; i <= n; i++)
    {
        visited[i] = 0;
    }
}

void Destroy(Graph &g)
{
    for (int i = 1; i <= g.vNum; i++)
    {
        ArcNode *p = g.head[i];
        while (p)
        {
            ArcNode *tmp = p;
            p = p->next;
            free(tmp);
        }
        g.head[i] = NULL; //! 重要：释放后置空
    }
}

int main()
{
    int n, e;
    while (scanf("%d %d", &n, &e) != EOF)
    {
        Graph g;
        CreateGraph(g, n, e);
        DFS(g, 1);
        printf("\n");
        ClearVisited(n);
        BFS(g);
        printf("\n");
        ClearVisited(n);
        Destroy(g);
    }
    return 0;
}