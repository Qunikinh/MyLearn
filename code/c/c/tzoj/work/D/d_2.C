#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Elem
{
    int row, col, data;
};

typedef struct TSMatrix
{
    struct Elem elem[21];
    int rn;
    int cn;
    int tn;
} TSMatrix;

TSMatrix *creat(int m, int n, int t)
{
    TSMatrix *A = (TSMatrix *)malloc(sizeof(TSMatrix));
    A->rn = m;
    A->cn = n;
    A->tn = t;
    int i, r, c, x;
    for (i = 1; i <= t; i++)
    {
        scanf("%d%d%d", &r, &c, &x);
        A->elem[i].row = r;
        A->elem[i].col = c;
        A->elem[i].data = x;
    }
    return A;
}
void TransposeMatrix(TSMatrix *a, TSMatrix *b)
{
    int i, j;
    for (i = 1; i <= a->tn; i++) // 行列数据互换
    {
        b->elem[i].row = a->elem[i].col;
        b->elem[i].col = a->elem[i].row;
        b->elem[i].data = a->elem[i].data;
    }
    b->tn = a->tn;
    b->rn = a->cn;              // 维度互换
    b->cn = a->rn;              //...
    for (i = 1; i < b->tn; i++) // 排序
    {
        for (j = 1; j <= b->tn - i; j++)
        {
            if (b->elem[j].row > b->elem[j + 1].row ||
                b->elem[j].row == b->elem[j + 1].row && b->elem[j].col > b->elem[j + 1].col)
            {
                struct Elem t = b->elem[j];
                b->elem[j] = b->elem[j + 1];
                b->elem[j + 1] = t;
            }
        }
    }
}
// todo--------------------------------------------------------

void print(TSMatrix C)
{
    int i, j, n = 1;
    while (n <= C.tn)
        for (i = 1; i <= C.rn; i++)
        {
            for (j = 1; j <= C.cn; j++)
                if (C.elem[n].row == i && C.elem[n].col == j)
                {
                    printf("%4d", C.elem[n].data);
                    n++;
                }
                else
                    printf("%4d", 0);
            printf("\n");
        }
}
int main()
{
    int i, j, m, n, k, t;
    TSMatrix *A, B;
    while (scanf("%d%d%d", &m, &n, &t) && t != 0)
    {
        A = creat(m, n, t);
        TransposeMatrix(A, &B);
        print(B);
        free(A);
    }
    return 0;
}