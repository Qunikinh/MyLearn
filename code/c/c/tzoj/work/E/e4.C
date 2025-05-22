#include <stdio.h>
#include <stdlib.h>

typedef struct Bitnode
{
    int data;
    struct Bitnode *right, *left;
} Bitnode;

Bitnode *CreatBitree_level()
{
    int data;
    int front = 1, rear = 0;
    Bitnode *p;
    Bitnode *root;
    Bitnode *q[1001];
    while (scanf("%d", &data), data != -1)
    {
        if (data == 0)
        {
            p = NULL;
        }
        else
        {
            p = (Bitnode *)malloc(sizeof(Bitnode));
            p->data = data;
            p->left = NULL;
            p->right = NULL;
        }
        q[++rear] = p;
        if (rear == 1)
        {
            root = p;
        }
        else
        {
            if (q[front] != NULL)
            {
                if (rear % 2 == 0)
                {
                    q[front]->left = p;
                }
                else
                {
                    q[front]->right = p;
                }
            }
            if (rear % 2 == 1)
            {
                front++;
            }
        }
    }
    return root;
}
void postorder(Bitnode *t)
{
    if (t == NULL)
        return;
    postorder(t->left);
    postorder(t->right);
    printf(" %d", t->data);
    free(t);
}

void preorder(Bitnode *t)
{
    if (t == NULL)
        return;
    printf(" %d", t->data);
    preorder(t->left);
    preorder(t->right);
    free(t);
}