// 数据结构实验：压缩对称矩阵
// 给定一个对称矩阵，我们可以将下三角阵（或上三角阵）存储于一维数组中，实现数据压缩（内存空间减半）
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Zip(int a[100][100], int n, int *b);
int Index(int i, int j);

int main()
{
    int n, i, j, a[100][100];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }
    int *b = (int *)malloc(sizeof(int) * n * (n + 1) / 2);
    Zip(a, n, b);
    while (scanf("%d%d", &i, &j) != EOF)
    {
        printf("%d\n", b[Index(i, j)]);
    }
    free(b);
    return 0;
}
// todo------------------------------------------------
void Zip(int a[100][100], int n, int *b)
{
    int i, j, k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            b[k++] = a[i][j];
        }
    }
}
int Index(int i, int j)
{
    int k, a = 0;
    if (i < j)
    {
        k = i;
        i = j;
        j = k;
    }
    for (k = 0; k < i; k++)
    {
        a += k;
    }
    a += j - 1;
    return a;
}
