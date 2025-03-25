#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef char Elemtype;
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
void f(char *a)
{
}

int main()
{
    char a[51];
    while (gets(a))
    {
    }
    return 0;
}