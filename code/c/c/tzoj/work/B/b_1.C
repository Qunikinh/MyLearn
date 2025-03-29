
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int Elemtype;
typedef struct
{
	Elemtype *base;
	int top;
	int size;
} SqStack;

void InitStack(SqStack *s)
{
	s->size = 500;
	s->base = (Elemtype *)malloc(sizeof(Elemtype) * s->size);
	s->top = -1;
}

void Push(SqStack *s, Elemtype x)
{
	if (s->top == s->size - 1)
	{
		return;
	}
	s->base[++s->top] = x; // 列表形式
}

int Pop(SqStack *s)
{
	int a;
	if (s->top == -1)
	{
		return 0; // 栈空
	}
	a = s->base[s->top--]; // 出栈
	return a;
}

int GetTop(SqStack s, Elemtype *px)
{
	if (s.top == -1)
	{
		return 0; // 栈空
	}
	*px = s.base[s.top];
	return 1;
}

void Destroy(SqStack *s)
{
	free(s->base);
}

int main()
{
	SqStack s;
	InitStack(&s);
	char c;
	int x, res;
	while (scanf("%c", &c) != EOF)
	{
		if (c <= '9' && c >= '0')
		{
			scanf("%d", &x);
			Push(&s, x);
		}
		else
		{
			int w;
			int a, b;
			b = Pop(&s);
			a = Pop(&s);
			switch (c)
			{
			case '+':
				w = a + b;
				break;
			case '-':
				w = a - b;
				break;
			case '*':
				w = a * b;
				break;
			case '/':
				w = a / b;
			default:
				break;
			}
			printf("%c", w);
			Push(&s, w);
		}
	}
	Destroy(&s);
	return 0;
}