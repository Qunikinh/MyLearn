#include <stdio.h>
#include <stdlib.h>
struct Elem
{
    int x, y, d;
};
typedef struct F
{
    struct Elem elem[200]; //! 要使用结构体，正常数组放不下
    int size;
} F;
F *Read()
{
    F *H = (F *)malloc(sizeof(F));
    scanf("%d", &H->size);
    int i;
    for (i = 0; i < H->size; i++)
    {
        scanf("%d %d %d",
              &H->elem[i].x,
              &H->elem[i].y,
              &H->elem[i].d);
    }
    return H;
}
F *Sum(F *N, F *M)
{
    int i, j, k = 0;
    F *H = (F *)malloc(sizeof(F));
    H->size = 0;
    for (i = 0, j = 0; i < N->size && j < M->size;)
    {
        if (N->elem[i].x < M->elem[j].x)
        {
            H->elem[k++] = N->elem[i++];
            H->size++;
        }
        else if (N->elem[i].x > M->elem[j].x)
        {
            H->elem[k++] = M->elem[j++];
            H->size++;
        }
        else
        {
            if (N->elem[i].y < M->elem[j].y)
            {
                H->elem[k++] = N->elem[i++];
                H->size++;
            }
            else if (N->elem[i].y > M->elem[j].y)
            {
                H->elem[k++] = M->elem[j++];
                H->size++;
            }
            else
            {
                H->elem[k] = N->elem[i++];
                H->elem[k++].d += M->elem[j++].d;
                H->size++;
            }
        }
    }
    //! 忘记处理剩余元素
    if (i == N->size)
    {
        for (j; j < M->size; j++)
        {
            H->elem[k++] = M->elem[j];
            //    H->elem[k++] = M->elem[j++];//!多余的增加
            H->size++;
        }
    }
    else
    {
        for (i; i < N->size; i++)
        {
            H->elem[k++] = N->elem[i];
            H->size++;
        }
    }
    return H;
}
void Print(F *H)
{
    int i;
    for (i = 0; i < H->size; i++)
    {
        printf("%d %d %d\n",
               H->elem[i].x,
               H->elem[i].y,
               H->elem[i].d);
    }
}
int main()
{
    F *N = Read();
    F *M = Read();
    F *H = Sum(N, M);
    free(N);
    free(M);
    Print(H);
    free(H); //! 忘记释放
    return 0;
}
