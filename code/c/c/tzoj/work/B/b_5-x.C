#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    char *base;
    int top;
    int size;
} Stack;

void initStack(Stack *s, int size)
{
    s->base = (char *)malloc(sizeof(char) * size);
    s->top = -1;
    s->size = size;
}

void push(Stack *s, char c)
{
    if (s->top < s->size - 1)
    {
        s->base[++s->top] = c;
    }
}

char pop(Stack *s)
{
    if (s->top == -1)
    {
        return '\0';
    }
    return s->base[s->top--];
}

char top(Stack *s)
{
    if (s->top == -1)
    {
        return '\0';
    }
    return s->base[s->top];
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int get_priority(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

int main()
{
    char expr[21];
    while (scanf("%20s", expr) == 1)
    {
        Stack s;
        initStack(&s, 20);
        char buffer[200] = {0};
        int pos = 0;

        for (int i = 0; expr[i] != '\0'; i++)
        {
            char ch = expr[i];
            if (isdigit(ch))
            {
                if (pos > 0)
                {
                    buffer[pos++] = ' ';
                }
                buffer[pos++] = ch;
            }
            else if (ch == '(')
            {
                push(&s, ch);
            }
            else if (ch == ')')
            {
                while (!isEmpty(&s) && top(&s) != '(')
                {
                    char op = pop(&s);
                    if (pos > 0)
                    {
                        buffer[pos++] = ' ';
                    }
                    buffer[pos++] = op;
                }
                pop(&s);
            }
            else
            {
                while (!isEmpty(&s) && top(&s) != '(' && get_priority(top(&s)) >= get_priority(ch))
                {
                    char op = pop(&s);
                    if (pos > 0)
                    {
                        buffer[pos++] = ' ';
                    }
                    buffer[pos++] = op;
                }
                push(&s, ch);
            }
        }

        while (!isEmpty(&s))
        {
            char op = pop(&s);
            if (pos > 0)
            {
                buffer[pos++] = ' ';
            }
            buffer[pos++] = op;
        }

        printf("%s\n", buffer);
        free(s.base);
    }
    return 0;
}