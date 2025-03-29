#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int Elemtype;
typedef struct SqQueue
{
    Elemtype *data;
    int front;
    int rear;
    int size;
} SqQueue;

void InitQueue(SqQueue *q)
{
    q->size = 5;
    q->data = (Elemtype *)malloc(sizeof(Elemtype) * q->size);
    q->front = 0;
    q->rear = 0;
}
int QueueLength(SqQueue q)
{
    int l;
    l = (q.size + q.rear - q.front) % q.size;
    return l;
}
int EnQueue(SqQueue *q, int x)
{
    if (QueueLength(*q) == 4)
        return 0;
    q->data[q->rear++] = x;
    if (q->rear == q->size)
        q->rear = 0;
    // printf("已输入%d", q->rear);//!记得删除测试代码。。。
    return 1;
}

int DeQueue(SqQueue *q, int *x)
{
    if (q->front == q->rear)
        return 0;
    *x = q->data[q->front++];
    if (q->front == q->size)
    {
        q->front = 0;
    }
    return 1;
}

int main()
{
    SqQueue q;
    char ss[10];
    int x, sta, l;
    InitQueue(&q);
    while (scanf("%s", ss) != EOF)
    {
        if (strcmp(ss, "enter") == 0)
        {
            scanf("%d", &x);
            sta = EnQueue(&q, x);
            if (sta == 0)
                printf("FULL\n");
        }
        else if (strcmp(ss, "length") == 0)
        {
            l = QueueLength(q);
            printf("%d\n", l);
        }
        else
        {
            sta = DeQueue(&q, &x);
            if (sta == 0)
                printf("EMPTY\n");
            else
                printf("%d\n", x);
        }
    }
    return 0;
}