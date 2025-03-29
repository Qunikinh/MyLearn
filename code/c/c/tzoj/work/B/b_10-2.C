// 银行业务队列简单模拟
// 设某银行有A、B两个业务窗口，且处理业务的速度不一样，其中A窗口处理速度是B窗口的2倍 —— 即当A窗口每处理完2个顾客时，B窗口处理完1个顾客。给定到达银行的顾客序列，请按业务完成的顺序输出顾客序列。假定不考虑顾客先后到达的时间间隔，并且当不同窗口同时处理完2个顾客时，A窗口顾客优先输出。

// 输入
// 输入为一行正整数，其中第1个数字N(N≤1000)为顾客总数，后面跟着N位顾客的编号。编号为奇数的顾客需要到A窗口办理业务，为偶数的顾客则去B窗口。数字间以空格分隔。
// 输出
// 按业务处理完成的顺序输出顾客的编号。数字间以空格分隔，但最后一个编号后不能有多余的空格。

// 样例输入
// 8 2 1 3 9 4 11 13 15
// 样例输出
// 1 3 2 9 11 4 13 15

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

void Init(SqQueue *s)
{
    s->size = 1000;
    s->data = (Elemtype *)malloc(sizeof(Elemtype) * s->size);
    s->front = 0;
    s->rear = 0;
}
void Destroy(SqQueue *s)
{
    free(s->data);
}
int main()
{
    SqQueue a, b;
    Init(&a);
    Init(&b);
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x % 2)
        {
            a.data[a.rear++] = x;
        }
        else
        {
            b.data[b.rear++] = x;
        }
    }
    for (i = 0;;)
    {
        if (a.front == a.rear)
        {
            while (1)
            {
                if (i)
                {
                    printf(" %d", b.data[b.front++]);
                }
                else
                {
                    printf("%d", b.data[b.front++]);
                    i++;
                }
                if (b.front == b.rear)
                {
                    return 0;
                }
            }
        }
        if (b.front == b.rear)
        {
            while (1)
            {
                if (i)
                {
                    printf(" %d", a.data[a.front++]);
                }
                else
                {
                    printf("%d", a.data[a.front++]);
                    i++;
                }
                if (a.front == a.rear)
                {
                    return 0;
                }
            }
        }
        if (i)
        {
            printf(" %d", a.data[a.front++]);
        }
        else
        {
            printf("%d", a.data[a.front++]);
            i++;
        }
        if (a.front == a.rear)
        {
            continue;
        }
        printf(" %d", a.data[a.front++]);

        if (i)
        {
            printf(" %d", b.data[b.front++]);
        }
        else
        {
            printf("%d", b.data[b.front++]);
            i++;
        }
    }
    Destroy(&a);
    Destroy(&b);
}