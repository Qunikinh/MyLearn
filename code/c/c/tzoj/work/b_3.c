#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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