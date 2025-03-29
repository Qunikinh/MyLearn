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
void Readout(SqQueue *s, int n)
{
    int x, i;
    int a = 0, b = 2;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x % 2)
        {
            if (a % 3 == 2)
            {
                a++;
            }
            s->data[a++] = x;
            // printf("输入%d", a);
        }
        else
        {
            s->data[b] = x;
            // printf("输入%d", b + 1);
            b += 3;
        }
    }
    while (1)
    {
        if (s->front > a && s->front > b)
        {
            break;
        }

        {
            if (s->front < a && s->front < b)
            {
                if (i)
                {
                    printf(" %d", s->data[s->front++]);
                }
                else
                {
                    printf("%d", s->data[s->front++]);
                }
            }
            if (s->front > a)
            {
                while (s->front < b)
                {
                    printf(" %d", s->data[s->front]);
                    s->front += 3;
                }
            }
            if (s->front > b)
            {
                while (s->front < a)
                {
                    {
                        if (s->front % 3 == 2)
                            s->front++;
                    }
                    printf(" %d", s->data[s->front++]);
                }
            }
        }
    }
}
void Destroy(SqQueue *s)
{
    free(s->data);
}
int main()
{
    int n;
    scanf("%d", &n);
    SqQueue s;
    Init(&s);
    Readout(&s, n);
    Destroy(&s);
}