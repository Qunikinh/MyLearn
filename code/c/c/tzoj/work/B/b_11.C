// 数据结构实验：链式队列
// 创建一个链式队列，能够完成队列的初始化、入队、出队、获取队首和队尾元素、销毁队列等操作。
// 部分代码已经给出，请补充完整，提交时请勿包含已经给出的代码。

// 输入
// 输入数据由以下几种命令组成：
// （1）enq x：将x入队
// （2）deq：出队
// （3）front：获取队首元素
// （4）back：获取队尾元素
// 每个命令占一行，以EOF结束。
// 总的命令个数不会超过500。
// 输出
// 当执行deq时输出出队的元素，当执行front时输出队首元素，当执行back时输出队尾元素，当队为空时，需要输出EMPTY。

// 样例输入
// enq 1
// enq 2
// front
// deq
// enq 3
// front
// back
// 样例输出
// 1
// 1
// 2
// 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int Elemtype;
typedef struct Node
{
    Elemtype data;
    struct Node *next;
} QNode;
typedef struct LinkQueue
{
    QNode *front;
    QNode *tail;
} LinkQueue;

void EnQueue(LinkQueue &q, int x)
{
    QNode *p = (QNode *)malloc(sizeof(QNode));
    p->data = x;
    p->next = NULL;
    q.tail->next = p;
    q.tail = p;
}
int Front(LinkQueue q)
{
    return q.front->next->data;
}
int Back(LinkQueue q)
{
    return q.tail->data;
}
int Empty(LinkQueue q)
{
    return q.front == q.tail;
}
int DeQueue(LinkQueue &q) //! 注意使用&使用实参，不加修改的是副本
{
    QNode *p = q.front;
    int x = p->next->data;
    q.front = q.front->next;
    free(p);
    return x;
}

// todo---------------------------------
void InitQueue(LinkQueue &q)
{
    q.front = (QNode *)malloc(sizeof(QNode));
    q.front->next = NULL;
    q.tail = q.front;
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