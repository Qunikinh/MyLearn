// 5695: 数据结构―逆波兰表达式

// 逆波兰表达式是一种把运算符后置的算术表达式，例如普通的表达式2+3的逆波兰表示法为2 3 +。逆波兰表达式的优点是运算符之间不必有优先级关系，也不用括号，
// 例如（2+3)*4的波兰表达式为2 3 + 4 *；本题求解逆波兰表达式的值，其中运算法只有* + - /.每个数据均为小于10的正整数。

// 输入
// 输入数据有多组，每组为一行逆波兰表达式，其中运算符和运算数之间用空格表示，不超过50个字符。

// 输出
// 每组在一行中输出逆波兰表达式的值，保留2位小数。

// 样例输入
// 2 3 +  4 *

// 样例输出
// 20.00

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef double Elemtype;
typedef struct SqStack
{
    Elemtype *base;
    int top;
    int size;
} SqStack;

void Push(SqStack *s, Elemtype x)
{
    s->base[++s->top] = x;
}

double Pop(SqStack *s)
{
    if (s->top == -1)
    {
        return 0;
    }
    return s->base[s->top--];
}

void Destory(SqStack *s)
{
    free(s->base);
    s->base = NULL;
    s->top = -1;
    s->size = 0;
}

int main()
{
    char a[51];
    int i = 0;
    double m, n, c;
    SqStack s;
    s.size = 100;
    s.base = (Elemtype *)malloc(sizeof(Elemtype) * s.size);
    while (gets(a))
    {
        i = -1;
        s.top = -1;
        while (a[++i] != '\0')
        {
            if (a[i] <= '9' && a[i] >= '0')
            {
                Push(&s, a[i] - '0');
                continue;
            }
            else if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/')
            {
                m = Pop(&s);
                n = Pop(&s);
                switch (a[i])
                {
                case '+':
                    c = n + m;
                    break;
                case '-':
                    c = n - m;
                    break;
                case '*':
                    c = n * m;
                    break;
                case '/':
                    if (m == 0)
                    {
                        printf("Error: Division by zero\n");
                        Destory(&s);
                        exit(1);
                    }
                    c = n / m;
                    break;
                }
                Push(&s, c);
            }
            else if (a[i] == ' ')
            {
                continue;
            }
        }
        m = Pop(&s);
        printf("%0.2f\n", m);
    }
    Destory(&s);
    return 0;
}