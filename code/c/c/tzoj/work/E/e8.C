#include <stdlib.h>
#include <stdio.h>
#include <math.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *CreateTree(int n)
{
    int data[100], i, j, tmp;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (data[j] > data[j + 1])
            {
                tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d", data[i]);
    }

    int front = 1, rear = 0;
    Node *t, *root, *q[1001]; // 队列
    while (rear < n)
    {

        if (data == 0)
            t = NULL;
        else
        {
            t = (Node *)malloc(sizeof(Node)); // 创建结点
            t->data = data[rear];
            t->left = NULL;
            t->right = NULL;
        }
        q[++rear] = t; // 入队列
        if (rear == 1) // 根结点
            root = t;
        else
        {
            if (q[front] != NULL)
            {
                if (rear % 2 == 0) // 左孩子
                    q[front]->left = t;
                else
                    q[front]->right = t;
            }
            if (rear % 2 == 1) // 两个孩子都处理完
                front++;
        }
    }
    return root;
}
void InOrder(Node *p)
{
    if (p == NULL)
        return;
    InOrder(p->left);
    printf(" %d", p->data);
    InOrder(p->right);
    free(p);
}
int main()
{
    int n;
    scanf("%d", &n);
    Node *t = CreateTree(n);
    InOrder(t);
}