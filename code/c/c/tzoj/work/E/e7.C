#include <stdlib.h>
#include <stdio.h>
#include <math.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *Create()
{
    int data, front = 1, rear = 0;
    struct TreeNode *t, *root, *q[1001]; // 队列
    while (scanf("%d", &data), data != -1)
    {
        if (data == 0)
            t = NULL;
        else
        {
            t = (struct TreeNode *)malloc(sizeof(struct TreeNode)); // 创建结点
            t->val = data;
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

struct TreeNode *mergeTrees(struct TreeNode *t1, struct TreeNode *t2)
{
    if (t1 == NULL && t2 == NULL)
    {
        return NULL;
    }
    struct TreeNode *m = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *b = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    b->val = 0;
    b->left = NULL;
    b->right = NULL;
    if (t1 == NULL)
    {
        t1 = b;
    }
    else if (t2 == NULL)
    {
        t2 = b;
    }
    m->val = t1->val + t2->val;
    m->left = mergeTrees(t1->left, t2->left);
    m->right = mergeTrees(t1->right, t2->right);
    free(t1);
    free(t2);
    return m;
}
void InOrder(struct TreeNode *p)
{
    if (p == NULL)
        return;
    InOrder(p->left);
    printf(" %d", p->val);
    InOrder(p->right);
}
void InOrderm(struct TreeNode *p)
{
    if (p == NULL)
        return;
    InOrder(p->left);
    printf(" %d", p->val);
    InOrder(p->right);
    free(p);
}
int main()
{
    struct TreeNode *t1 = Create();
    InOrder(t1);
    printf("\n");
    struct TreeNode *t2 = Create();
    InOrder(t2);
    printf("\n");
    struct TreeNode *m = mergeTrees(t1, t2);
    InOrderm(m);
}