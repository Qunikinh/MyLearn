#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct QNode
{
    int data;
    struct QNode *next;
} QNode;

typedef struct
{
    QNode *front;
    QNode *tail;
} LinkQueue;

void InitQueue(LinkQueue &q)
{
    q.front = (QNode *)malloc(sizeof(QNode));
    q.front->next = NULL;
    q.tail = q.front;
}

void EnQueue(LinkQueue &q, int x)
{
    QNode *newNode = (QNode *)malloc(sizeof(QNode));
    newNode->data = x;
    newNode->next = NULL;
    q.tail->next = newNode;
    q.tail = newNode;
}

int DeQueue(LinkQueue &q)
{
    QNode *temp = q.front->next;
    int res = temp->data;
    q.front->next = temp->next;
    if (q.tail == temp)
    {
        q.tail = q.front;
    }
    free(temp);
    return res;
}

int Front(LinkQueue &q)
{
    return q.front->next->data;
}

int Back(LinkQueue &q)
{
    return q.tail->data;
}

bool Empty(LinkQueue &q)
{
    return q.front == q.tail;
}

void Destroy(LinkQueue &q)
{
    QNode *p = q.front, *t;
    while (p)
    {
        t = p;
        p = p->next;
        free(t);
    }
}

int main()
{
    LinkQueue q;
    InitQueue(q);
    char cmd[10];
    int x, res;
    while (scanf("%s", cmd) != EOF)
    {
        if (strcmp(cmd, "enq") == 0)
        {
            scanf("%d", &x);
            EnQueue(q, x);
        }
        else if (strcmp(cmd, "front") == 0)
        {
            if (Empty(q))
                printf("EMPTY\n");
            else
                printf("%d\n", Front(q));
        }
        else if (strcmp(cmd, "back") == 0)
        {
            if (Empty(q))
                printf("EMPTY\n");
            else
                printf("%d\n", Back(q));
        }
        else
        {
            if (Empty(q))
                printf("EMPTY\n");
            else
                printf("%d\n", DeQueue(q));
        }
    }
    Destroy(q);
    return 0;
}